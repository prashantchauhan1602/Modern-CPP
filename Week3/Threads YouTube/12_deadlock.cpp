#include<iostream>
#include<thread>
#include<mutex>

std::mutex m1;
std::mutex m2;
void f1(){
    m1.lock();

    // If we are not using sleep function...then our processor is too fast ----> there is a huge chance to run the code...
    // If m1 lock in F1 and m2 lock in F2 ----> In F1 m2 also wants to lock but m2 is already locked ---> but processor speed is too high ---> It may be run...
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    std::cout << "F1 Critical section called \n";
    m1.unlock();
    m2.unlock();
}

void f2(){
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m1.lock();
    std::cout << "F2 Critical section called \n";
    m2.unlock();
    m1.unlock();
}

int main(){
    std::thread t1(f1);
    std::thread t2(f2);

    t1.join();
    t2.join();
}
