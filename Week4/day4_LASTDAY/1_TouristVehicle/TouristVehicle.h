#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include<iostream>
#include<memory>
#include"Permit.h"
#include"TouristVehicleType.h"

using PermitPtr = std::shared_ptr<Permit>;


class TouristVehicle
{
private:
    std::string _vehicleRegistrationNumber {" "};
    int _seatCount {0};
    float _perHourBookingCharges {0.0f};
    
    TOURISTVEHICLETYPE _vehicleType {TOURISTVEHICLETYPE::BIKE};
    PermitPtr _permit {nullptr};

public:
    TouristVehicle() = default;

    TouristVehicle(const TouristVehicle&) = delete;
    TouristVehicle& operator=(TouristVehicle&) = delete;

    TouristVehicle(const TouristVehicle&&) = delete;
    TouristVehicle& operator=(TouristVehicle&&) = delete;

    ~TouristVehicle() = default;


    // Getter and Setter functions.....
    std::string vehicleRegistrationNumber() const { return _vehicleRegistrationNumber; }

    int seatCount() const { return _seatCount; }

    float perHourBookingCharges() const { return _perHourBookingCharges; }
    void setPerHourBookingCharges(float perHourBookingCharges) { _perHourBookingCharges = perHourBookingCharges; }

    TOURISTVEHICLETYPE vehicleType() const { return _vehicleType; }

    // Containership....
   
    PermitPtr permit() const { return _permit; }
    void setPermit(const PermitPtr &permit) { _permit = permit; }
    
    // Parameterized Constructor...
    TouristVehicle(std::string vehicleRegistrationNumber, int seatCount, float perHourBookingCharges, TOURISTVEHICLETYPE vehicleType, PermitPtr permit);


    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H

/*
    TouristVehicle t1;          //Garbage values
    TouristVehicle t2{};        // { " " , 0, BIKE , 0.0f, 0} 
                                   [whatever the parameter is]
*/
