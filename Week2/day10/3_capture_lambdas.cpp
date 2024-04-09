#include<iostream>
#include<functional>


void Outer(){
    int n1 = 10;
    int n2 = 20;


    //Option 1:

    auto f1 = [](int n1, int n2){
        n1= 100;
        n2=300;
        std::cout <<  n1 + n2 << std::endl;
    };

    f1(n1, n2);    // works...

    // f2 captures all variables from the scope of its enclosing
    // function "Outer" 
    // which means n1 and n2 are accessible by reference in f2..
    auto f2 = [&](){
        std::cout << n1 + n2 << "\n";
        n1 = 50;
        n2 = 70;
    };

    f2();

    // Option 3 : 

    auto f3 =[=]()mutable{
        // n1 = 90;
        // n2 = 120;
        std::cout << n1 + n2 << "\n";    // Captured by Value...
    };

    f3();

    // Option 4: 

    // Captures only selected variables...
    auto f4 = [&](){
        std::cout << n1+n2 << "\n";    // Here, n2 gives error as it i snot fetched here
    };

    f4();

    // // Option 5:

    // auto f5 = [&n1,f1](){
    //     f1(n1,n2);   // n1 captured by reference, n2 is not accessible
    // };

    // f5();
}

/*
    Lambda function is not a function, it is considered as an Object by compiler..

    Sorrounding : If your lambda function X is kept inside the function Y,
    then all the data members or value of function Y can be 
    accessible by lambda function X....
*/
int main(){
    Outer();
}
