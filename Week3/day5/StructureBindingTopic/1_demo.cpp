#include<iostream>
#include<array>

bool IsEven(int number){
    return number % 2 == 0;
}

std::array<int, 5> makeValues(){
   return std::array<int,5>{1,2,3,4,5};
}

int main(){
    std::cout << "Hello  \n";

    // bool ans = IsEven(13);                              // ans is not used in our code again...[ memory ]
    if(bool ans = IsEven(13); ans){                        // Optimised version...
        std::cout << "Number is even\n";
    }
    else{
        std::cout << "Not even\n";
    }

    for(int i=0;i<10;i++){
        std::cout << i*i << std::endl;
    }

    if( std::array<int,5>result = makeValues() ; result[0] > -1){
        std::cout << result.back();
    }
    else{
        std::cout << "Array has negative values : " << result.front() << std::endl;
    }
}
