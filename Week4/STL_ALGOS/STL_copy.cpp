/*
    Copy 
    Copy_n
    Copy based on condtion....
*/

/*
int main(){

    <--------------------- COPY_N --------------------------->

    StackObjects result;                !! destination

    // SYNTATICALLY CORRECT BUT LOGICALLY INCORRECT !!
    auto itr = std::copy_n(
        data.begin(),
        2,                                    // no of elements...
        result1.begin()
    );

    ERROR : terminated by signal SIGSEGV (Address Boundary Error) OR Segmentation fault
    SIGSEGV : Signal for Segmentation fault   ( check once !! )

    // BEST VERSION : 
    auto itr = std::copy_n(
        data.begin(),
        2,                                    // no of elements...
        std::inserter(result1, result1.begin())
    );

    if(result1.size() == 2){
        std::cout << "Element copied !! \n";
    }



    <-----------------------------  COPY_IF (pending)-------------------------------> 

    RETURNS ONE ELEMENT BEHIND THE LAST COPIED ELEMENT...

    Example : 11   19   14   17   21   28   16
        Find first number divisible by 3
            COPY_IF return itr of next to 21 element...

            IT ALSO DEPENDS ON KISMAT !!
            IF THERE IS ANY ELEMENT NEXT TO 21, THEN IT WILL GOOD FOR US...
                BUT IF NOT, THEN IT MAY RETURN END VALUE..


}

*/

#include"Functionality.h"
#include<algorithm>

int main(){
    StackEmployeeContainer data;
    CreateObjects(data);

    StackEmployeeContainer result;

    // Copy_n  ---> N is given by the user or by own...
    std::copy_n(
        data.begin(),
        2,                                    // no of elements...
        std::inserter(result, result.begin())
    );

    for(auto val : result){
        std::cout << val << std::endl;
    }

    // Copy_if 
    StackEmployeeContainer result1;
    std::copy_if(
        data.begin(),
        data.end(),                                    // no of elements...
        std::inserter(result1, result1.begin()),
        [](const Employee& emp){ return emp.age() > 20 ;}
    );

    for(auto val : result1){
        std::cout << val << std::endl;
    }
}

