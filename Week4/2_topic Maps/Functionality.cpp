#include<iostream>
#include<memory>
#include<unordered_map>
#include"Employee.h"

// KEY HAS A TYPE OF INT AND VALUE IS EMPLOYEE OBJECT...
using StackObjects = std::unordered_map<std::string, Employee>;
using RawPointerObjects = std::unordered_map<std::string, Employee*>;

using EmpPtr = std::shared_ptr<Employee>;
using SmartPointerObjects = std::unordered_map<std::string, EmpPtr>;


// DON'T USE COPY..... ITS ONLY WORK WITH RVALUE OR MOVE CONCEPT...
// PAIR ONLY SUPPORT MOVE SEMANTICS... 
// RETURN BY VALUE NHII CHALEGA....etc

/*
    Step 1: Choose key and value pair
    Step 2: Make a pair of key and value...
    Step 3: Move the pair into the unordered map
*/
void CreateObjects(StackObjects& data1){
    data1.emplace(
            std::make_pair(
            "emp1",
            Employee("emp1", "Prashant",45000.0f,22,"Pune")
        )
    );

    data1.emplace(
        std::make_pair(
            "emp2",
            Employee("emp2", "Dev", 55990.0f, 25, "Mumbai")
        )
    );

    data1.emplace(
        std::make_pair<std::string, Employee>(                      // !! GOOD PRACTICE
            "emp3",
            Employee("emp3", "Rana", 92500.0f,30,"Noida")
        )
    );

    // FOR TEMPLATE FUNCTION : PARAMETERS OF TEMPLATES CAN DEDUCE SINCE CPP 14
    // FOR TEMPLATE CLASS :  PARAMETERS OF TEMPLATES CAN DEDUCE SINCE CPP 20

    
}

void CreateRawPointerObjects(RawPointerObjects& data2){
    data2.emplace(
            std::make_pair(
            "emp1",
            new Employee("emp1", "Prashant",45000.0f,22,"Pune")
        )
    );

    data2.emplace(
        std::make_pair(
            "emp2",
            new Employee("emp2", "Dev", 55990.0f, 25, "Mumbai")
        )
    );

    data2.emplace(
        std::make_pair<std::string, Employee*>(          // Use * (asterik)    // !! GOOD PRACTICE
            "emp3",
            new Employee("emp3", "Rana", 92500.0f,30,"Noida")
        )
    );
}

template <typename T>
void Display(T& data){
    for(auto& [k,v] : data){                  // STRUCTURE BINDING
        std::cout << "key : " << k << " value : " << v << std::endl;
    }                                 
        

}
int main(){
    StackObjects data1;
    RawPointerObjects data2;

    CreateObjects(data1);
    CreateRawPointerObjects(data2);

    Display<StackObjects>(data1);
}

/*

    Sequential Containers:
        For example : list / vector / array etc...

    Container Adaptors
    Associative Container

    Unordered Associative Container :                             !! CPP REFERENCE...



    Do you want fixed size container ? 
        ------> Yes  [ ARRAY ]
        --------------------------------------> No
                                                |
                            Do you want to store data consecutively ?
                                --------> Yes  [ VECTOR ]
                                -----> NO
                                        |
                                        |
                            Do you want to traverse data sequentially
                                where Nth data is avail after N-1th data ?
                                ------> Yes    [ LIST ]
                                        |
                                        |
                            Do you want to store data with key and value pair ?
                                        NO
                                        |
                                        |
                            Do you want to store data in FIFO or LIFO Order ?
                                ---> YES [ STACK OR QUEUE ]
                                --> NO
                                    |
                                    |
                            Does order matter ?
                                Here, Unordered Associative Container comes into the picture...

*/


/*
    CONTAINER WHO USES HASH TABLE IN THE BACKEND DOESN'T GUARANTEE TO INSERT THE DATA IN SAME ORDER..

    IT DEPENDS ON HASH VALUE...
*/
