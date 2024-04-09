#include<iostream>
#include"Employee.h"


std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_employee_name: " << rhs._employee_name
       << " _emp_id: " << rhs._emp_id
    //    << " _project_wrapper: " << *(rhs._project_wrapper)
       ;
    return os;
}

Employee::Employee(std::string name, int id, std::reference_wrapper<Project> _project)
    : _employee_name{name}, _emp_id{id}, _project_wrapper{_project}
{
}
