#include "1_Funtionality.h"

// Homework : done only by using first two parameters...
void Square(DataContainer &data, ResultContainer &result, int start, int end)
{
    if (data.empty())
    {
        throw std::runtime_error("Data empty exception ");
    }

    for (int i = start; i < end; i++)
    {
        result[i] = data[i] * data[i];
    }
    std::cout << std::endl;
}

void Cube(DataContainer &data, ResultContainer &result, int start, int end)
{
    if (data.empty())
    {
        throw std::runtime_error("Data empty exception ");
    }

    for (int i = start; i < end; i++)
    {
        // result[i] = data[i] * data[i] * data[i];
        result[5+i] = data[i] * data[i] * data[i];          // USED WHEN INPUT IS TAKEN BY THE USER OF SIZE 5

    }
    std::cout << std::endl;
}

void factorial(DataContainer &data, ResultContainer &result, int start, int end)
{
    if (data.empty())
    {
        throw std::runtime_error("Data empty exception ");
    }

    for (int i = start; i < end; i++)
    {
        if (data[i] < 0)
        {
            throw std::runtime_error("Data value is less than zero - fact not calculate ");
        }

        if (data[i] == 0 || data[i] == 1)
        {
            // result[i] = 1;
            result[10+i] = 1;                        // USED WHEN INPUT IS TAKEN BY THE USER OF SIZE 5
        }

        int number = data[i];
        int fact = 1;
        while (number)
        {
            fact *= number;
            number--;
        }

        // result[i] = fact;
        result[10+i] = fact;           // USED WHEN INPUT IS TAKEN BY THE USER OF SIZE 5
    }
    std::cout << std::endl;
}

void MapThreadToData(DataContainer &data, ThreadContainer &thArr, ResultContainer &result)
{
    if (data.empty() || thArr.empty())
    {
        throw std::runtime_error("Data or thread is empty - no mapping is to be done");
    }

    int index = 0;

    // for(std::thread& th: thArr){

    //     if(index >= 0 && index < 5){
    //         th = std::thread(&Square, std::ref(data), std::ref(result), index , index + 5);
    //         index = index + 5;
    //     }

    //     else if(index >= 5 && index < 10){
    //         th = std::thread(&Cube, std::ref(data), std::ref(result), index , index + 5);
    //         index = index + 5;
    //     }

    //     else{
    //         thArr[2] = std::thread(&factorial, std::ref(data), std::ref(result), index , index + 5);

    //     }
    // }

   
   // SECOND APPROACH FOR MAPPING : 

    thArr[0] = std::thread(&Square, std::ref(data), std::ref(result), index, index + 5);

    // index = index + 5;                        // USED WHEN INPUT IS TAKEN BY THE USER OF SIZE 5
    
    thArr[1] = std::thread(&Cube, std::ref(data), std::ref(result), index, index + 5);

    // index = index + 5;                       // USED WHEN INPUT IS TAKEN BY THE USER OF SIZE 5
    
    thArr[2] = std::thread(&factorial, std::ref(data), std::ref(result), index, index + 5);
    
}

void JoinThread(ThreadContainer &thArr)
{
    for (std::thread &th : thArr)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

void Display(ResultContainer &result)
{
    if (result.empty())
    {
        throw std::runtime_error("Result conatiner is empty");
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}

void TakeInput(DataContainer &data)
{

    int val{-1};
    int count = 0;

    std::cout << "Enter values : \n";
    while (count != 5)
    {                                                // Only for one thread
        std::cin >> val;
        if (val < 0 || val > 10)
        {
            continue;
        }

        data[count++] = val;
    }
}
