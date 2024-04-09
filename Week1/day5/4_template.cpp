#include<iostream>

/*
    GENERIC PROGRAMMING :-  
        Writing logic which works generally with all type OR
             writing type agonostic logic !!

*/

/*
    Now to print the value of integer and string 
        1. Create two display function for integer and string data type as arguments.
            But this is not feasible way because I have infinite number of Data types
                 in my code..
*/

/*
    Display is a function that accepts one reference of some data type T 
    and use << operator with data as rhs operand


*/

template < typename T>                   // [Receipe type....]
void Display( T &arg ){                  // [Paas the type here]
    std::cout << arg << "\n";
}

/*
    When calling both display function below.... Compiler did the following conversion

    void display(int & arg)    ------> 
    void display(std::string &arg)      -------->    
*/


// Add function...
/*
    Take two values(call by value), callt hem as n1 nad n2. 
    They could of any type BUT MY CONDITION IS THAT IT WOULD BE OF SAME TYPE !!
*/
template < typename T>       // [We can use class also instead of typename]
void AddSame(T n1, T n2){
    std::cout << n1 + n2 << "\n";
}

template < typename T, typename A>       // [We can use class also instead of typename]
void AddDifferntType(T n1, A n2){
    std::cout << n1 + n2 << "\n";
}

int main(){
    int n1=10;
    Display<int>(n1);

    std::string _name = "Prashant Rana";
    Display<std::string>(_name);

    AddSame<float>(10.20f, 8.70f);
    AddSame<int>(20, 12);

    AddDifferntType<int , float>(1, 3.2f);
}

/*
    In call by value : 
        Both the values are passed i.e (lvalue and rvalue)

*/
