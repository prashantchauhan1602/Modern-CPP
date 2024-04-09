/*
    Objective : 
        12 number stored in an array

        Calculate square of each number in array and store in a result array
            1 2 3 4 5 6 7 8 9 10 11 12

        Result : 1 4 9 16 25 36 49 64 81 100 121 144

        Thread : Divide array into 4 parts and apply threads on it...


*/


/*

Solution A)
    1) Declare the threads array and data array...
    2) Create thread by mapping square function on three data values each..
    3) Wait for all threads to complete
    4) After all threads are done, call display and print the result

    Systummmmmm : 
        Make plan ---> 
        Execute the plan ---> 
        Expect the plan to off rails ---> 
        Throw away the plan

    Writing solution happens in phases/ steps : 
        a) Interpret the problem "ACCURATELY !!"
        b) Design solution(s)
            b1) Evaluate each of your solution for feasible
            b2) Now do analysis and "Try to find" the best solution amongest all
        c) Implement the solution
        d) Unit test for all possible corner cases...
        e) Document the solution
        f) Use VCS to maintain code
        g) Assist in Deployment
        h) Maintain the code !!

Solution B)
    1) Create a class with logic for square written somewhere (member function, overload for operator())
    2) Initialize one object of this class where we have memory for input data and output data
    3) Create a mapping function to assign 3 values per thread 
    4) Wait for all thread in step 3 to complete
    5) Write logic for display and show output


*/

#include<thread>
#include<iostream>
#include<array>

using DataContainer = std::array<int, 12>;
using ThreadContainer = std::array<std::thread, 4>;
using ResultContainer = std::array<int, 12>;      
// Here, race condition will not occur because here we create an array of size 12...
// 12 inputs -----> 12 outputs   ------> mutex not be used...  
// If we used std::cout in function --------> then mutex will be used

void Display(DataContainer& data){
    for(int val: data){
        std::cout << val << std::endl;
    }
}


//Solution A :

void Square(DataContainer& data, ResultContainer& result, int start, int end){
    for(int i = start;i < end; i++){
        result[i] = data[i] * data[i];
    }
}

void MapThreadToData(DataContainer& data, ThreadContainer& thArr, ResultContainer& result){

    int k=0;
    int quoitent = data.size()/thArr.size();
    int th_count = 0;
    
    for(std::thread& th : thArr){
        th_count++;
        if(th_count == thArr.size()){
            th = std::thread(&Square,std::ref(data),std::ref(result), k, data.size());
        }
    
        else{
            th = std::thread(&Square, std::ref(data), std::ref(result), k , k+quoitent);
            k = k+quoitent;
        }
    }

}

int main(){

    DataContainer data{1,2,3,4,5,6,7,8,9,10,11,12};
    ThreadContainer thArr;
    ResultContainer result;

    MapThreadToData(data, thArr, result);

    for(std::thread& th: thArr){
        if(th.joinable()){
            th.join();
        }
    }

    Display(result);

}

// 10 - (0+3) = 7 > 3    -------------> k = 3
// 10 - (3+3) = 6 > 3   -------> k = 6

// 10 -(6+3)  = 1 > 3  -----> false 
// 10 - 6 = 7

/*
        [ 1, 2 ,3 , 4 ,5 , 6 ,7 ,8 , 9  ,10 , 11]

        [ 1, 2, 3]   ----------> thread t0

        [ 4, 5 , 6] -----------> thread t1

        [ 7, 8 , 9 ] ------------> thread t2

        [ 10, 11, 12 ] -----------> thread t3

*/

/*
    N number of data values
    X number of threads to be processed

    Scenario 1: N can be equally divided amongest X threads

    Scenario 2: N is slightly less than equal divide 
                    // 14 number and 3 threads

    Scenario 3: N is slightly more than equal divide 
                    // 14 number and 3 threads
     
*/

// 14 number % 3 = remainder ----->     2 remainder

// 14 // 3 = 4     

// total - remainder = 12

// 12, 14

// 0-12 ----> k+3
