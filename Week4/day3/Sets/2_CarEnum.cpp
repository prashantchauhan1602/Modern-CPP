#include<iostream>
#include<vector>
#include<unordered_set>

enum class CarType{
    HATCHBACK=1,
    SEDAN,
    SUV
};

// Homework !!
std::ostream& operator<<(std::ostream& os, const CarType& vt){
    if(static_cast<int>(vt) == 1){
        os << "HATCHBACK\n";
    }
    if(static_cast<int>(vt) == 1){
        os << "SEDAN\n";
    }
    if(static_cast<int>(vt) == 1){
        os << "SUV\n";
    }
    return os;
}

int main(){
    std::vector<CarType> types{CarType::HATCHBACK, CarType::HATCHBACK, CarType::SEDAN, CarType::SUV};

    std::unordered_set<CarType> data {types.begin(), types.end()};

    for(const CarType& tp : data){
        std::cout << tp << std::endl;
    }
}
