/*
                                       ADVANCE ALGORITHM Vs NEXT ALGORITHM : 
    
    ADVANCE ALGORITM : 
        It doesn't return anything...
        IN FIRST ARGUMENT, WE HAVE TO PASS LVALUE REFERENCE
        INPUT TAKE BY ITERATOR BY REFERENCE AND UPDATE IT AND RETURNS THE SAME ITERATOR !!

    NEXT ALGORITHM :
        IT DOESN'T TAKE THE VALUE BY RVALUE OR LVALUE REFERENCE !! 
        IT RETURNS AN ANOTHER ITERATOR OR COPY OF AN ITERATOR

*/


#include<iostream>
#include<algorithm>
#include<vector>

int main(){
    std::vector<int> data{11, 19, 14, 17, 21, 16, 28};

    // First number divisible by 7 amongest last 3 integer in input !! 

    // In this code, we have to move our initial iterator to 3rd last element...
        // Beginning iterator :     (N + 3)th element...

    // std::advance(data.begin(), data.size() - 3);

    auto itr = data.begin();
    std::advance(itr, data.size()-3);

    std::vector<int>::iterator result = std::find_if(
        itr,
        data.end(),
        [](int number){ return number % 7 == 0;}
    );

    if(result != data.end()){
        std::cout << "Divisible by 7 amongest last 3 elements are : " << *result << std::endl;
    }
    
}
