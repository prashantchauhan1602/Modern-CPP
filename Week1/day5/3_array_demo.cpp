
/*

    STL is like an illusion ...
    Array offset = base address + (i * sizeof(data_type))
        0000 0000
        0000 0000
        0000 0000
        0000 1010

*/


/*
    Operations: 
        1. FirstItem
        2. LastItem
        3. Access Random positioned item
        4. Access something based on label
        5. Add element

        6. Remove an element                 [At least make people beleive that]
            You don't delete anything from RAM....[always remember]
            It may be overwrite
*/

/*

MAP : 
    To access the element N, you need label/key of N

        hashing mechanism - std::unordered_map
        self-balancing tree : std::map

ITERATORS : 
    They are abstraction over pointers to elements in a container
*/


#include<iostream>
#include<array>

template <typename T>
// using Array = std::array<int, 5>;
using Array = std::array<T, 5>;

template <typename T>
void insert(Array<T>& data, const int poisition , const int val){
    data[poisition] == val;
}

template <typename T>
void Display(const Array<T>& data){
    // Technically, we have to write auto = Array<T>::iterator 
    // This - rbegin()/ rend() / ++ operator are written inside iterator class..
    
    for(auto itr =  data.begin(); itr!=data.end(); ++itr)
    {
        std::cout << *itr << "\n";
    }

    std::cout << "\n";

    for(auto itr =  data.rbegin(); itr!=data.rend(); ++itr)
    {
        std::cout << *itr << "\n";
    }
}

template <typename T>
int FindElementAtIndexN(const Array<T>& data, unsigned int N){
    return data[N];
}

int main(){}
