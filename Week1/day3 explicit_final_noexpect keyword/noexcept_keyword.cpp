#include<iostream>

void F1(int n) noexcept {
    int n1 = 10;
    std::cout << "Output is : " << n << std::endl;    
    
    // If there is a condition or assume : may be cout is fail...

    // According to my logic, exception nahi hoga yaha...
    // noexcept is used for guarantee that in my function, there is no exception...

    // But if any exception is found, then it will give an error during compilation...

    // After this, do not need of try catch block....(exception handling)


    // For eg : 
    // throw "error";

    
}

int main(){
    F1("10");
}
