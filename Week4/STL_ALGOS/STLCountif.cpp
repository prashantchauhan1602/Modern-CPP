// Count If : The number of iterators as a count in the range [_first, last) for which pred(i) is true...
// Here for first : [_first ] is used -------> [ represent inclusive... and last) ---> represent exclusive


#include<algorithm>
#include"Functionality.h"

int main(){
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    CreateObjects(data2);
    CreateObjects(data3);

    ////////////////////////////////////////

    // INputIterator : Iterator that are used to use only one time...[ This iterator can't go back ]

    std::size_t size1 = std::count_if(data1.begin(), data1.end(), [](const Employee& emp){ return emp.salary() > 60000.0f; });
    std::size_t size2 = std::count_if(data2.begin(), data2.end(), [](const Employee* emp){ return emp->salary() > 60000.0f; });
    std::size_t size3 = std::count_if(data3.begin(), data3.end(), [](const EmpPtr& emp){ return emp->salary() > 60000.0f; });

    std::cout << size1 << std::endl;
    std::cout << size2 << std::endl;
    std::cout << size3 << std::endl;

}
