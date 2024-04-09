#include<iostream>
#include<vector>

// This will work in string and integer also...
// template <typename T>
// void display(std::vector<T>& data){
//     for( T val : data){
//         std::cout << val << "\n";
//     }
// }

// template<typename T>
// T add(T n1){
//     return n1;
// }

// Aonther template...[Variadic Template CPP11 features...]
template<typename T, typename... Remainining>    // Remaining is a variable here...we can change it accodingly
T add (T n1,Remainining... args){
    return n1+ add(args...);
}

// Upper vale ka bada version...
// template <typename... T>                             // args could be 0 or more
// auto add(T... n1){                                  // auto used ...as return type
//     return add(n1 + ...)
// }
int main()
{
    // Checking first function...
    // std::vector<std::string> arr{"Prashant", "Dev", "Rana"};
    // display<std::string>(arr);

    // CHECKING SECOND TEMPLATE : 

    int a = 10;
    int b = add<int>(a);
    std::cout << "Value is : " << b <<std::endl;

    std::cout<<add<int>(10,20,30,40,50) << std::endl;
    // std::cout<<add<int>(10,20,30,90) << std::endl;

    // std::cout<< add<float>(12.5, 14.25f, 18.5f) << std::endl;
    // return 0;
}


/*
    Recursion Problem :
        A situation which requires a particular "algorithm" to find its solution...
            Eg: Searching a Number]

        Problem Solving Techniques : 
            a) GIVE UP !!
            b) Iterative Approach
            c) Divide and Conquer
            d) Recursion : Divide the problem into smaller problem till a well known, fully solved sub problem
                                appears. Then you reverse the chain and solve the whole problem...

                    Eg : Factorial(5)          
*/
