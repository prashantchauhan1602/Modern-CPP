
/*
    Original amount : 1000
    
    If I do 100 transaction each to withdraw 10 rs
    and
    100 more transaction to deposit 10 rs
*/

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;

int amount = 1000;                         // Global Variable : Not a good choice..



void withDraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));


        // CRITICAL SECTION....
        // mt.lock();
        // amount = amount - 10;                                    
        // mt.unlock();

        // But if the exception occurs , then mt.unlock() will not run..
        // Creates a condition of DEADLOCK

        // std::lock_guard<std::mutex> lk(mt);          // [ SOLUTION ]
        amount = amount - 10;
   }
}

void Deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));

        // mt.lock();
        // amount = amount + 10;
        // mt.unlock();

        // std::lock_guard<std::mutex> lk(mt);
        amount = amount + 10;
    }
}

int main(){
    std::thread t1(&withDraw);
    std::thread t2(&Deposit);

    if(t1.joinable()){
        t1.join();
    }

    if(t2.joinable()){
        t2.join();
    }

    std::cout << "Final answer is : " << amount << "\n";
}

/*
    Terminal for loop :
        for (( i=0; i<50; i++)); do ./outputfileName ; done
*/

/*
    RACE CONDITION IN THIS CODE : Why it happens ?
        IT OCCURS SPECIALLY WHEN SHARED MEMORY IS USED....

    WITHOUT MUTEX : 
        MAIN STARTS 
        MAIN CREATES WITHDRAW
        MAIN CREATES DEPOSIT

        Suppose withdraw function is called first...
            1000 ---> l3 Cache ---> l2 Cache ---> l1 Cache ---> REGISTER[EAX] ---> ALU[ 1000 - 10 = 990]
            [ RAM ] <---------------------------------------------------------------------------ANSWER

            But before the ANSWER came to the RAM by DATA BUS, DEPOSIT function called...

            DEPOSIT
            [ 990 ]  ----> It comes but before this deposit function is triggered with initial value 1000..

            [ 1000 ] ----------------------------------------------------------------> ALU[1000 + 10]

            <----------  1010



*/
