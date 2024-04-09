#include "DataOperation.h"

DataOperation *DataOperation::_instance{nullptr};

DataOperation *DataOperation::GetInstance()
{
    if (!_instance)
    {
        _instance = new DataOperation();
    }
    
    return _instance;
}


void DataOperation::factorial(std::future<int> &number)
{
    _answer = (int *)malloc(4);

    int n = number.get(); // WAIT TILL INPUT ARRIVES

    int final_result{1};
    for (int i = 2; i <= n; i++)
    {
        final_result *= i;
    }

    *_answer = final_result;

    std::cout << "Factorial is : " << *_answer << std::endl;
}

void DataOperation::operator()()
{
    _ft = _pr.get_future();

    std::future<void> result = std::async(&DataOperation::factorial, this, std::ref(_ft));

    int value{0};
    std::cin >> value;
    // value has to be sent to another dummy variable !!

    _pr.set_value(value);

    // We can wait for factorial to finish ( wait !! )
    result.wait();
}
