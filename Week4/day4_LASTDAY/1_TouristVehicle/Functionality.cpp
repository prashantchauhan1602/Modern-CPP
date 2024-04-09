#include "Functionality.h"

void createObjects(Container &data)
{
    data.emplace_back(
        std::make_shared<TouristVehicle>(
            "UP12K95",
            6,
            10.5f,
            TOURISTVEHICLETYPE::BUS,
            std::make_shared<Permit>(
                "AA1234",
                97,
                PERMITTYPE::LEASE)));

    data.emplace_back(
        std::make_shared<TouristVehicle>(
            "MH12K2985",
            10,
            80.5f,
            TOURISTVEHICLETYPE::CAR,
            std::make_shared<Permit>(
                "BB9876",
                97,
                PERMITTYPE::LEASE)));

    data.emplace_back(
        std::make_shared<TouristVehicle>(
            "UP12K91",
            8,
            91.2f,
            TOURISTVEHICLETYPE::CAR,
            std::make_shared<Permit>(
                "CC4567",
                122,
                PERMITTYPE::OWNED)));

    data.emplace_back(
        std::make_shared<TouristVehicle>(
            "UP15BR0773",
            2,
            80.5f,
            TOURISTVEHICLETYPE::BIKE,
            std::make_shared<Permit>(
                "INDIA",
                97,
                PERMITTYPE::OWNED)));

}

std::optional<Container> printFirstNInstanceSatisfyCondition(const Container &data, unsigned int N)
{

    if ((int)N <= 0 || (int)N > data.size())
    {
        throw invalidNValueException("N value is not valid !! \n");
    }

    if (data.empty())
    {
        throw dataEmptyException("Data is empty !! \n");
    }

    /*
        STL PART :
            1st Part:
                Matching condition instance have to copied
                If N or more were instances were copied, we can now return first N instances from this
                    copied collection to the user..

                obj1         obj2      obj3        obj4          obj5

            2nd Part :
                2 Instances matching condition....
                obj1, obj4 and obj5
                Return obj1 and obj4
    */

    Container matching_instances{};
    Container actual_result{};

    std::copy_if(
        data.begin(),
        data.end(),
        std::inserter(matching_instances, matching_instances.begin()),
        [](const TouristVehiclePtr& ptr){
            return ptr->seatCount() >=4 && ptr->permit()->permitType() == PERMITTYPE::LEASE;
        }
    );

    if(matching_instances.size() < N){
        return std::nullopt;
    }
 
    std::copy_n(
        matching_instances.begin(),
        N,
        std::inserter(actual_result, actual_result.begin())
    );

    return actual_result;

    // OPTIMISED VERSION !!

    // matching_instances.resize(N);     
    // return matching_instances;                

}

float AveragePerHourBookingCharges(const Container &data)
{
    if(data.empty()){
        throw dataEmptyException("Data is empty - not calc average !! \n");
    }
    
    float total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,                                                              // Return type !!
        [](float current_upto_point, const TouristVehiclePtr& ptr){
            return current_upto_point + ptr->perHourBookingCharges();
        }
    );

    int count = data.size();
    return total / static_cast<float>(count);

}

float MaxPerHourCharges(const Container &data)
{
    // Always initialise the variable to any value....[ IMPORTANT ]
    if (data.empty())
    {
        throw dataEmptyException("Nothing is found in the container or it is empty !!");
    }

    auto itr1 = std::max_element(
        data.begin(),
        data.end(),
        [](const TouristVehiclePtr& p1, const TouristVehiclePtr& p2){
            return p1->perHourBookingCharges() < p2->perHourBookingCharges();
        }
    );

    return (*itr1)->perHourBookingCharges();

}

Container printFirstNFunctionalities(Container &data, unsigned int N)
{
    if (data.empty())
    {
        throw dataEmptyException("Data is empty yaar !! \n");
    }

    if ( (int)N <= 0 || (int)N > data.size())
    {
        throw invalidNValueException("Number of required facilities is invalid !! \n");
    }

    Container result;
    std::copy_n(
        data.begin(),
        N,
        std::inserter(result, result.begin())
    );

    return result;
}

bool AreContainerInstanceOfSamePermitType(Container& data){
    if (data.empty())
    {
        throw dataEmptyException("Data is empty yaar !! \n");
    }

    PERMITTYPE type = data.front()->permit()->permitType();

    bool ans = std::all_of(
        data.begin(),
        data.end(),
        [&](const TouristVehiclePtr& ptr){
            return ptr->permit()->permitType() == type;
        }
    );

    return ans;
}

std::size_t CountCabType(Container& data){
    if(data.empty()){
        throw dataEmptyException("Data empty -- no cab type !!\n");
    }

    std::size_t total = std::count_if(
        data.begin(),
        data.end(),
        [](const TouristVehiclePtr& ptr){
            return ptr->vehicleType() == TOURISTVEHICLETYPE::CAR;
        }
    );

    return total;
}

std::optional<PermitPtr> FindPermitById(Container &data, std::string id)
{
    if(data.empty()){
        throw dataEmptyException("data empty -- no permit id !! \n");
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const TouristVehiclePtr& ptr){
            return ptr->permit()->serialNumberOfPermit() == id;
        }
    );

    if(itr == data.end()){
        return std::nullopt;
    }
    return (*itr)->permit();
}

int LastNMaxSeatCount(Container &data, unsigned int N)
{
    if(data.empty()){
        throw dataEmptyException("data empty -- no permit id !! \n");
    }

    if( (int)N <= 0 || (int)N > data.size() ){
        throw invalidNValueException("N value is invalid \n");
    }

    auto itr = data.begin();
    std::advance(itr, data.size()-N);

    auto itr1 = std::max_element(
        itr, 
        data.end(),
        [](const TouristVehiclePtr& ptr1, const TouristVehiclePtr& ptr2){
            return ptr1->seatCount() < ptr2->seatCount();
        }
    );

    return (*itr1)->seatCount();

}

std::list<float> CalculateGST(Container &data, std::function<float(const TouristVehiclePtr& ptr)> fn)
{
    if(data.empty()){
        throw dataEmptyException("data empty -- no permit id !! \n");
    }

    std::list<float> result;
    std::transform(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),fn );

    return result;
}

