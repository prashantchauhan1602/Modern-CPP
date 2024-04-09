#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>

using FnType = std::function<void(int)>;
using FnContainer = std::vector<FnType>;

using DataContainer = std::vector<int>;


class Task
{
private:
    std::mutex mt;

public:
    Task() = default;
    Task(const Task &) = delete;
    Task(Task &&) = delete;
    Task &operator=(const Task &) = delete;
    Task &operator=(Task &&) = delete;

    ~Task() = default;

    void square(int number)
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "Square is : " << number * number << std::endl;
    }

    void cube(int number)
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "Cube is : " << number * number * number << std::endl;
    }

    void Ctimes(int number)
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "100 times of value is : " << 100 * number << std::endl;
    }

    void factorial(int number)
    {
        int ans = 1;
        while (number)
        {
            ans = ans * number;
            number--;
        }
        std::lock_guard<std::mutex> lk(mt);
        std::cout << ans << std::endl;
    }

    void fibonacci(int number)
    {
        int a = 0;
        int b = 1;
        int sum;

        for (int i = 0; i < number - 2; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
        }

        std::lock_guard<std::mutex> lk(mt);
        std::cout << number << "th Fibonacci number is : " << sum << std::endl;
    }

    void Adaptor(DataContainer &data, FnContainer &fns)
    {
        if (data.empty())
        {
            throw std::runtime_error("Data is empty now !! ");
        }

        for (int i = 0; i < fns.size(); i++)
        {
            fns[i](data[i]);
        }
    }
};

int main()
{
    Task t{};
    DataContainer data{5, 6, 7, 8, 9};

    std::thread t1(&Task::square, &t);
    std::thread t2(&Task::cube, &t);
    std::thread t3(&Task::Ctimes, &t);
    std::thread t4(&Task::factorial, &t);
    std::thread t5(&Task::fibonacci, &t);

    if(t1.joinable()){
        t1.join();
    }
    if(t2.joinable()){
        t2.join();
    }
    if(t3.joinable()){
        t3.join();
    }
    if(t4.joinable()){
        t4.join();
    }
    if(t5.joinable()){
        t5.join();
    }
}
