#include<iostream>
#include<vector>
#include<functional>

void square(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty !! \n");
    }

    // for each integer called "val" in data, calculate square of val
    for(int val: data){
        std::cout << val*val << "\n";
    }
}

void cube(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("Data is empty !! \n");
    }

    // for each integer called "val" in data, calculate square of val
    for(int val: data){
        std::cout << val*val*val << "\n";
    }
}

/*
    Adaptor or Middleware :
            Adaptor (   data ,    logic   )

            Adaptar is a function which takes 2 parameters
                a) Constant lvalue reference to a std::vector of integers
                b) A function wrapper which wrap a function of following signature
                    - accept one const lvalue reference to a vector of integers
                    - return void

            Adaptar also returns void

    This logic will run if the signature of function is same....
    like return type is void 
    input : const std::vector<int>& 

*/



// But C language only have function pointer, So, it is not working properly. 
    // That's why we have to use Wrapper class/function...


// void Adaptor( const std::vector<int>& data,  void (*logic) (const std::vector<int>&)){
//     if(data.empty()){
//         throw std::runtime_error("Data is empty !!\n");
//     }

//     (*logic)(data);
// }


/*Now, this function accepts all type of function which have same signature as :
    void (const std::vector<int>&)*/

void Adaptor( const std::vector<int>& data, std::function<void (const std::vector<int>&)> fn){
    if(data.empty()){
        throw std::runtime_error("Data is empty !!\n");
    }

    fn(data);
}
 

int main(){
    // square(std::vector<int>{1,2,3,4,5});

    // Function can be passed as function pointers...
    // Adaptor(std::vector<int>{1,2,3,4,5}, &square);

    // Function pointers...
    // void cube(const std::vector<int>& data)      [ Copy signature ]

    void (*ptr) (const std::vector<int>&) = &cube;
    void (*ptr2) (const std::vector<int>&) = &square;

    // Calling will be same for function pointer and this template function type adaptor..
    Adaptor(std::vector<int>{1,2,3,4,5}, &cube);     
 

}

/*
    BMW: Workshop Engineers 
            ----> diagnostics

                    ---> Function (carUnit, logic_for_diagnosis)

*/

/*
    In Javascript : 
        Map ----> filter ----> reduce    [ Functional programming ]

    In Python : 
        ans = list(map( lambda number : number*number, [1,2,3,4,5]))
        print(ans)
*/



