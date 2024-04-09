#include <iostream>
#include <memory>
#include <functional>
#include <array>
/*
    Take N values from the user
*/
using FnType = std::function<void(int)>;
using FnContainer = std::array<FnType, 5>;

void Adaptor(const std::array<int,5> &data,
            FnContainer& fn)
{
    for (int i = 0; i < 5; i++)
    {
        fn[i](data[i]);
    }
}

int main()
{

    std::array<int, 5> data{10, 20, 30, 40, 50};

    FnContainer fns
    {
        [](int number){ std::cout << number * number << std::endl; },
        
        [](int number){ std::cout << number * 2 << std::endl; },

        [](int number){ std::cout << number * 3 << std::endl; },

        [](int number){ std::cout << number * 4 << std::endl; },

        [](int number){ std::cout << number * 5 << std::endl; },
    };

    Adaptor(data, fns);
}
