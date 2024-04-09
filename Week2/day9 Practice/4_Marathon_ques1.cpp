#include<iostream>
#include<functional>
#include<vector>

using FnType = std::function<void(std::string)>;
using FnContainer = std::vector<FnType>;


void Is3Vowels(std::string str){
    std::cout << "1\n";
    std::cout << str << std::endl;
    if(str.size() < 3 || str.empty()){
        throw std::runtime_error("Size is less than 3 or empty !! ");
    }

    int counter{0};
    std::string vowels = "aeiouAEIOU";
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(vowels.find(ch)){
            counter++;
        }
    }

    if(counter >= 3){
        std::cout << "String contain atleast 3 vowels !!\n";
    }
    else{
        std::cout << "Not enough vowels !!\n"; 
    }
}

void StartWithCPP(std::string str){
    std::cout << "2\n";
    std::cout << str << std::endl;
    if(str.size() < 3){
        throw std::runtime_error("String size is less than 3 \n");
    }

    if(str[0] == 'C' && str[1] == '+' && str[2] == '+'){
        std::cout << "Starts with C++\n";
    }
    else{
        std::cout << "Not start with C++\n";
    }
}

void PrintLastThreeCharacters(std::string str){
    std::cout << "3\n";
    std::cout << str << std::endl;
    if(str.size() < 3){
        throw std::runtime_error("Invalid input as size is less than 3 \n");
    }

    int index = str.size()-1;
    int range = 3;
    while(range){
        std::cout << str[index--];
        range--;
    }
}

void PrintFirstTwoCharOnCondition(std::string str){
    std::cout << "4\n";
    std::cout << str << std::endl;
    if(str.size() < 2){
        throw std::runtime_error("Unable to verify as the length is less than 2 \n");
    }

    if(str[0] == 'a' || str[0] == 'b'){
        std::cout << "Length of " << str << " is :"<< str.size() << std::endl;
    }

    else if(str[0] == ' '){
        std::cout << "Invalid Input \n";
    }
    else{
        std::cout << str[0] << str[1] << std::endl;
    }
}

void PrintConsecutiveTwoChars(std::string str){
    std::cout << "5\n";
    std::cout << str << std::endl;
    if(str.size() < 2){
        throw std::runtime_error("String size is less than 2 \n");
    }

    char ch = ' ';
    int lastIdx = str.size()-1;

    for(int i=1;i<lastIdx;i++){
        if(str[i] == str[i-1]){
            ch = str[i];
            break;
        }
    }

    if(ch != ' '){
        std::cout << ch << ch << std::endl;
    }
    else{
        std::cout << str[lastIdx] << str[lastIdx-1] << std::endl;
    }
}

void Adaptor(std::vector<std::string>&data, FnContainer& fns)
{
    for(int i=0;i<fns.size();i++){
        fns[i](data[i]);
    }
}


int main(){
    std::vector<std::string> data{ "Mohan", "Satyam", "Prashant", "FuckFuck", "Ohhyess"};
    FnContainer fns{
        Is3Vowels,
        StartWithCPP,
        PrintLastThreeCharacters,
        PrintFirstTwoCharOnCondition,
        PrintConsecutiveTwoChars
    };

    Adaptor(data, fns);
}
