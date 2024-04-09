/*

    I want to design an adapter that accepts 
        a) A vector of integers
        b) A logic that works on a single item at a time..
            This logic should "filter" the input data and only display value which
                satisfy the requirements of the logic

                Eg : From a vector of 1,2,3,4,5 logic of "even numbers" should only display
                        2
                        4


*/

#include<iostream>
#include<functional>

//  Filtration is based on the condition : so the data type is bool....[ bool is a type of lambda function here]
// void Adaptor(const std::vector<int>&data, std::function<void(int)> fn){}

void Adaptor(const std::vector<int>&data, std::function<bool(int)> fn){
    for(int val: data){
        if( fn(val) ){
            std::cout << val << "\n";
        }
    }
}
int main(){
    Adaptor(std::vector<int>{1,2,3,4,5,6,8}, 
        [] (int number) { return number % 2 == 0; }
    );
}
