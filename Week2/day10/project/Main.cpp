#include<iostream>
#include"Project.h"
#include"Employee.h"
#include"Functionality.h"

int main(){

    EmployeeContainer empContainer;
    ProjectContainer projectContainer;
    
    createObject(projectContainer, empContainer);

    printObject(empContainer);
}
