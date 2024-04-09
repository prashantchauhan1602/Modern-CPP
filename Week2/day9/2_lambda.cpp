/*

    Lambda functions : 

    Used when....
        1) Make function which have scoped...
        2) One time use only 

        
        1) A function which is a one time usable logic

        2) Normal top-level global function are stored in code segment
            They have global access level... I want to create local-scoped functions..

        3) Remove naming conflicts...

        4) Lambda are anonymous (without name)

    How to make ?

        Copy paste the same function...
        Remove the name of function...
        Remove return type from left....If you want 
            -> void (on the right)

        Put this whole in square brackets []


*/

#include<iostream>
#include<functional>
#include<algorithm>

// void square(int number){
//     std::cout << number * number ;
// }

void Adaptor(int number, std::function<void(int)> fn){
    fn(number);
}
int main(){
    // square(100);

    // Lambda function of square...
    // [](int number) -> void{
    // std::cout << number * number ;

    // Adaptor...
            // Paas this lambda function to adapter

    Adaptor(
        10,
        [](int number){           // [] total line -----> predicate
        std::cout << number * number ;
        }
    );

    std::vector<int> data{1,2,3,4,5,6,10};

    int ans = std::count_if(
        data.begin(),
        data.end(), 
        [] (int number ) {return number % 5 == 0 ;}
    );
    std::cout << "\n " << ans << "\n";
}
