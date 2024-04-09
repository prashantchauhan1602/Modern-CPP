#ifndef MAPFUNCTIONALITY_H
#define MAPFUNCTIONALITY_H

#include"TouristVehicle.h"
#include"Permit.h"
#include"dataEmptyException.h"
#include"invalidNValueException.h"

#include<memory>
#include<unordered_map>
#include<list>
#include<functional>
#include<numeric>

using TouristVehiclePtr = std::shared_ptr<TouristVehicle>;

using MapEntry = std::pair<std::string, TouristVehiclePtr>;
using Container = std::unordered_map<std::string, TouristVehiclePtr>;


void createObjects(Container& data);

std::optional<std::list<TouristVehiclePtr>> printFirstNInstanceSatisfyCondition(const Container& data, unsigned int N);

float AveragePerHourBookingCharges(const Container& data);

float MaxPerHourCharges(const Container& data);

std::list<TouristVehiclePtr> printFirstNFunctionalities(Container& data, unsigned int N);

bool AreContainerInstanceOfSamePermitType(Container&);

std::size_t CountCabType(Container& );

std::optional<PermitPtr> FindPermitById(Container& , std::string id);

int LastNMaxSeatCount(Container& , unsigned int N);

std::list<float> CalculateGST(Container& , std::function<float( const MapEntry &)> fn);

#endif // MAPFUNCTIONALITY_H


