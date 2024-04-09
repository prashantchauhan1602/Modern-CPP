#include<iostream>

#include"Employee.h"
#include"BusinessOwner.h"
#include<variant>
#include<array>

using vType = std::variant<Employee*, BusinessOwner*>;
/*
    Each variant variable when declared is always initialised with default value 
    of type at first position in variant declaration...

    Eg: vType was declared<Employee, BusinessOwner>. Employee is first position type

    vType v will be assigned default value of type Employee which means Employee class
    should have default constructor enabled...

    ByPass : We can make variant of Employee* , BusinessOwner*..

    Variant is like a object - It can passed as arguments...return variantType etc...
*/

void CreateObject(){
    vType v = new Employee("Prashant", 45800.0f);

    v = new BusinessOwner("Aadi", 1000.0f, 750.0f);
}

void CreateObjects(std::array<vType, 2>& data){

    data[0] = new Employee("Prashant", 45800.0f);
// struct Employee
// {
//     int _id;
//     char _grade;
// };

// union Employee
// {
//     int _id;
//     char _grade;
// };

// int main(){

        // union Employee e1;

//     e1._id = 10;                     // Grade is inaccessible but id is...
// }


/*
    Employee : 
        Manager 
        Accountant
        HR

    Variant : Better version of Inheritance if child types are fixed..

    variant<Manager, Accountant, HR> = h1;

    Drawbacks : We cannot add more child in this method...
*/


    data[0] = new BusinessOwner("Satyam", 1000.0f , 800.0f); // [ Now Prashant Employee data will overwrite or erase]

    data[1] = new Employee("Prashant" , 85000.0f);

    // When you change the variant data on same position , old data will erased....
}


void TaxFunctionCall(std::array<vType, 2>& data){
    /*
        for each variant that is stored in the array,
            a) Visit that variant
            b) Open the variant wrapper, you should get a pointer inside.
                Pointer may be of Employee type or BusinessOwner type
            c) Regardless of type, call the pointer as "val". Now use val to call PayTax Function...
    */

   for(vType& v : data){
    std::visit(
        [](auto&& val) { val->PayTax() ;}, v
    );

    /*
        Visit function takes two parameters:
            1) A callabele that explains what you want to do with the item found inside the variant
            2) You can pass one or more variants (based on operation requirements)
                    Eg : We can pass v1 , v2 instead of v in above code also
    */
   }
}

int main(){

    std::array<vType, 2> data;
    CreateObjects(data);
    TaxFunctionCall(data);
}
