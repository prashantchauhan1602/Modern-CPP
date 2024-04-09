#include "MapFunctionality.h"

// STL FUNCTION WORKS ON VALUE.....
// CONST LVALUE REFERENCE OR RVALUE WITH &&...

void createObjects(Container &data)
{
    data.emplace(
        std::make_pair(
            "UP12K95",
            std::make_shared<TouristVehicle>(
                "UP12K95",
                6,
                10.5f,
                TOURISTVEHICLETYPE::BUS,
                std::make_shared<Permit>(
                    "AA1234",
                    97,
                    PERMITTYPE::LEASE))));

    data.emplace(
        std::make_pair(
            "MH12K2985",
            std::make_shared<TouristVehicle>(
                "MH12K2985",
                10,
                80.5f,
                TOURISTVEHICLETYPE::CAR,
                std::make_shared<Permit>(
                    "BB9876",
                    97,
                    PERMITTYPE::LEASE))));

    data.emplace(
        std::make_pair(
            "UP12K91",
            std::make_shared<TouristVehicle>(
                "UP12K91",
                8,
                91.2f,
                TOURISTVEHICLETYPE::CAR,
                std::make_shared<Permit>(
                    "CC4567",
                    122,
                    PERMITTYPE::OWNED))));

    data.emplace(
        std::make_pair(
            "UP15BR0773",
            std::make_shared<TouristVehicle>(
                "UP15BR0773",
                2,
                80.5f,
                TOURISTVEHICLETYPE::BIKE,
                std::make_shared<Permit>(
                    "INDIA",
                    97,
                    PERMITTYPE::OWNED))));
}

std::optional<std::list<TouristVehiclePtr>> printFirstNInstanceSatisfyCondition(const Container &data, unsigned int N)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    if ((int)N <= 0 || (int)N > data.size())
    {
        throw invalidNValueException("N value is invalid !! \n");
    }

    // COPY NOT ALLOWED IN MAP Container !!
  
    /*
        For each pair in the input data,
        a) Extract pair.second
        b) Push_back pair.second into the result...
    */

    // a) Exract pair.second   & push into list...

    std::list<TouristVehiclePtr> result;

    std::for_each(
        data.begin(),
        data.end(),
        [&](const MapEntry &p)
        {
            if (p.second->seatCount() >= 4 && p.second->permit()->permitType() == PERMITTYPE::OWNED)
            {
                result.push_back(p.second);
            }
        });

    if (result.size() < N)
    {
        return std::nullopt;
    }

    result.resize(N);
    return result;
}

float AveragePerHourBookingCharges(const Container &data)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    float total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float upto_current_val, const MapEntry &ptr)
        {
            return upto_current_val + ptr.second->perHourBookingCharges();
        });

    return (total / static_cast<float>(data.size()));
}

float MaxPerHourCharges(const Container &data)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    // float maxi = data.begin()->second->perHourBookingCharges();

    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](const MapEntry &p, const MapEntry& p1)
        { return p.second->perHourBookingCharges() < p1.second->perHourBookingCharges(); });

    return (itr->second->perHourBookingCharges());
}

std::list<TouristVehiclePtr> printFirstNFunctionalities(Container &data, unsigned int N)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    if ((int)N <= 0 || (int)N > data.size())
    {
        throw invalidNValueException("N value is invalid !! \n");
    }

    std::list<TouristVehiclePtr> result;
    std::for_each_n(
        data.begin(),
        N,
        [&](const MapEntry &p)
        {
            result.push_back(p.second);
        });

    return result;
}

bool AreContainerInstanceOfSamePermitType(Container &data)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no all of same type !! \n");
    }

    PERMITTYPE type = data.begin()->second->permit()->permitType();
    bool ans = std::all_of(
        data.begin(),
        data.end(),
        [&](const MapEntry &p)
        {
            return p.second->permit()->permitType() == type;
        });

    return ans;
}

std::size_t CountCabType(Container &data)
{

    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no cab type !! \n");
    }

    int total = std::count_if(
        data.begin(),
        data.end(),
        [](MapEntry &&p)
        {
            return p.second->vehicleType() == TOURISTVEHICLETYPE::CAR;
        });

    return total;
}

std::optional<PermitPtr> FindPermitById(Container &data, std::string id)
{
    if (data.empty())
    {
        throw dataEmptyException("Data empty ----> no permit id\n");
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const MapEntry &p)
        {
            return p.second->permit()->serialNumberOfPermit() == id;
        });

    if (itr == data.end())
    {
        return std::nullopt;
    }
    return (*itr).second->permit();
}

int LastNMaxSeatCount(Container &data, unsigned int N)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    if ((int)N <= 0 || (int)N > data.size())
    {
        throw invalidNValueException("N value is invalid !! \n");
    }

    auto itr = data.begin();
    std::advance(itr, data.size() - N);

    auto it1 = std::max_element(
        itr,
        data.end(),
        [](const MapEntry &p, const MapEntry &p1)
        { return p.second->seatCount() < p1.second->seatCount(); });

    return (*it1).second->seatCount();
}

std::list<float> CalculateGST(Container &data, std::function<float( const MapEntry & ptr)> fn)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty ---- no max per hour charge !! \n");
    }

    std::list<float> result;
    std::transform(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),fn);
    return result;
}
