#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include"TouristVehicle.h"
#include"TouristVehicleType.h"
#include"invalidNValueException.h"
#include"dataEmptyException.h"
#include"Permit.h"
#include<list>
#include<memory>
#include<optional>
#include<algorithm>
#include<numeric>

using TouristVehiclePtr = std::shared_ptr<TouristVehicle>;
using PermitPtr = std::shared_ptr<Permit>;

using Container = std::list<TouristVehiclePtr>;
using Predicate = std::function<bool(float number)>;

void createObjects(Container& data);

std::optional<Container> printFirstNInstanceSatisfyCondition(const Container& data, unsigned int N);

float AveragePerHourBookingCharges(const Container& data);

float MaxPerHourCharges(const Container& data);

Container printFirstNFunctionalities(Container& data, unsigned int N);

bool AreContainerInstanceOfSamePermitType(Container&);

std::size_t CountCabType(Container& );

std::optional<PermitPtr> FindPermitById(Container& , std::string id);

int LastNMaxSeatCount(Container& , unsigned int N);

std::list<float> CalculateGST(Container& , std::function<float(const TouristVehiclePtr& ptr)> fn);


#endif // FUNCTIONALITY_H
