/*
    int arr[3];
    int[] arr = new int[3];

    Default choice will be :  stl array
*/

#include<iostream>
#include<array>

// Paas an array to a function...(By reference )

void Magic(std::array<int,5>& arr){
    // Iterator type : std::Array<int,5>& arr;       [ Replacement of auto ]
    // Iterator is inside the class Array..
    for(auto itr=arr.begin(); itr=arr.end();++itr){
        std::cout << *itr << "\n";
    }

    // Reverse iterator
    for(std::array<int,5>:: reverse_iterator itr =arr.rbegin(); itr!=arr.rend();++itr){
        std::cout << *itr << "\n";
    }

    // Cbegin and Cend();
    for(auto itr=arr.cbegin(); itr=arr.cend();++itr){
        std::cout << *itr << "\n";
        *itr = 10;                                   // [ Gives an error now]
    }
}

int main(){
    // Syntax : std::array<int, size> arr;
    std::array<int, 5> arr{0};                             // int arr[5];

    // Arrays are accessed by index...

    arr[0] = 10;

    std::cout << arr[0] << "\n";
    std::cout << arr.front() << "\n";


    

}

/*
    Find features of array...
        You have to use arr and dot ---> choose from suggestions


    front : access first item in container by reference 
    back : access to last item in container by reference 

    begin() : iterator to first item in contaniner
    end() : iteratof to a non-valid locatoion outside of the limits of
        container memory

    cbegin() : iterator to the first item of the container
        THIS ITERATOR CANNOT BE DEFERENCED FOR WRITE OPERATION

    cend() : iterator to a non-valid location outside the container
        THIS ITERATOR CANNOT BE DEREFERNCED FOR WRITE OPERATION
*/
