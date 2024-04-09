#include "Employee.h"


std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _project: " << rhs._project.get();           // get function to be used...
                                        // [for printing the value present at this address - get() func is used]
    return os;
}

// Copying the data...(copy constructor called here..)
Employee::Employee(int id, std::string name, float salary, ProjectRef project)
    : _id{id}, _name{name}, _salary{salary}, _project{project}
{
}
