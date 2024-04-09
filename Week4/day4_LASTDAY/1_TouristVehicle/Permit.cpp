#include "Permit.h"


std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serialNumberOfPermit: " << rhs._serialNumberOfPermit
       << " _permitDurationLeft: " << rhs._permitDurationLeft
       << " _permitType: " << static_cast<int>(rhs._permitType)
       << " \n"
    ;
    return os;
}

Permit::Permit(std::string serialNumberOfPermit, unsigned int permitDurationLeft, PERMITTYPE permitType)
    : _serialNumberOfPermit{serialNumberOfPermit}, _permitDurationLeft{permitDurationLeft},
        _permitType{permitType}
{
}

