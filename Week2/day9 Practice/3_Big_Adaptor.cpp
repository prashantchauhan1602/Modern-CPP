#include <iostream>
#include <vector>
#include <functional>

using FnType = std::function<void(const std::vector<int>)>;
using FnContainer = std::vector<FnType>;

void square(const std::vector<int> &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }

    std::cout << "Square of all element is : \n";
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] * data[i] << std::endl;
    }
}

void cube(const std::vector<int> &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    std::cout << "Cube of all element is : \n";

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] * data[i] * data[i] << std::endl;
    }
}

void Ctimes(const std::vector<int> &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data is empty");
    }
    std::cout << "Cube of all element is : \n";

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << 100 * data[i] << std::endl;
    }
}

int takeChoice()
{
    std::cout << "Enter your choice to perform : \n";
    std::cout << "0 for Square \n1 for Cube \n2 for 100times \n-1 for Own logic \n";
    int input;
    std::cin >> input;
    return input;
}

void Adaptor(std::vector<int> &data, FnContainer& fns)
{
    fns(data);
    
    
}

int main()
{
    FnContainer fns = {square, cube, Ctimes};
    std::vector<int> arr{5, 6, 7, 8, 9};
    int choice = takeChoice();

    // if(choice == -1){
    //     Adaptor(std::vector<int>{2,4,6,7,9}, 
    //                 [](int number){ return number % 2 == 0;});
    // }

    Adaptor(arr, fns[choice]);

 
}

/*

    void factorial(std::vector<int>& arr){
        int number;
        for(int i=0;i<arr.size();i++){
            int ans = 1;
            number = arr[i];
            while(number){
                ans = ans* number;
                number--;
            }
            std::cout << "Factorial is : " << ans << std::endl;
        }
    }

    [](std::vector<int>& arr){
        int number;
        for(int i=0;i<arr.size();i++){
            int ans = 1;
            number = arr[i];
            while(number){
                ans = ans* number;
                number--;
            }
            std::cout << "Factorial is : " << ans << std::endl;
        }
    }
*/
