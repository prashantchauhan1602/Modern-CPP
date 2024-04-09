#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std::chrono;

unsigned long long findevenSum(unsigned long long start, unsigned long long end){
    unsigned long long evenSum =0;
    for(unsigned long long i=start; i<end; i++){
        if( (i & 1) == 0){
            evenSum+=i;
        } 
    }
    return evenSum;
}

unsigned long long findoddSum(unsigned long long start, unsigned long long end){
    unsigned long long oddSum =0;
    for(unsigned long long i=0; i<end; i++){
        if( (i & 1) == 1){
            oddSum+=i;
        } 
    }
    return oddSum;
}

int main(){
    unsigned long long start = 0;
    unsigned long long end = 1900000;

    auto startTime = std::chrono::high_resolution_clock::now();
    unsigned long long evs = findevenSum(start, end);
    unsigned long long odd = findoddSum(start, end);
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<microseconds>(startTime, endTime);

    std::cout << "Even sum is : " << evs << std::endl;
    std::cout << "Odd sum is : " << odd << std::endl;

    std::cout << "Second : " << 

}
