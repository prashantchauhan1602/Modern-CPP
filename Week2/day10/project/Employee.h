#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<functional>
#include"Project.h"

class Employee
{
private:
    std::string _employee_name {""};
    int _emp_id{-1};

    std::reference_wrapper<Project> _project_wrapper;
public:
    Employee() = default;

    Employee(const Employee&) = delete;
    Employee operator=(const Employee&) = delete;

    Employee(Employee &&) = delete;
    Employee& operator=(Employee&&) = delete;

    ~Employee() = default;

    std::string employeeName() const { return _employee_name; }
    void setEmployeeName(const std::string &employee_name) { _employee_name = employee_name; }

    int empId() const { return _emp_id; }
    void setEmpId(int emp_id) { _emp_id = emp_id; }

    std::reference_wrapper<Project> projectWrapper() const { return _project_wrapper; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs); 

    Employee(std::string name, int id, std::reference_wrapper<Project> _project);


};




#endif // EMPLOYEE_H
