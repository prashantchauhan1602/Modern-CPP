#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    std::string _e_id;
    std::string _e_name;
    float _salary;
    unsigned int _age;
    std::string _location;
public:
    Employee() = default;

    Employee(const Employee &) = default;
    Employee &operator=(const Employee &) = default;

    Employee(Employee &&) = default;
    Employee &operator=(Employee &&) = default;
    
    ~Employee() = default;


    std::string eId() const { return _e_id; }
    void setEId(const std::string &e_id) { _e_id = e_id; }

    std::string eName() const { return _e_name; }
    void setEName(const std::string &e_name) { _e_name = e_name; }

    float salary() const { return _salary; }

    unsigned int age() const { return _age; }

    std::string location() const { return _location; }
    
    Employee(std::string id, std::string name, float salary, unsigned int age, std::string location);

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};


#endif // EMPLOYEE_H
