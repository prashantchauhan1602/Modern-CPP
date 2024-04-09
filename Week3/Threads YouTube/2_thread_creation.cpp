#include<thread>
#include<iostream>


/*
    Five types : 
        1) Simple function
        2) Lambda function
        3) Functor [ Function object ]
        4) Non static Data member
        5) Static Data member
*/

class Base
{
private:
    /* data */
public:
    void operator()(int x){
        while(x-- > 0){
            std::cout << x << std::endl;
        }
    }
};

int main(){

    // By Functor 
    std::thread t1( (Base()), 10);
    t1.join();

    // By Non - Static Data member..
    Base b;
    // fun fuction to be declared...
    std::thread t2(&Base::fun, &b, 10);

    // By Static Member 
    // If functin is static then we don't have to pass the address of object...

    std::thread t3(&Base::fun2, 10);
}
