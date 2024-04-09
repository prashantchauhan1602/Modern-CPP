#include<iostream>
#include<functional>
#include<cstring>

int formula(int x,int y, int z){
    return (x + y - z);
}


void Adaptor(int n1, int n2, std::function<void(int,int)>fn){
    fn(n1, n2) ;

}

class Dummy{
private:
    int _factor;

public:
    Dummy(int factor): _factor{factor}{}

    void Magic(int n1){
        std::cout << _factor* n1 << std::endl;
    }
};


int main(){
    // std::cout << formula(10,50,20) << std::endl;


    // std::cout << formula(20,50);
    /*
        It gives an error because there are only two params are passed
            but required arguments are three...

        Now, I want that value of x becomes 100 (explicitly) without changing the
            modification of original function...
    */

   // Works if value passed directly/variable passed/ std::ref(variale)
   int n1 = 100;
   int& d = std::ref(n1);

   auto fn = std::bind(&formula, d, std::placeholders::_1, std::placeholders::_2);
   std::cout << fn(40,30) << std::endl;

   /*
        Now, if the user passed three arguments then the last one will be discarded...
   */

//    std::cout << fn(50,30,40) << std::endl;    // [ x= 100, y = 20 , z = 30 ]  and 40 will be discarded...


   // Objective : Hardcore fn from Adaptor to addition function....
    Adaptor(50,90, [](int n1 , int n2){ std::cout << n1*n2 << std::endl ;});  // [ Multiply function is discarded now..]

   auto binded_adapter = std::bind(&Adaptor, std::placeholders::_1, 
                    std::placeholders::_2,
                    [](int n1, int n2){
                    std::cout << n1+n2 << std::endl;
                });

    binded_adapter(50,90);


    // binded_adapter(50,90);

    // Bind strcpy.....  (source , destination)

    // auto asli_strcpy = std::bind(&strcpy, std::placeholders::_2, std::placeholders::_1);
    // std::string _msg;
    // asli_strcpy("Rana", _msg);
    // std::cout << _msg;

    // <----------------------- Class ka magic function ------------------>

    // Dummy d1(4);

    // auto new_magic = std::bind(&Dummy::Magic, &d1, 50);     // d1[0x100H] -> Dummy:: Magic
                                                            // use & with object [ &d1 ]
    // d1.Magic(20);      // 80 
    // new_magic(20);  // 200  = 4 * 50 (fixed value)


    // Lambda function....[ different trick ]

    // auto f1 = [](int number){ std:: cout << number* number << std::endl;};

    // auto binded_f1 = std::bind(f1, 100);  // [ Don't use & here...like &f1 ]
    // binded_f1();
    
}

/*
    Reg_owner_name, car_model, car_engine_fuel...

    Now, after 50 years, we want that engine fuel is set or bind to a fixed value...

        Then, in this condition bind function is used..
*/


/*
        Functional programming

            -Use function as values
            -flexibility : User can paas data as well as logic
            -first class function benefits
                -every function has a type
                -function can be passed as an argument
                -function can be returned as an argument
                -function can be saved in other variable(closure)
                -function can be saved in containers

            -Adaptors:
                Higher Order function because it accepts and/order returns functions..

            -Function Wrappers:
                -a data type(class) which can be used to attach to a callable of 
                    any kind (member function, top level function, lambda function,
                        functor object etc...)

                - It is an improvement over function pointer syntax

            -Lambda : 
                - Anonymous function...
                - One time - use and throw logic
                - You can limit logic to a scope !!
                - Capture clause: 
                    [] - capture data from enclosing function into lambda scope

            -Reference wrapper:
                -Improvement over raw reference_wrappers
                -normal references(raw reference) have drawbacks:
                    -Raw reference has no memory footprint !!
                        [ Reference nhii le sakte, memory nhii hoti inki...]

                -put pointers to original data into a wrapper, when use wants,
                    dereference pointer and return object by reference:
                        MAGIC !!!!!!!!  std::reference_wrapper

                -Use it for : AGGREGATION PROBLEM

            -std::bind
                -Use it to change functionality of an existing API without by:
                    a) swap parameters
                    b) fix/ hardcore some parameters

            // Video : Cppcon video (iterators and problem)
*/


/*
    <-------------------- Function and their problem ----------------------->

    Problem : Some function are designed for "call by value" semantic only !!

        These three function cannot accept "call by reference" data...

        1) std::bind :

        2) std::thread

        3) std::async

*/

/*  
    RefContainer FindFirstNProjectReferences(const EmployeeContainer &employees, unsigned int N){
        EmployeeContainer mySpecialContainer;   // 100 objects..

        std::bind(&FindFirstNProjectReferences, mySpecialContainer);

        This will not work because it try to copy the data...
        If the data is copied during Runtime, then it will be a risky practise..

    Hack to do this : 
        By using std::ref:
            std::ref is a function to create reference_wrapper..

    Solution : 
        RefContainer FindFirstNProjectReferences(const EmployeeContainer &employees, unsigned int N){
        EmployeeContainer mySpecialContainer;   // 100 objects..

        std::bind(&FindFirstNProjectReferences, 
            std::ref(mySpecialContainer), std::placeholders::_2);
}
*/
int n1 = 100;
   int& d = std::ref(n1);

   auto fn = std::bind(&formula, d, std::placeholders::_1, std::placeholders::_2);
   std::cout << fn(40,30) << std::endl;

Adaptor(50,90, [](int n1 , int n2){ std::cout << n1*n2 << std::endl ;});  // [ Multiply function is discarded now..]

   auto binded_adapter = std::bind(&Adaptor, std::placeholders::_1, 
                    std::placeholders::_2,
                    [](int n1, int n2){
                    std::cout << n1+n2 << std::endl;
                });

    binded_adapter(50,90);

  Dummy d1(4);

    auto new_magic = std::bind(&Dummy::Magic, &d1, 50);
    new_magic(20)

x1
