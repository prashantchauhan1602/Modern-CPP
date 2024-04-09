#include "Functionality.h"

std::condition_variable cv;
std::mutex mt;

int value{-1};
bool flag{false};
void ProducerInput()
{
    std::cout << "Enter the value : " ;
    std::cin >> value;

    //trigger a signal after cin is done, to indicate that consumer can proceed with square calculation...

    flag = true;
    cv.notify_one();     // Send signal to ANY ONE OF THE CONSUMER !!
}

void ConsumerOperation(){
    int* result = (int*)malloc(4);

    std::unique_lock<std::mutex> ul(mt);   // [ Nobody modify the values --> all threads block]

        /*
            
            If this thread runs first, then it will block all thread i.e Main and ProducerInput thread
                Now if this is locked off, then we are in Deadlock condition because if the input not received from the user 
                    and we put the lock ----> then there is no chance for input
        */

        /*
            Solution : 
                Use unique_lock : 
                    It checks the signal (Predicate func --> flag) --> if input is received then lock applied
                    Otherwise unlock all thread and wait for receiving the input...
        */
    
    cv.wait( ul , []{ return flag ;});

    /*
        Wait : 
            It checks only the condition  -----> true or false

            If false : It means the input is not received, unlock the lock...
            If true : Lock all the threads..
    */

    *result = value * value;

    std::cout << "Square calculation is  " << *result << std::endl;
}


/*

    UNIQUE_LOCK vs MUTEX vs LOCKGUARD...

            ALL THREE ARE USED TO PREVENT RACE CONDITION : 

    MUTEX : 
        A mutex is a synchronization primitive that ensures only one thread can access resource at a time....
        It typically provides : 

            a) lock() function:
                When a thread locks a mutex, it gains exclusive accesss to the protected resource, 
                    and other thread attempting to lock the mutex will be blocked until it is unlocked..

                Mutex can be used for both thread synchronization and protecting critical sections of code...

            b) unlock() function:
                When a thread unlock a mutex, then other thread uses critical section...

    PROBLEMS OF MUTEX : 

        1) As mutex is lock() and unlock() by manually, then there is a chance to skip one part..
            like : 
                forgot to unlock a thread 
                        OR
                forgot to lock a thread (critical section)

        2) If the exception comes under critical section then a thread will not be unlocked...
                and system goes to DEADLOCK CONDITION...

    LOCKGUARD:

        A LockGuard is ah higher-level abstraction often used with mutexes...

        It automatically locks a mutex upon creation and unlocks the mutex when it goes out of scope..

        It ensures that mutex is always released, even in the presence of exceptions or early returns..

    PROBLEMS IN LOCKGUARD : 

        For eg: 
            In our code, there are two functions : 
                One function is dependent to another function..... [ like Producer Consumer Problem ]

                    In this, consumer is depend on producer

            Problem : If ConsumerThread is allocated to CPU and we are using LockGuard 
                        then,
                            OUR SYSTEM MAY BE GOES TO DEADLOCK CONDITION OR EXCEPTION CONDITION  
                                ( because consumer doesn't have any data till now !! )


    UNIQUE_LOCK : 

        It provides more flexibility compared to LOCKGUARD..

        It's movable, meaning a "std::unique_lock" object can be transferred from one scope to another,
             or even between threads...

        In this, locking and unlocking a mutex can be done by manually or it acts as LOCKGUARD in some conditions...


*/
