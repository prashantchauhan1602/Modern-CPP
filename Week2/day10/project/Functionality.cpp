#include "Functionality.h"
#include"Project.h"
#include"Employee.h"

void createObject(ProjectContainer &projectContainer, EmployeeContainer &employeeContainer)
{

    projectContainer.push_back(Project("Project1", 999));

    projectContainer.push_back(Project("Project2", 888));

    projectContainer.push_back(Project("Project3", 777));

    employeeContainer.push_back(Employee("Prashant Chauhan", 123, projectContainer[0]));

    employeeContainer.push_back(Employee("Dev", 234, projectContainer[1]));

    employeeContainer.push_back(Employee("Rana", 345, projectContainer[2]));
}

void printObject(EmployeeContainer& employeeContainer)
{
    if(employeeContainer.empty()){
        throw std::runtime_error("Data is empty !! \n");
    }

    for(Employee& ptr: employeeContainer){
        std::cout << ptr.employeeName() << "\n";

    }
}
