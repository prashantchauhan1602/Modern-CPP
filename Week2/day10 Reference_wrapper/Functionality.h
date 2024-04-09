#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include<list>
#include"Project.h"
#include"Employee.h"
#include<memory>

using ProjectContainer = std::list<Project>;      // stack memory
using RefContainer = std::list<ProjectRef>;       // check it once !! 
// using EmployeeContainer = std::list<Employee>;

// Convert the code by using Shared_ptr...

using EmpPointer = std::shared_ptr<Employee>;
using EmployeeContainer = std::list<EmpPointer>;


void CreateObject(ProjectContainer& projects, EmployeeContainer& employees);


/*
    Find the budget for the project based on Employee Id given as parameters...
*/

// Only employee container passed because employee container access the project container values..
float FindBudgetBasedOnId(EmployeeContainer&employees,int idFind);

/*
    Return the refererence wrapper of first N instance given by the user as second params..
*/

RefContainer FindFirstNProjectReferences(const EmployeeContainer& employees, unsigned int N);

/*
    Find if all employee have a salary above 5000
*/

bool IsContainerAll50KAboveSalary(const EmployeeContainer& employees);

/*
    Find the count of employee working on projects with budget over 60000
*/

std::size_t EmployeeCountBudgetOver60000(const EmployeeContainer& employees);

/*
    Return a container of Employee instance filetered based on predicate provided 
        as an argument...

    Predicate : A function always returns a bool value....
                    Input is only single parameter..(always)  
                            [like take only one object and check the condition]
*/

// Here the data type is Employee....
EmployeeContainer FilterEmployeeByPredicate(const EmployeeContainer& employees, 
                            std::function<bool(const Employee&)>pred);

/*
    Calculate for each employee based on a "Tax formula logic" passed as an argument 
                [ Lambda function ]
*/

void ComputeTaxBasedOnFormula(const EmployeeContainer&employees, 
                        std::function<float(const Employee&)> fn);       
                            // [ variable name fn is a choice here...]








#endif // FUNCTIONALITY_H
