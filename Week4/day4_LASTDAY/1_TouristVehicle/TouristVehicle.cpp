
#include<iostream>
#include"TouristVehicle.h"


std::ostream &operator<<(std::ostream &os,const TouristVehicle &rhs) {
    os << "\n _vehicleRegistrationNumber: " << rhs._vehicleRegistrationNumber
       << " _seatCount: " << rhs._seatCount
       << " _perHourBookingCharges: " << rhs._perHourBookingCharges
       << "_vehicleType is : " << static_cast<int>(rhs._vehicleType)
    //    Use if else statement or operator overload
       << *(rhs.permit())
    ;
    return os;
}


TouristVehicle::TouristVehicle(std::string vehicleRegistrationNumber, int seatCount, float perHourBookingCharges, TOURISTVEHICLETYPE vehicleType, PermitPtr permit)
    : _vehicleRegistrationNumber{vehicleRegistrationNumber},
        _seatCount{seatCount}, _perHourBookingCharges{perHourBookingCharges},
         _vehicleType{vehicleType}, _permit{permit}
{
}
