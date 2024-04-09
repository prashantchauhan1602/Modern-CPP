#include<iostream>

class Demo
{
private:
    int _id;
    std::string _name;
public:
    Demo(int id) : _id{id} {}                  // Explicit type conversion

    // Demo(int id, std::string name="Dev") : _id{id}, _name{name} {}



    ~Demo() = default;
};

void Magic(Demo Obj){}

int main(){
    Magic(10);        // Implicit type conversion from int to Demo because of Parameterized Constructor
    
}

/*
    1. If your function takes one argument as Object Type and
            you have only (one single parameter or only one non default parameter)
            constructor in your class....then,

            If the argument type and when calls the function which take (object as a
                 parameter) then, it doesn't give an error because of implicit type conversion..

    2. For implicit type conversion like this, there is only one parameterizer
         constructor (one argument) is mandatory..

*/

/*
    NOte : 
        If a constructor has only one missing value or one unknown data member , then make it explicit...

        If you don't want implicit type conversion, then use explicit keyword in constructor
*/
