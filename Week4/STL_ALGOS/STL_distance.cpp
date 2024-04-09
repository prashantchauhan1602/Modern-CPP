/*

    QUES : IF I FOUND AN ELEMENT, THEN ONE QUESTION COMES IN OUR MIND IS ? 
        I   IN WHICH POSITION DATA IS FOUND ?

    ANS : IT IS EASY IN MOST CASES BY USING INDEXES, BUT IN LIST THERE IS NO INDEXES..

    EXAMPLE:    11   19   14    21   16    27    48
        FIND THE NUMBER WHICH IS DIVISIBLE BY 3 ( EXPECTED ANSWER IS : 21 )

    DISTANCE = BEGIN_ITERATOR  -------------------------------> END_ITERATOR


    BUT HERE AUTO CAN BE REPLACED BY : 
    auto = std::vector<int>::iterator

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [](int number){ return number % 3 == 0 ;}
    );

    FIRSTLY CHECK THE CONDITION :
    if(itr != data.end()){
        std::cout << std::distance(data.begin(), itr);
    }
    


*/

#include"Functionality.h"
#include<algorithm>
int main(){

    EmployeeSmartPointerContainer data;
    CreateObjects(data);

    std::string _name = "Anchal";
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const EmpPtr& ptr){ return ptr->eName() == _name ;}
    );

    if(itr != data.end()){
        int dist = std::distance(data.begin(), itr);
        std::cout << "Distance is : " << dist << std::endl;
    }

}
