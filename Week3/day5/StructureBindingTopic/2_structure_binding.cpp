/*

    
    THis feature will work when the size of Right Hand Side Data is fixed...
        Eg: Not work in vector
*/

#include<iostream>
#include<array>

int main(){
    std::array<int,2> data{101, 17};

    // Copy data[0] in employee_id
    // Copy data[1] in team_size

    auto [employee_id, team_size] = data;

    // Taking reference : 
    
    std::pair<int , std::string> info {101, "Prashant"};
    auto& [id_ref, name_ref] = info;

    std::cout << employee_id;
    std::cout << team_size;

    std::cout << id_ref ;
    std::cout << name_ref;
}
