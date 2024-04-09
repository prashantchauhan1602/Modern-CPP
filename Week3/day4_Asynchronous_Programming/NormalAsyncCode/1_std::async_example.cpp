
/*
    Objective:
        Main thread will tak an input from the user...

        The input number's factorial will be calculated in the Factorial 
            fuction which peromr the following actions...

        a) Allocate memory for 4 byte 

    
*/


#include<future>
#include<iostream>


void factorial (std::future<int>&number){
    int* answer = (int*) malloc(4);      
    /*
        Statement can execute even before input !!>  
    */

   /*
        Since prerequisites task is done, malloc is finished, now I REALLY NEED THE INPUT
            WITHOUT WHICH I CAN'T PROCEED...
   */

    int n = number.get();  // WAIT TILL INPUT ARRIVES

    int final_result{1};
    for(int i=2; i<=n; i++)
    {
        final_result*=i;
    }

    *answer = final_result;

    std::cout << "Factorial is : " << *answer << std::endl;
}


#include <iostream>
#include <future>
#include <thread>

// Dummy factorial function
void factorial(std::future<int>& ft) {
    int n = ft.get(); // Retrieve the value from the promise
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    std::cout << "Factorial of " << n << " is: " << result << std::endl;
}

int main() {
    // S1: I want to make a promise to provide an Integer;
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    // Asynchronous call to the factorial function
    std::future<void> result = std::async(&factorial, std::ref(ft));

    int value;
    std::cout << "Enter a value: ";
    std::cin >> value;
    // Value has to be sent to another dummy variable !!
    pr.set_value(value);

    // We can wait for factorial to finish (wait !!)
    result.wait();

    return 0;
}

/*
Main  -------------------------------------------> factorial


*/

/*
    1) Promise : 
            Make a promise to provide an integer in future

    2) By paasing future varible by reference

    3) While factorial perfoms malloc , main thread accepts input and set that in the 
        Promise variable...

*/

