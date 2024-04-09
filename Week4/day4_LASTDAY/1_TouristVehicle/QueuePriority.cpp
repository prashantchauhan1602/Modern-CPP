#include"QueuePriority.h"

void createObjects(Container& data)
{
    PermitPtr p1 = std::make_shared<Permit>(
                "AA1234",
                97,
                PERMITTYPE::LEASE);
                
    TouristVehiclePtr t1 = std::make_shared<TouristVehicle>(
            "UP12K95",
            6,
            10.5f,
            TOURISTVEHICLETYPE::BUS,
            p1);

    data.push(t1);
    // data.push(
    //     std::make_shared<TouristVehicle>(
    //         "UP12K95",
    //         6,
    //         10.5f,
    //         TOURISTVEHICLETYPE::BUS,
    //         std::make_shared<Permit>(
    //             "AA1234",
    //             97,
    //             PERMITTYPE::LEASE)));

    // data.push(
    //     std::make_shared<TouristVehicle>(
    //         "MH12K2985",
    //         10,
    //         80.5f,
    //         TOURISTVEHICLETYPE::CAR,
    //         std::make_shared<Permit>(
    //             "BB9876",
    //             97,
    //             PERMITTYPE::LEASE)));

    // data.push(
    //     std::make_shared<TouristVehicle>(
    //         "UP12K91",
    //         8,
    //         91.2f,
    //         TOURISTVEHICLETYPE::CAR,
    //         std::make_shared<Permit>(
    //             "CC4567",
    //             122,
    //             PERMITTYPE::OWNED)));

    // data.push(
    //     std::make_shared<TouristVehicle>(
    //         "UP15BR0773",
    //         2,
    //         80.5f,
    //         TOURISTVEHICLETYPE::BIKE,
    //         std::make_shared<Permit>(
    //             "INDIA",
    //             97,
    //             PERMITTYPE::OWNED)));

}

// std::optional<Container> printFirstNInstanceWithMatchingInstance(const Container &data, unsigned int N)
// {

//     if ((int)N <= 0 || (int)N > data.size())
//     {
//         throw invalidNValueException("N value is not valid !! \n");
//     }

//     if (data.empty())
//     {
//         throw dataEmptyException("Data is empty !! \n");
//     }

//     Container actual_result{f1};
//     Container temp = data;                // NOT TO DELETE ORIGINAL ONE !!
        
//     while(!temp.empty()){
//         if(temp.top()->seatCount() >=4 && temp.top()->permit()->permitType() == PERMITTYPE::LEASE){
//             actual_result.push(temp.top());
//         }
//         temp.pop();
//     }

//     if(actual_result.size() < N){
//         return std::nullopt;
//     }

//     return actual_result;
//     // std::copy_if(
//     //     data.top(),
//     //     data.empty(),
//     //     std::inserter(matching_instances, matching_instances.top()),
//     //     [](const TouristVehiclePtr& ptr){
//     //         return ptr->seatCount() >=4 && ptr->permit()->permitType() == PERMITTYPE::LEASE;
//     //     }
//     // );
              

// }

// float AveragePerHourBookingCharges(const Container &data)
// {
//     if(data.empty()){
//         throw dataEmptyException("Data is empty - not calc average !! \n");
//     }
    
//     TouristContainer enteries;
//     Container temp = data;

//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     float total = std::accumulate(
//         enteries.begin(),
//         enteries.end(),
//         0.0f,                                                              // Return type !!
//         [](float current_upto_point, const TouristVehiclePtr& ptr){
//             return current_upto_point + ptr->perHourBookingCharges();
//         }
//     );

//     int count = enteries.size();
//     return total / static_cast<float>(count);

// }

// float MaxPerHourCharges(const Container &data)
// {
//     // Always initialise the variable to any value....[ IMPORTANT ]
//     if (data.empty())
//     {
//         throw dataEmptyException("Nothing is found in the container or it is empty !!");
//     }

//     TouristContainer enteries;
//     Container temp = data;

