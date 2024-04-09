/*
    Few important points to remember while using "condition variables" are as follows:
1. Condition variables allow us to synchronise threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronise two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition
*/



#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::condition_variable cv;
std::mutex mt;
long balance = 0;

void addMoney(int money){
    std::lock_guard<std::mutex> lt(mt);
    balance+=money;
    std::cout << "Amount added : " << balance << std::endl;
    cv.notify_one();
}

void withdrawMoney(int money){
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, [&]{return (balance!=0) ? true : false;});

    if(balance >= money){
        balance-=money;
        std::cout << "Remaining balance is : " << balance << std::endl;
    }
    else{
        std::cout << "Amount can't deducted, Current balance is less than " << money << std::endl;
    }
    std::cout << "Current balance is : " << balance << std::endl;
}

int main(){
    std::thread t1(addMoney, 500);
    std::thread t2(withdrawMoney, 280);
    
    t1.join();
    t2.join();

    return 0;
}
