#include<iostream>


/*
    Scenario 1:  Design function so that it accept both lvalue and rvalue. 
    Lvalue should be copied and rvalue should be assigned
    Value will be modify
    
    rvalue : 10 is assigned to value in F1 stack memory
    lvalue : n1 is created in main (4 bytes). Then its copied into stack memory of function F1 and assigned the name "value"
    Call by value situation...

*/
void F1(int value){
    std::cout<<value*value;
    // value = 99    [will work]
}

/*
    Scenario 2:  Design function so that it accept both lvalue and rvalue. 
    Lvalue should be copied and rvalue should be assigned
    Value should not be modifiable
    
    rvalue : 10 is assigned to value in F1 stack memory
    lvalue : n1 is created in main (4 bytes). Then its copied into stack memory of function F1 and assigned the name "value"
*/
void F2(const int value){
    std::cout << value*value;
    // value = 99;       [not work]
}


/*
    Scenario 3 : Accept lvalues only. Rvalues are not allowed 
    Value should be modifyable in the function...

    n1 is created in main function. Then copied into F3 with the name "Value"
    Value is modifyable..
    However memory is exactly the same..

    Call by : It takes non-const integer lvalue reference returns void
*/

void F3(int& value){
    std::cout << value*value;
}

/*
    Scenario 4: Accept rvalues only (by assignment). Value should be modifyable
    No lvalues...
    [Not possible in basic C++ / only in Modern CPP]

    Reading method : accepts one non-const rvalue references and returns void
*/

// Rvalue reference : (int&& value)
void F4(int&& value){
    std::cout<<value*value<<std::endl;
    value=11;
}

/*
    Scenario 5: I want lvalues and rvalues both.. Value to not be modifyable
    Lvalues should be taken by reference....[like scenario 2]

    Nowadays not used...
*/

void F5(const int& value){
    std::cout << value*value;
    //value = 11;       // not allowed
}

/*
    Scenario 6: Accept rvalues only (by assignment). Value should not be modifyable
    No lvalues...
    [Not possible in basic C++ / only in Modern CPP]
    [Similar to scenario 4 but value should not be modifyable]

    Reading method : accepts one non-const rvalue references and returns void
*/

void F6(const int&& value){
    std::cout<<value*value<<std::endl;
    //value=11;      // not allowed
}

int main(){
    int n1 = 10;
    F1(10);
    F1(n1);


    F2(10);
    F2(n1);

    F3(n1);
    //F3(10);      // not allowed

    F4(10);        // (temporary data which is not present in main stack memory.. Directly assigned to F4)
    //F4(n1);     // not allowed

    F5(10);
    F5(n1);

    F6(10);
    //F6(n1);      //not allowed
}
/*
    class Employee(){.......}

    int main(){

        Employee e1{};
        Employee e2{e1}  OR Employee e2{ Employee {}}

        Employee e2{e1} = Copy constructor
        Employee e2{ Employee {}} = Move constructor [because rvalues passed]
    }
*/
