#include "Functionality.h"

void CreateObjects(StackEmployeeContainer &data)
{
    data.emplace_back(Employee("Emp1", "Prashant", 45000.0f, 22, "Pune"));
    data.emplace_back(Employee("Emp2", "Dev", 75000.0f, 25, "Mohali"));
    data.emplace_back(Employee("Emp3", "Rana", 95000.0f, 27, "NOida"));
    data.emplace_back(Employee("Emp4", "Anchal", 115000.0f, 28, "Noida"));
    data.emplace_back(Employee("Emp5", "Chauhan", 130000.0f, 30, "Shamli"));
}

void CreateObjects(EmployeePointerContainer &data)
{
    data.emplace_back(new Employee("Emp1", "Prashant", 45000.0f, 22, "Pune"));
    data.emplace_back(new Employee("Emp2", "Dev", 75000.0f, 25, "Mohali"));
    data.emplace_back(new Employee("Emp3", "Rana", 95000.0f, 27, "NOida"));
    data.emplace_back(new Employee("Emp4", "Anchal", 115000.0f, 28, "Noida"));
    data.emplace_back(new Employee("Emp5", "Chauhan", 130000.0f, 30, "Shamli"));
}

void CreateObjects(EmployeeSmartPointerContainer &data)
{
    data.emplace_back(std::make_shared<Employee>("Emp1", "Prashant", 45000.0f, 22, "Pune"));
    data.emplace_back(std::make_shared<Employee>("Emp2", "Dev", 75000.0f, 25, "Mohali"));
    data.emplace_back(std::make_shared<Employee>("Emp3", "Rana", 95000.0f, 27, "NOida"));
    data.emplace_back(std::make_shared<Employee>("Emp4", "Anchal", 115000.0f, 28, "Noida"));
    data.emplace_back(std::make_shared<Employee>("Emp5", "Chauhan", 130000.0f, 30, "Shamli"));
}
