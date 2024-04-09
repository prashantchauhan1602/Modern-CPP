/*
    In this video we will learn about lock_guard in threading in C++ programming language.

Few points to remember about the lock_guard is as follows:
0. It is very light weight wrapper for owning mutex on scoped basis.
1. It acquires mutex lock the moment you create the object of lock_guard.
2. It automatically removes the lock while goes out of scope.
3. You can not explicitly unlock the lock_guard.
4. You can not copy lock_guard.
*/

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;
int buffer = 0;
void Task(const char* ch, int loopFor){
    std::lock_guard<std::mutex> lk(mt);
    for(int i=0;i<loopFor;++i){
        buffer++;
        std::cout << ch << " " << buffer << std::endl;
    }
}
 
int main(){
    std::thread t1(Task,"a",10);
    std::thread t2(Task ,"b", 15);
    t1.join();
    t2.join();

    return 0;
}
