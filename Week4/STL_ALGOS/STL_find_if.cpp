/*
    CPP 98 Feature: 

    To find the position of the first matching data in input container 
        Eg: Find the employee name for the employeee whose ID mathches with id provided

        Eg : Find the name of first employee in input whose salary is above 50K

    NOTE : If match is not found, then it returns an [ end iterator() ]

    USE & ALSO IN THIS FUNCTION.....

    auto itr = std::find_if(
        data.begin(),
        data.end(), 
        [&](const Employee&emp ){ return emp.id == id;}
    );

    CHECKING THE OUTPUT
    if(itr == data.end()){
        std::cerr << "Data matching id not found !! \n";
    }
    else{
        std::cout << *(itr).data_member();      // CHECKING THE DATA MEMBERS
    }


    IF WE WANT TO CREATE A FUNCTION FOR THIS : 

    DATA TYPE IS : 

    StackObject::const_iterator FetchNameByID(StackObject&data, std::string id){
        auto itr = std::find_if(
        data.begin(),
        data.end(), 
        [&](const Employee&emp ){ return emp.id == id;}
        );

        return itr;
    }
    std::string id + "v0101";
    StackObject::const_iterator itr = FetchByID(data, id);
    
    CHECKING THE OUTPUT
    if(itr == data.end()){
        std::cerr << "Data matching id not found !! \n";
    }
    else{
        std::cout << *(itr).data_member();      // CHECKING THE DATA MEMBERS
    }
*/

#include<iostream>
#include<algorithm>
#include<numeric>

#include"Functionality.h"

int main(){
    // USE & ALSO IN THIS FUNCTION.....
    StackEmployeeContainer data;
    CreateObjects(data);

    std::string _id = "Emp5";
    auto itr = std::find_if(
        data.begin(),
        data.end(), 
        [&](const Employee&emp ){ return emp.eId() == _id;}
    );

    std::cout << "Hello\n"; 
    std::cout << (*itr).eName();
}
