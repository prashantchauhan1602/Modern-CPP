/*
    Few important points to remember about the unique_lock is as follows:
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies

    b. time-constrained attempts at locking (try_lock_for, try_lock_until)

    c. recursive locking
    d. transfer of lock ownership (Only move ---->  not copy)
        For eg: 
                If obj1 has ownership of mutex mt, then it can only be transfer from another obj (obj2)....NOw obj1 has not contain ownership of mutex mt...

    e. condition variables. (See this in coming videos)

Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  do not acquire ownership of the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex.

std::unique_lock<std::mutex> lock(mt, defer_lock);


mt.try_lock_for(2 second);
mt.lock();   --------------------> infinite time
*/


#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;
int buffer = 0;

void Task(const char* ch, int loopFor){
    std::unique_lock<std::mutex> lk(mt);
    for(int i=0;i<loopFor;++i){
        buffer++;
        std::cout << ch << " " << buffer << std::endl;
    }

    // std::unique_lock<std::mutex> lk(mt, defer_lock);


    // Provides flexibility to write here...


    lk.lock();
    // for(int i=0;i<loopFor;++i){
    //     buffer++;
    //     std::cout << ch << " " << buffer << std::endl;
    // }
}
 
int main(){
    std::thread t1(Task,"a",10);
    std::thread t2(Task ,"b", 15);
    t1.join();
    t2.join();

    return 0;
}

