/*  
    max_element or min_element   ---------------> return the position
    max or min        --------------------------> returns the value 
*/
#include"1_employee.h"
#include<numeric>
#include<algorithm>
#include"Functionality.h"

int main(){
    
    StackEmployeeContainer data1;
    CreateObjects(data1);
    auto itr = std::max_element(
        data1.begin(),
        data1.end(), 
        [](const Employee& emp1, const Employee& emp2){ return emp1.salary() < emp2.salary();}
    );

    auto itr1 = std::min_element(
        data1.begin(),
        data1.end(), 
        [](const Employee& emp1, const Employee& emp2){ return emp1.salary() < emp2.salary();}
    );

    // NOTE : USE ( < ) SIGN IN COMPARISON BECAUSE SOME COMPILER MAY CREATE PROBLEMS IN ( > ) SYMBOL ...

    // Position of max !! 

    // Example : Print name of employee whose salary is maximum...
    std::cout << (*itr).eName() << std::endl;
    std::cout << (*itr1).eName() << std::endl;
    
}
