/*
    Original amount : 1000

    If I do 100 transaction each to withdraw 10 rs
    and
    100 more transaction to deposit 10 rs
*/

#include <iostream>
#include <thread>
#include <mutex>

// Improvement of 3_sample.cpp file.....
// Create a wrapper class and wrap the global variable info..

class DataOperation
{
private:
    std::mutex mt;
    int _amount = 1000;

public:
    DataOperation() = default;

    DataOperation(const DataOperation &) = delete; // Always delete....[ construction in this way ]
    DataOperation &operator=(const DataOperation &) = delete;

    DataOperation(const DataOperation &&) = delete;
    DataOperation operator=(DataOperation &) = delete;

    ~DataOperation() = default;

    DataOperation(int amount) : _amount{amount} {}

    // <------------------- Getter function ----------------------->
    int amount() const { return _amount; }

    void withDraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));

            // CRITICAL SECTION....
            // mt.lock();
            // amount = amount - 10;
            // mt.unlock();

            // But if the exception occurs , then mt.unlock() will not run..
            // Creates a condition of DEADLOCK

            std::lock_guard<std::mutex> lk(mt); // [ SOLUTION ]
            _amount = _amount - 10;
        }
    }

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));

            // mt.lock();
            // amount = amount + 10;
            // mt.unlock();

            std::lock_guard<std::mutex> lk(mt);
            _amount = _amount + 10;
        }
    }

};

int main()
{
    DataOperation d1{};                                // Mandatory for having an objec object...

    std::thread t1(&DataOperation::withDraw, &d1);                 // Name with scope resolution and & before className....
    std::thread t2(&DataOperation::Deposit, &d1);

    if (t1.joinable())
    {
        t1.join();
    }

    if (t2.joinable())
    {
        t2.join();
    }

    std::cout << "Final answer is : " << d1.amount() << "\n";
}
