#include<iostream>
#include<memory>

class Data
{
private:
    int* m_values;
    std::size_t m_size;
public:
    Data(int* values, std::size_t size) 
    {
        int* m_values = (int*) malloc(4*size);

        for(int i=0;i<size;i++){
            m_values[i] = values[i];
        }
    }
    ~Data(){
        delete[] m_values;
    }
};



int main(){
    int arr[] = {1,2,3,4,5};

    // Purana code ko bhi ye dekh lega...
    try{
        std::shared_ptr<Data>sptr = std::make_shared<Data>(arr,5);
    }catch(std::exception& ex) { std::cout << ex.what() ;}
}

/*
    Whenever you want to create an object, then you have to use smart pointers...
        Espically shared_ptr :
            Because of easier syntax...
*/
