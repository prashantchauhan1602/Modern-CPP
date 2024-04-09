// Dark series... what we know is a drop...what we don't know is an ocean..

#include<iostream>

int main(){
    int n1 = 10;
    float f1 = 10.3f;

    /*
        Integer n3 is assigned the result of float f1 
        value converted by cast to integer type

    */
    int n3 = (int) f1;      // C-style casting

    // C++ flavour : (static_cast)
    // Static cast : performs action at compile time..
    // If conversion fails, we get compile time error
    // NOT DESIGNED FOR POLYMORPHISM RELATED SITUATION...
    // small conversion/ rvalue conversion etc...

    // Syntax : data_type var_name = static_cast<data_type> (var_name2);  
    // [Use parentheses mandatory]
    int n4 = static_cast<int> (f1);

}
