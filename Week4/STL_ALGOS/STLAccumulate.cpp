// Total of employee salary for all instances in the container
// For example :     50K   20K  30K  40K  12K
// Operation is our's choice : addition/subtraction/multiplication/division/mod etc..

#include <algorithm>
#include <numeric> // For using accumulate...
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

    // Binary arguments takes two parameters :
    // Parameter 1 : Answer upto current point
    // Parameter 2 : Next value...

    auto fn = [](float answer_upto_current_point, const EmpPtr &emp){
                                              return answer_upto_current_point + emp->salary();
    };

                                          
    float final_answer1 = std::accumulate(data1.begin(), data1.end(), 0.0f,
                                          [](float answer_upto_current_point, const Employee &emp)
                                          {
                                              return answer_upto_current_point + emp.salary();
                                          });

    float final_answer2 = std::accumulate(data2.begin(), data2.end(), 0.0f,
                                          [](float answer_upto_current_point, const Employee* emp)
                                          {
                                              return answer_upto_current_point + emp->salary();
                                          });

    // float final_answer3 = std::accumulate(data3.begin(), data3.end(), 0.0f,
    //                                       [](float answer_upto_current_point, const EmpPtr &emp)
    //                                       {
    //                                           return answer_upto_current_point + emp->salary();
    //                                       });

    // We can replace lambdas by other functions....
    float final_answer3 = std::accumulate(data3.begin(), data3.end(), 0.0f, fn);

    // NOTE : IF WE HAVE ALREADY OPERATOR OVERLOAD, THEN WE DON'T HAVE TO PASS THE LOGIC AGAIN.....



    std::cout << final_answer1 << std::endl;

    std::cout <<  final_answer2 << std::endl;

    std::cout << final_answer3  << std::endl;
}
