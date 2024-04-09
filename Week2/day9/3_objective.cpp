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

bool Mod7(int number){
    return number % 7 == 0;
}

bool DivBy7_11(int number){
    return number % 7 == 0 && number % 11 == 0;
}

bool isPrime(int number){
    if(number == 0 || number == 1){
        return false;
    }

    if(number < 0){
        throw std::runtime_error("Negative number !! ");
    }

    for(int counter = 0; counter < number ; counter++){
        if(number % counter ==0){
            return false;
        }
    }
    return true;
}


short takeInput(){
    short choice{-1};
    std::cout << "Enter 0 for 7 & 11 check \n 1 for Mod \n 2 for Prime\n -1 if you want your filter\n";
    std::cin >> choice;
    return choice;

}

int main(){

    std::vector <std::function<bool(int)>> fns {
        Mod7, 
        DivBy7_11, 
        isPrime
    };

   

    // Adaptor(std::vector<int>{1,2,3,4,5,6,8}, 
    //     [] (int number) { return number % 2 == 0; }
    // );

    short choice = takeInput();
    if(choice == -1){
        Adaptor(std::vector<int>{1,2,3,4,5,6,8}, 
            [] (int number) { return number % 2 == 0; }
        );
    }

    else{
        Adaptor(
            std::vector<int>{4,5,6,7,8}, 
            fns[choice]
        );
    }
}