//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     auto itr1 = std::max_element(
//         enteries.begin(),
//         enteries.end(),
//         [](const TouristVehiclePtr& p1, const TouristVehiclePtr& p2){
//             return p1->perHourBookingCharges() < p2->perHourBookingCharges();
//         }
//     );

//     return (*itr1)->perHourBookingCharges();

// }

// TouristContainer printFirstNFunctionalitiesNormal(Container &data, unsigned int N)
// {
//     if (data.empty())
//     {
//         throw dataEmptyException("Data is empty yaar !! \n");
//     }

//     if ( (int)N <= 0 || (int)N > data.size())
//     {
//         throw invalidNValueException("Number of required facilities is invalid !! \n");
//     }

//     TouristContainer enteries;
//     TouristContainer result;

//     Container temp = data;
//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     std::copy_n(
//         enteries.begin(),
//         N,
//         std::inserter(result, result.begin())
//     );

//     return result;
// }

// bool AreContainerInstanceOfSamePermitType(Container& data){
//     if (data.empty())
//     {
//         throw dataEmptyException("Data is empty yaar !! \n");
//     }

//     // PERMITTYPE type = data.front()->permit()->permitType();
//     PERMITTYPE type = data.top()->permit()->permitType();

//     TouristContainer enteries;
//     Container temp = data;

//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     bool ans = std::all_of(
//         enteries.begin(),
//         enteries.end(),
//         [&](const TouristVehiclePtr& ptr){
//             return ptr->permit()->permitType() == type;
//         }
//     );

//     return ans;
// }

// std::size_t CountCabType(Container& data){
//     if(data.empty()){
//         throw dataEmptyException("Data empty -- no cab type !!\n");
//     }

//     TouristContainer enteries;
//     Container temp = data;
//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     std::size_t total = std::count_if(
//         enteries.begin(),
//         enteries.end(),
//         [](const TouristVehiclePtr& ptr){
//             return ptr->vehicleType() == TOURISTVEHICLETYPE::CAR;
//         }
//     );

//     return total;
// }

// std::optional<PermitPtr> FindPermitById(Container &data, std::string id)
// {
//     if(data.empty()){
//         throw dataEmptyException("data empty -- no permit id !! \n");
//     }

//     TouristContainer enteries;
//     Container temp = data;
//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     auto itr = std::find_if(
//         enteries.begin(),
//         enteries.end(),
//         [&](const TouristVehiclePtr& ptr){
//             return ptr->permit()->serialNumberOfPermit() == id;
//         }
//     );

//     if(itr == enteries.end()){
//         return std::nullopt;
//     }
//     return (*itr)->permit();
// }

// int LastNMaxSeatCount(Container &data, unsigned int N)
// {
//     if(data.empty()){
//         throw dataEmptyException("data empty -- no permit id !! \n");
//     }

//     if( (int)N <= 0 || (int)N > data.size() ){
//         throw invalidNValueException("N value is invalid \n");
//     }

//     TouristContainer enteries;
//     Container temp = data;
//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     auto itr = enteries.begin();
//     std::advance(itr, data.size()-N);

//     auto itr1 = std::max_element(
//         itr, 
//         enteries.end(),
//         [](const TouristVehiclePtr& ptr1, const TouristVehiclePtr& ptr2){
//             return ptr1->seatCount() < ptr2->seatCount();
//         }
//     );

//     return (*itr1)->seatCount();

// }

// std::list<float> CalculateGST(Container &data, std::function<float(const TouristVehiclePtr& ptr)> fn)
// {
//     if(data.empty()){
//         throw dataEmptyException("data empty -- no permit id !! \n");
//     }

//     TouristContainer enteries;
//     Container temp = data;

//     while(!temp.empty()){
//         enteries.push(temp.top());
//         temp.pop();
//     }

//     std::list<float> result;
//     std::transform(
//         enteries.begin(),
//         enteries.end(),
//         std::inserter(result, result.begin()),fn );

//     return result;
// }

