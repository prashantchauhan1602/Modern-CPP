#ifndef PERMIT_H
#define PERMIT_H
#include<iostream>
#include"PermitType.h"
class Permit
{
private:
    std::string _serialNumberOfPermit {""};
    unsigned int _permitDurationLeft {0};
    PERMITTYPE _permitType {PERMITTYPE::OWNED};
    
public:
    Permit() = default;

    Permit(const Permit&) = delete;
    Permit& operator=(const Permit&) = delete;

    Permit(Permit&&) = delete;
    Permit& operator=(Permit&&) = delete;

    ~Permit() = default;


    // Getter and Setter Method : 
    std::string serialNumberOfPermit() const { return _serialNumberOfPermit; }

    unsigned int permitDurationLeft() const { return _permitDurationLeft; }

    PERMITTYPE permitType() const { return _permitType; }
    void setPermitType(const PERMITTYPE &permitType) { _permitType = permitType; }
    
    // Parmaterized Constructor...
    Permit(std::string serialNumberOfPermit, unsigned int permitDurationLeft, PERMITTYPE permitType);

    

    


    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
