#include<vector>
#include<iostream>

class Data{
private:
    int _id;
    std::vector<int> _readings;
    int* _extra_values;
    int _N;

public:
    Data(int id, std::vector<int>& readings,int* base, int n)
        : _id{id}, _readings{readings}, _N{n}{

            int* _extra_values = (int*) malloc(4*n);

            for(int i=0;i<n;i++){
                _extra_values[i] = base[i];
            }
        }

    // ~Data() = default;                       // [ Creates a problem ]

    ~Data(){
        delete[] _extra_values;
    }
    
};

int main(){
    try{
        int arr[3] = {40,50,60};
        Data* ptr = new Data(101, std::vector<int>{10,20,30}, arr, 3);
        std::cout << "Hello \n";

        // Do some operations...
        delete ptr;
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
    }
}


/*
    [ 40               50               60 ]           ----> extra values
    0x100H


    [ 101         |  std::vector<int>{10,20,30}    |   0x100H   | 3 ]
                                                        |
                                                        |
                                                    If this deletes, then value of this
                                                    still remains...

*/
