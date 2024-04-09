#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"Project.h"
#include<functional>

using ProjectRef = std::reference_wrapper<Project>;

class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;
    ProjectRef _project;
public:
    Employee() = delete;

    Employee(const Employee&) = default;
    Employee& operator=(Employee&) = delete;

    Employee(Employee&&) = default;
    Employee& operator=(Employee&&) = delete;

    ~Employee() = default;

    int id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

    ProjectRef project() const { return _project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    Employee(int id, std::string name,float salary, ProjectRef project);
};




#endif // EMPLOYEE_H
