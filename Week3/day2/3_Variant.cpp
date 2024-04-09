#include"Employee.h"
#include"BusinessOwner.h"
#include<iostream>
#include<memory>
#include<list>
#include<variant>


using EmpPtr = std::shared_ptr<Employee>;
using BusinessPtr = std::shared_ptr<BusinessOwner>;

using vType = std::variant<EmpPtr, BusinessPtr>;

using Container = std::list<vType>;

void CreateObject(Container& data){

    data.push_back(
        std::make_shared<Employee>("Dev", 150000.0f)
    );

    data.push_back(
        std::make_shared<BusinessOwner>("Aadi", 150000.0f, 122400.0f)
    );

    data.push_back(
        std::make_shared<Employee>("Satyam", 250000.0f)
    );

}

/*
    A function to print revenue of all BusinessOwner from the data
*/

void showRevenue(Container& data){
    for(vType& v : data){
        if(std::holds_alternative<BusinessPtr>(v)){
            std::cout << std::get<1>(v)->revenue();
                // get < 1 >  -----> 1 is a index of Business in variant...
        }
    }
}

void AverageRevenueOfBusinessOwner(Container& data){

    if(data.empty()){
        throw std::runtime_error("Data is empty now !!");
    }
    // If we are using array, then we don't have to check above condition...
    // Because array never be empty because when we declare an array we passed the size as arguments...

    float total_revenue = 0.0f;
    std::size_t counter = 0;
    for(vType& v: data){
        // Use BusinessPtr because variant contains BusinessPtr as name...

        if(std::holds_alternative<BusinessPtr>(v)){
            total_revenue+= std::get<1>(v) -> revenue();
            counter++;
        }
    }

    if(counter == 0){
        throw std::runtime_error("No data is found - average not calculate \n");
    }
    std::cout << "Average revenue is : " << total_revenue/ static_cast<float>(counter) << std::endl;
}

void IsAllEmployeeSalaryAbove60K(Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty sir !! \n");
    }

    bool flag = true;
    for(vType& v: data){
        if(std::holds_alternative<EmpPtr>(v)){
            if(std::get<0>(v) -> salary() < 60000.0f){
                flag =  false;
                break;
            }
        }
    }

    std::cout << "Status check complete : " << std::boolalpha << flag << std::endl;
}

/*
    With variants, we are performing functional polymorphism !! 
*/
int main(){
    Container data;
    CreateObject(data);
    showRevenue(data);

    AverageRevenueOfBusinessOwner(data);
    IsAllEmployeeSalaryAbove60K(data);
}
