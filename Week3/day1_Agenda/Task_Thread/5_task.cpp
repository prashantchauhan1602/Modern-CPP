/*

    Create 6 functions and store them in Adaptor

        F1 : Takes 5 numbers as input from the user and save it to an array
        F2 : Computes squares of one integer
        F3 : Computes cube of one integer
        F4 : Computes 100 times the value of one integer
        F5 : Computes factorial of one Integer
        F6 : Computes Nth fibonacci series value where N is the integer an Input

        Performs function[i+2] on data[i]
            f2(data[0])
            f3(data[1])
            f4(data[2])

        Input constraints : All inputs must be between 1 to 10

        Eg : 1 2 3 4 5

        Output :
            1
            8
            300
            24
            5



*/

#include <iostream>
#include <array>
#include <functional>
#include <thread>
#include <mutex>

// std::mutex mt;

using FnType = std::function<void(int)>;
using FnContainer = std::array<FnType, 5>;
class Wrapper
{
private:
    std::mutex mt;
    std::array<int, 5> arr;

public:
    Wrapper() = default;

    Wrapper(const Wrapper &) = delete; // Always delete....[ construction in this way ]
    Wrapper &operator=(const Wrapper &) = delete;

    Wrapper(const Wrapper &&) = delete;
    Wrapper operator=(Wrapper &) = delete;

    ~Wrapper() = default;

    void square(int number)
    {

        std::lock_guard<std::mutex> lk(mt);
        std::cout << number * number << std::endl;
    }

    void cube(int number)
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << number * number * number << std::endl;
    }

    void Ctimes(int number)
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << number * 100 << std::endl;
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

    void Adaptor(const std::array<int, 5> &data, FnContainer &fn)
    {

        for (int i = 0; i < 5; i++)
        {
            fn[i](data[i]);
        }
    }
};

// using FnType = std::function<void(int)>;
// using FnContainer = std::array<FnType, 5>;

// void square(int number){

//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << number * number << std::endl;
// }

// void cube(int number){
//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << number* number* number << std::endl;
// }

// void Ctimes(int number){
//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << number * 100 << std::endl;
// }

// void factorial(int number){
//     int ans = 1;
//     while(number){
//         ans = ans* number;
//         number--;
//     }
//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << ans << std::endl;
// }

// void fibonacci(int number){
//     int a = 0;
//     int b = 1;
//     int sum ;

//     for(int i=0; i< number -2 ; i++){
//         sum = a + b;
//         a = b;
//         b = sum;
//     }

//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << number << "th Fibonacci number is : " << sum << std::endl;
// }
// void Adaptor(const std::array<int, 5> &data, FnContainer &fn)
// {

//     for (int i = 0; i < 5; i++)
//     {
//         fn[(i + 2) % 5](data[i]);
//     }
// }

int main()
{

    // FnContainer fns = {
    //     [](int number){ std::cout << number * number << std::endl;},
    //     [](int number){ std::cout << number * number* number << std::endl;} ,
    //     [](int number){ std::cout << number * 100 << std::endl;},
    //     [](int number){
    //         int ans = 1;
    //         while(number){
    //             ans = number* ans;
    //             number--;
    //         }
    //         std::cout << ans << std::endl;
    //     },
    //     [](int number){
    //         int sum = 0;
    //         int a = 0;
    //         int b = 1;
    //         std::cout << a << " " << b << " ";
    //         for(int i=0;i<number-2;i++){
    //             sum = a + b;
    //             std::cout << sum << "  ";
    //             a = b;
    //             b = sum;
    //         }
    //         std::cout << std::endl;

    //     }
    // };

    // FnContainer fns = {&Wrapper::square, Wrapper::cube, &Wrapper::Ctimes, &Wrapper::factorial, &Wrapper::fibonacci};

    Wrapper d1{};
    using thArray = std::array<std::thread,6>;
    // thArray[0]= std::thread t1(&Wrapper::square, &d1);
    // thArray[1]= std::thread t2(&Wrapper::cube, &d1);
    // thArray[2]= std::thread t3(&Wrapper::Ctimes, &d1);
    // thArray[3]= std::thread t4(&Wrapper::factorial, &d1);
    // thArray[4]= std::thread t5(&Wrapper::fibonacci, &d1);
    // thArray[5]= std::thread t6(&Wrapper::Adaptor, &d1);

    std::array<int, 5> arr{1, 2, 5, 4, 5};



    // Adaptor(arr, fns);
}
