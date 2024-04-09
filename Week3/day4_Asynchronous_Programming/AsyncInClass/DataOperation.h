#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include<iostream>
#include<future>

class DataOperation
{
private:
    int _number{-1};
    std::promise<int> _pr;
    std::future<int>_ft;
    int* _answer{nullptr};


    DataOperation() = default;
    DataOperation(const DataOperation &) = delete;
    DataOperation(DataOperation &&) = delete;
    DataOperation &operator=(const DataOperation &) = delete;
    DataOperation &operator=(DataOperation &&) = delete;
 
    static DataOperation* _instance;

public:
    
    ~DataOperation() = default;

    static DataOperation* GetInstance();

    void factorial(std::future<int>&number);

    void operator()();


};


#endif // DATAOPERATION_H
