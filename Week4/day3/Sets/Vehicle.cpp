#include<iostream>
#include<unordered_set>
class Vehicle
{
private:
    std::string _id;
    float _price;
public:
    Vehicle() = default;
    Vehicle(const Vehicle &) = default;
    Vehicle &operator=(const Vehicle &) = delete;
    
    Vehicle(Vehicle &&) = default;
    Vehicle &operator=(Vehicle &&) = delete;
    
    ~Vehicle() = default;
    Vehicle(std::string id, float price): _id{id}, _price{price} {}

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }
};



int main(){
    Vehicle v1("v101", 32500.0f);
    Vehicle v2("v102", 48500.0f);
    Vehicle v3("v102", 62500.0f);

    // UNORDERED SET : 
    
    std::unordered_set<std::string> data;
    data.insert({v1.id(), v2.id(), v3.id()});

    for(const std::string& i : data){
        std::cout << i << std::endl;
    }
}


/*
    Ids :   v101, v102, v103, 101

    Objective : Find unique ids

    Process : Create 
*/
