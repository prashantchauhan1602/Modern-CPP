#include "1_employee.h"

Employee::Employee(std::string id, std::string name, float salary, unsigned int age, std::string location)
    : _e_id{id}, _e_name{name}, _salary{salary}, _age{age}, _location{location}
{
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_e_id: " << rhs._e_id
       << " _e_name: " << rhs._e_name
       << " _salary: " << rhs._salary
       << " _age: " << rhs._age
       << " _location: " << rhs._location;
    return os;
}
