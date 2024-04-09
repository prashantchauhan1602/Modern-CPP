#include<iostream>
#include<unordered_set>
#include<queue>
#include<memory>

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

    // PRIORITY QUEUE START HERE : 

    // FIRST SOLUTION :    (NOT WORKING)
    // using Vptr = std::shared_ptr<v1>;
    //         }; 
    // std::priority_queue(Vptr, std::vector(VPtr), decltype(f1) pq(f1));


    // PRIORITY QUEUE : 
    using Vptr = std::shared_ptr<Vehicle>;
    

    auto f1 = [](const Vptr& v1, const Vptr& v2){return v1->price() < v2->price() ;};                    // Comparator function...
    using Container = std::priority_queue<Vptr, std::vector<Vptr>, decltype(f1)>;
    Container pq(f1);

    Vptr v1 = std::make_shared<Vehicle>("v102",48500.0f);
    Vptr v2 = std::make_shared<Vehicle>("v103", 32500.0f);
    pq.push(v1);
    pq.push(v2);

    std::vector<Vptr> res;
    while(!pq.empty()){
        std::cout << "hello \n";
        res.push_back(pq.top());
        pq.pop();
    }

    for(Vptr ptr : res){
        std::cout << ptr->id() << "   " << ptr->price() << std::endl;
    }

}


/*
    Ids :   v101, v102, v103, 101

    Objective : Find unique ids

    Process : Create 
*/
