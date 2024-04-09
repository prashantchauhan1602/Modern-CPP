#include<iostream>
#include<functional>

// Lambdas and its Types : 

void Wrapper(){

    int _first = 30;
    int _second = 25;

    auto f1 = [&](){
        std::cout << _first* _second << std::endl;
    };
}

int main(){
    Wrapper();
}
