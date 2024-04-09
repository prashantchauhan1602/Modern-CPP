#include<iostream>

class Wrapper
{
private:
    int* m_values;
    std::size_t m_size;
public:
    Data() = delete;
    ~Data(){
        delete m_values;
    }
};


template <typename> T
class Wrapper{
private:
    T* m_ptr;

public: 
};

/*
    1) Destructor is alwayst triggered just before object is destroyed..
            It means we have to make destructor here...

        Step a) I will make one object of Class Data
                
                [     10           20             30     ]
                
                [0x100H      |    3 ]

        Step b) This object's pointer will be saved in wrapper inside _mptr

        Step c) When wrapper object goes out of scope, destructor of wrapper will be called...
                        delete data objects...

        Step d)Since delete was called on a class type, 
            destructor of this particular class will also be called...
*/

