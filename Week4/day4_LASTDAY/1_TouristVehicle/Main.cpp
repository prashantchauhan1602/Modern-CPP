#include <iostream>
#include "TouristVehicle.h"

#include "invalidNValueException.h"
#include "dataEmptyException.h"
#include"QueuePriority.h"

// #include "Functionality.h"
// #include"MapFunctionality.h"


int main()
{
    // Container data;           // LIST !!

    // Container data;          // UNORDERED_MAP !!

    Container data(f1);
    TouristContainer tourist_data;

    createObjects(data);
    // try
    // {
        // std::optional<Container>  f1_res = printFirstNInstanceWithMatchingInstance(data, 2);
        // if (f1_res.has_value())
        // {
        //     TouristContainer res;
        //     Container res_f1 = f1_res.value();

        //     while( !res_f1.empty() ){
        //         res.push_back(res_f1.top());
        //         res_f1.pop();
        //     }

        //     for (TouristVehiclePtr ptr : res)
        //     {
        //         std::cout << *ptr << std::endl;
        //     }
        // }

        // float f2_ans = AveragePerHourBookingCharges(data);
        // std::cout << "Average per hour charges is : " << f2_ans << std::endl;

        // float f3_ans = MaxPerHourCharges(data);
        // std::cout << "Max per hour charges is : " << f3_ans << std::endl;

        // TouristContainer res =  printFirstNFunctionalitiesNormal(data, 3);
        // for (TouristVehiclePtr ptr : res)
        // {
        //     std::cout << *ptr << std::endl;
        // }

        // if(bool ans = AreContainerInstanceOfSamePermitType(data);ans){
        //     std::cout << "All container of same type \n";
        // }
        // else{
        //     std::cout << "All container are not of same type \n";
        // }

        // std::size_t f4_ans = CountCabType(data);
        // std::cout << "Total count of CAR type is : " << f4_ans << std::endl;

        // std::optional<PermitPtr> f5_ans =  FindPermitById(data,"CC4567");
        // if(f5_ans.has_value()){
        //     PermitPtr final_ans = f5_ans.value();
        //     std::cout << *final_ans << std::endl;
        // }

        // int f6_ans = LastNMaxSeatCount(data, 3);
        // std::cout << "From last max seat count is : " << f6_ans << std::endl;

        // std::list<float> f7_ans = CalculateGST(data, [](const MapEntry & ptr){
        //     return ptr.second->seatCount()*2;
        // });

        // auto itr = f7_ans.begin();
        // while( itr != f7_ans.end()){
        //     std::cout << *itr << std::endl;
        //     *itr++;
        // }
    // }
    // catch (dataEmptyException &ex)
    // {
    //     std::cout << ex.what();
    // }

    // catch (invalidNValueException &ex)
    // {
    //     std::cout << ex.what();
    // }

    // catch (...)
    // {
    //     std::runtime_error("Last vali run time error !! \n");
    // }
}
