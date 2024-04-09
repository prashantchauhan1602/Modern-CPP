#include"Functionality.h"
#include<iostream>

int main(){
    EmployeeContainer employees;
    ProjectContainer projects;

    CreateObject(projects, employees);

    try{

        float budget = FindBudgetBasedOnId(employees, 104);
        std::cout << "Budget for this id is : " << budget << std::endl;

        RefContainer ref_container = FindFirstNProjectReferences(employees, 2);
        

        // pending this one !!
    }
    catch(std::exception& ex){
        std::cerr << ex.what() << std::endl;
    }

    
}
