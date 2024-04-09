/*
    Container of Employees
        -id, name , salary

    A function that returns a container of all Employess with salary above 50000.0f

        -Scenario 1: Input data is not valid   (exception)

        -Scenario 2: Input is valid atleast 1 employee above 50K salary exists !!
            -Make a result container , push employee into result and return result

        -Scenario 3: Input is valid but no employee has salary above 50K
            // MAY OR MAY NOT RETURN A VALUE

            -We return an empty result container...
                But this is also not a good practise..[ Risk in chaining problem ]

            -throw an exception for No Matching Instance found !!
                - Is it really a exception ?

*/

#include"Employee.h"
#include<vector>
#include<optional>
#include<memory>

using Container = std::vector<std::shared_ptr<Employee>>;

void CreateObject(Container& data){
    data.push_back(
        std::make_shared<Employee>("Rana",32500.0f)
    );

    data.push_back(
        std::make_shared<Employee>("Sourav",62500.0f)
    );

    data.push_back(
        std::make_shared<Employee>("Sumanth",22500.0f)
    );
}

std::optional<Container> FindAbove50KEmployee(Container& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty \n");
    }

    Container result;
    for(std::shared_ptr<Employee>emp : data){
        if(emp->salary() > 50000.0f){
            result.push_back(emp);
        }
    }

    if(result.empty()){
        return std::nullopt;    // nothing to show , nothing to return... 
                                // [ now change function return value is std::optional<Container> ]
    }

    return result;
}

int main(){
    Container data;
    CreateObject(data);

    std::optional<Container> result = FindAbove50KEmployee(data);

    // std::cout << "Size of result is : " << result.size() << std::endl;   // Gives error

    if(result.has_value()){                           // Confirm result has a value or not ?  --> bool type
        Container actual_value  = result.value();      // [ value - return the value ]
    }
    else{
        // data nahi mila...ab jo krna h kro
        std::cout << "Data not found according to this condition \n";
    }
}


/*
    Lazy Evaluation : 

    
*/
