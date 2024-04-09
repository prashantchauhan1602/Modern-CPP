#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include<mutex>
#include<iostream>
#include<thread>
#include<condition_variable>



/*

    Singleton Class : 

        1) Make the constructor private...

        2) If constructor is private, how would be make the first object ?

            Make a seperate member function that access constructor from inside class
                and completes this task !!

        3) My objective is first time we get new object, for all other subsequent times,
                we need to returns same object again and again...

                HOW DO I SAVE SOMETHING AS A COMMON VALUE FOR WHOLE CLASS ?
                    Static variable...

*/
class DataOperation
{
private:
    int m_value{-1};
    bool m_flag{false};
    int* value {nullptr};

    std::mutex m_mt;                      // Not duplicate ----> Copy constructor delete
    std::condition_variable m_cv;         // Above same condition...


    DataOperation() = delete;

    DataOperation(const DataOperation &) = delete;  // Enable when all data is copied...
    DataOperation(DataOperation &&) = delete;

    DataOperation &operator=(const DataOperation &) = delete;
    DataOperation &operator=(DataOperation &&) = delete;

    DataOperation(int value) : m_value{value} {}

    static DataOperation* only_object;
    

public: 

    ~DataOperation() = default;

    static DataOperation* getInstance(int val); 

    void ProducerInput();

    void CustomerOperation();    


};


#endif // DATAOPERATION_H


/*
    Program starts...
        ---> Programmer wants first object
        ---> Programmer notices no constructor
        ---> Programmer also notices GetInstances....
        ---> Programmer invokes GetInstances..



    GetInstances will check if previously and object was created,
        ---> If not, makes a new object, returns its address
        ---> Else, Returns the address of existing object


*/
