
#include"DataOperation.h"

DataOperation* DataOperation:: only_object {nullptr};

DataOperation *DataOperation::getInstance(int val)
{
    if(only_object){
        return only_object;
    }
    else{
        only_object = new DataOperation(val);
        return only_object;
    }
}

void DataOperation::ProducerInput()
{
    std::cout << "Enter the value : " ;
    std::cin >> m_value;

    //trigger a signal after cin is done, to indicate that consumer can proceed with square calculation...

    m_flag = true;
    m_cv.notify_one();
}

void DataOperation::CustomerOperation()
{
    int *m_result_value = (int*)malloc(4);

    std::unique_lock<std::mutex> ul(m_mt);
    m_cv.wait( ul, [&](){return m_flag ; });   


    /*
            cv.wait() ----> before ----> Not dependent in function....

            cv.wait() ----> after -----> Dependent in Producer Input
    */

    *m_result_value = m_value * m_value;

    std::cout << "Square calculation : " << *m_result_value << std::endl;
}
