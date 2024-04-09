#ifndef PRIORITYQUEUEFUNCTIONLITY_H
#define PRIORITYQUEUEFUNCTIONLITY_H

#include<iostream>
#include<queue>
#include<memory>
#include<algorithm>
#include<numeric>
#include<list>
#include<vector>
#include<optional>

#include"TouristVehicle.h"
#include"Permit.h"
#include"dataEmptyException.h"
#include"invalidNValueException.h"

using TouristVehiclePtr = std::shared_ptr<TouristVehicle>;
using TouristContainer = std::vector<TouristVehiclePtr>;
using PermitPtr = std::shared_ptr<Permit>;

auto f1 = [](const TouristVehiclePtr& ptr1, const TouristVehiclePtr& ptr2){
    return ptr1->seatCount() < ptr2->seatCount();
};

using Container =  std::priority_queue<TouristVehiclePtr, std::vector<TouristVehiclePtr> , decltype(f1)>;


void createObjects(Container& data);

// std::optional<Container> printFirstNInstanceWithMatchingInstance(const Container& data, unsigned int N);

// float AveragePerHourBookingCharges(const Container& data);

// float MaxPerHourCharges(const Container& data);

// TouristContainer printFirstNFunctionalitiesNormal(Container &data, unsigned int N);

// bool AreContainerInstanceOfSamePermitType(Container&);

// std::size_t CountCabType(Container& );

// std::optional<PermitPtr> FindPermitById(Container& , std::string id);

// int LastNMaxSeatCount(Container& , unsigned int N);

// std::list<float> CalculateGST(Container& , std::function<float( const TouristVehiclePtr &)> fn);

#endif // PRIORITYQUEUEFUNCTIONLITY_H



/*
I want to assign free/availabe ^ to projects in HIGHEST ECPERIENCE GETS PROJECT FIRST FASHION.
                -----------> PRIORITY QUEUE

If comparator does < operation, we get MAX_HEAP and vice versa//

    Example : 
            
    PRIORITY QUEUE CONSTRUCTOR : 
        It takes 3 parameters :
            IMPLEMENTATION OF PRIORITY : 
                std::priority_queue(Vptr, std::vector(VPtr), decltype(f1) pq(f1));

                // Third parameters is comparison 

            auto f1 = [](const Vptr& v1, const Vptr2){
                return v1->price() < v2->price()                     // Comparator function...
            }; 

            // If lambda function makes, then we have to passed it as a parameters...
            std::priority_queue<Vptr, std::vector<Vptr>, decltype(f1) pq(f1);

*/
