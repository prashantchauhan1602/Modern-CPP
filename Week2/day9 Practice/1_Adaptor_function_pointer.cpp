#include<iostream>
#include<functional>

void square(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }

    std::cout << "Square of all element is : \n";
    for(int i=0;i<data.size();i++){
        std::cout << data[i]*data[i] << std::endl;
    }
}

void cube(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }
    std::cout << "Cube of all element is : \n";

    for(int i=0;i<data.size();i++){
        std::cout << data[i]*data[i]*data[i] << std::endl;
    }
}

// Both function signature is same....

// void Adaptor(data,   typeOfLogic (*logic) )

void Adaptor(const std::vector<int>& data, void (*logic)(const std::vector<int>& data)){
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }

    (logic)(data);
}

// Using std::function instead of (void (*logic) ) in parameters...
// <-----------------------   Function wrapper  ----------------------------->
void Adaptor2(const std::vector<int>& data, std::function<void(const std::vector<int>& data)> fn){
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }
    
    fn(data);
}
int main(){

    // Create function pointers...
    void (*ptr1) (const std::vector<int>& data) = &square;
    void (*ptr2) (const std::vector<int>& data) = &cube;

    std::vector<int> arr { 2, 3, 4 , 5 , 6};

    
    Adaptor(arr, &cube);

    // C language supports only function pointers...So, it is not working properly...
    //That's why we have to use function wrappers or wrapper class..

    // Function wrapper example :
    Adaptor2(arr, &square);

    
}
