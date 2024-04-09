#include<iostream>
#include<functional>


void Adapter(int n1, std::string& name, float salary, char& grade, 
            std::function<void(std::string& name, char& grade)> fn){
    //inside this function , logic should change name and grade

    // Connecting logic with function....[ calling ]
    // When your data is different place, so for this you have to call a function with values..

    fn(name, grade);

}

// If you are using capture mode...

void Adapter(int n1, std::string& name, float salary, char& grade, 
            std::function<void()> fn){
    //inside this function , logic should change name and grade

    // Connecting logic with function....[ calling ]
    // When your data is different place, so for this you have to call a function with values..

    fn();

}

int main(){

    // Declaration and initialization of a char type variable grade with initial 'A'

    char grade('A');
    std::string name {"Dev"};
    
    // Declaration and initialization of a variable f1 whose type is to be deduced by
    //      compiler based on initial lambda literal for a function theat accepts to 
    //      two parameters - string reference and grade reference with function returning void...

    auto f1 = [](std::string& name, char& grade) { name = "Rana"; grade = 'O';}; // [Defining]

    // After capturing the values...
    // auto f1 = [&]() { name = "Rana"; grade = 'O';} ;

    Adapter (10, name, 12500.0f, grade , f1);

    // We capture the value of data....Now you can remove the paramaters in lambda as well
    //    as Adapter function...

    Adapter(10, name, 10200.0f, grade, 
        [&](){ name = "Ben 10"; grade= 'U'; });
}
