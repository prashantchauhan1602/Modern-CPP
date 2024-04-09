#include"Employee.h"
#include"BusinessOwner.h"
#include<iostream>
#include<memory>
#include<list>
#include<variant>


using EmpPtr = std::shared_ptr<Employee>;
using BusinessPtr = std::shared_ptr<BusinessOwner>;

using vType = std::variant<EmpPtr, BusinessPtr>;

using Container = std::list<vType>;

void CreateObject(Container& data){

    /*
        a) make_shared returns EmpPtr (shared pointer to employee)
        b) Compiler tries to assign to the variant in postion 0 of the list
            Since variant accepts EmpPtr and BusinessPtr both, assignment is successuful , no errors !!
    */
    data.push_back(
        std::make_shared<Employee>("Dev", 150000.0f)
    );

    data.push_back(
        std::make_shared<BusinessOwner>("Aadi", 150000.0f, 122400.0f)
    );

    data.push_back(
        std::make_shared<Employee>("Satyam", 250000.0f)
    );

    /*



                                                BusinessOwner   [ "Aadi", 150000.0f, 122400.0f]
                                                [ 0x77H ]
                                                   |
            0x110H                                 |
        nullptr [Variant] 0x18H   -------> 0x11H [Variant] 033H -------> 0x22H [Variant] 
                    |                                                             |
                    |                                                             | [0x555H]
                    [0x123H ]                                                   EmpPtr [ "Satyam", 250000.0f]
                        |
                        | 
                        EmpPtr
                            |
                            |
                            ["Prashant" , 150000.0f]
    */
}

/*
    A function to print revenue of all BusinessOwner from the data
*/

void showRevenue(Container& data){
    /*
        for every vType variable codenamed "v" which is present in data,
            a) check if v holds the alternative of type BusineesPtr
                -If yes, since BusinessPtr is at position 1 in the declaration of vType , get<1> position pointer...
                -Use this pointer to fetch revenue getter
    */

    for(vType& v : data){
        if(std::holds_alternative<BusinessPtr>(v)){
            std::cout << std::get<1>(v)->revenue();
                // get < 1 >  -----> 1 is a index of Business in variant...
        }
    }
}

int main(){
    Container data;
    CreateObject(data);
    showRevenue(data);
}
