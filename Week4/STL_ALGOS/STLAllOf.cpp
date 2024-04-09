// Returns a boolean to indicate if all instance satisfy condition or not !!
// Example : All employee having salary more than 60K

#include <algorithm>
#include "Functionality.h"

int main()
{
    StackEmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateObjects(data1);
    CreateObjects(data2);
    CreateObjects(data3);

    ////////////////////////////////////////

    // INputIterator : Iterator that are used to use only one time...[ This iterator can't go back ]

    bool flag1 = std::all_of(data1.begin(), data1.end(), [](const Employee &emp)
                             { return emp.salary() > 60000.0f; });
    bool flag2 = std::all_of(data2.begin(), data2.end(), [](const Employee *emp)
                           { return emp->salary() > 60000.0f; });
    bool flag3 = std::all_of(data3.begin(), data3.end(), [](const EmpPtr &emp)
                           { return emp->salary() > 60000.0f; });

    std::cout << flag1 << std::endl;
    std::cout << flag2 << std::endl;
    std::cout << flag3 << std::endl;
}
