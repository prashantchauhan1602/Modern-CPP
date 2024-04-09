#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include<vector>
#include<memory>
#include"1_employee.h"


using StackEmployeeContainer = std::vector<Employee>;
using EmployeePointerContainer = std::vector<Employee*>;

using EmpPtr = std::shared_ptr<Employee>;
using EmployeeSmartPointerContainer = std::vector<EmpPtr>;


void CreateObjects(StackEmployeeContainer& data);
void CreateObjects(EmployeePointerContainer& data);
void CreateObjects(EmployeeSmartPointerContainer& data);

#endif // FUNCTIONALITY_H
