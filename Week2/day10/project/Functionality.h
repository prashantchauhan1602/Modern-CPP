#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include<vector>
#include<iostream>
#include"Project.h"
#include"Employee.h"

using EmployeeContainer = std::vector<Employee>;
using ProjectContainer = std::vector<Project>;

void createObject(ProjectContainer& projectContainer, EmployeeContainer& employeeContainer);

void printObject(EmployeeContainer& employeeContainer);

#endif // FUNCTIONALITY_H
