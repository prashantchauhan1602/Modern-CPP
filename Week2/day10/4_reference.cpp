/*
    Unit 2 : Syllabus

        Function wrapper...
        Lambda function...
        Reference variable...
        std::ref
        std::bind
        

*/

/*

    Recap : 
        Reference : An alias or an alternate TO SOMETHING THAT ALREADY EXISTS !! 

    References Problem : 

        1) Reference don't exist in memory PHYSICALLY !. They have no memory footprint..
                Eg : int& arr[5];   ( Gives an error )

                Eg : int n1 = 10;
                     int & ref = n1;   // lvalue references..

                     std::vector<int&>data{ref};
*/

#include<iostream>
#include<functional>
#include<vector>

using refType = std::reference_wrapper<int>;


int main(){

    

    // Why people don't use regular reference from CPP in Modern CPP

    // Similar to why people don't use pointers in Modern CPP

    // This will give an error because references are not allowed...

    // int n1 = 10;
    // int & ref = n1;   // lvalue references..
    // int& d = std::ref(n1);
    // std::cout << d << std::endl;

    // std::vector<int &> data{ref};



    // Solution for this problem :-

    int n1 = 10;
    // std::reference_wrapper<int> ref {n1};    //[ using keyword used ]
    // std::cout << ref ;

    refType ref {n1};
    std::cout << ref << std::endl;

    // refType arr[1] {ref};

    // std::vector<refType> data {ref};
// refType ref {n1};

    // refType arr[1] {ref};

    // std::vector<refType> data {ref};

}

/*

    emp = [ Prashant    |   22   |  Pune]
                ^
                |
                Ox100H


                Employees : 

                ----->[                 [Employee*]                  ]-----> Employee&


    Reference wrapper : Takes reference and returns references....

*/

/*

    Employee e1("Dev", 22, "Pune");   !! Object

    std::reference_wrapper<Employee> ref{e1};

    Solution : 
            ref  -----> [ 0x100H ]

        std::cout << ref.get();                // return by reference (*0x100H)

*/
