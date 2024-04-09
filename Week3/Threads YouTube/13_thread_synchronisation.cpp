/*
    Few important points to remember for "Thread OR Process Synchronisation" is as follows:
1.0 Thread Or Process synchronize to access critical section.
2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
If there is any doubt regarding the video, please let me know in the comment section i would definitely try to solve it. 

*/

#include<iostream>
#include<mutex>
#include<thread>

long long balance = 0;
std::mutex mt;

// RACE CONDITION / CRITICAL SECTION : 
// void addMoney(int val){
//     balance+=val;
// }

void addMoney(int val){

    //  This is known as Thread Synchronisation...
    mt.lock();
    balance+=val;
    mt.unlock();
}

int main(){
    std::thread t1(addMoney, 200);
    std::thread t2(addMoney, 100);

    t1.join();
}
