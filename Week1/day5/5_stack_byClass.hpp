/*

    Variable replacement : fn + f2 --> write correct name --> shift + enter

    LIFO : Last inserted item must always be the first one to get out....

    STACK : FIXED OR DYNAMICALLY RESIZEABLE ?

    Internally for storing data, what would your data container ?   ---> Array/list....

*/

/*
    Shallow copy : It is like making alias for one to another  

    Deep copy : It creates an another data/array... in which the value of previous one is copied..
*/

/*
    Important !!

    We cannot write the member function of template type in (.cpp file)...
    
    We have to create all the member function inside the header (.h) file...
*/
#include<iostream>

template <typename T>
class Stack
{
private:
    T* _data {nullptr} ;                         // array is used as backend for my index
    int _m_top {-1};
    int m_size {0};
public:
    Stack() = default;

    Stack(const Stack<T>&);                    // Gives shallow copy
    Stack<T>& operator=(const Stack<T>&);

    Stack(const Stack<T>&&);
    Stack<T>& operator=(Stack<T>&&);             // stack<T>&    = changes

    ~Stack();

    Stack(T* elements, int size);    
    void push( T val );
    void pop();

    T peek();
    std::size_t Size();

    /*
        take two stacks... Add element of stack 2 (rhs) into stack1 (this)
    */
    void operator+(const Stack<T>& rhs);
};


// <---------------------------------   Functions ----------------------------------->

template <typename T>
inline Stack<T>::Stack(const Stack<T> &rhs)
{
    this->_m_top = rhs._m_top;
    this->m_size = rhs.m_size;

    // Create space for a total of "size" number of elements...
    _data = new T[ rhs.m_size ];


    for(int i=0;i<m_size;i++){
        this->_data[i] = rhs._data[i];
    }
}

// template <typename T>
// inline Stack<T> &Stack<T>::operator=(const Stack<T> &)
// {
//     // TODO: insert return statement here
// }

template <typename T>
inline Stack<T>::Stack(const Stack<T> &&)
{
    this->_m_top = rhs._m_top;
    this->m_size = rhs._size;

    // Create space for a total of "size" number of elements...
    _data = new T[ rhs._size ];


    for(int i=0;i<m_size;i++){
        this->_data[i] = rhs._data[i];
    }

// Only one change according to copy constructor
    return *this;
}

// template <typename T>
// inline Stack<T> &Stack<T>::operator=(Stack<T> &&)
// {
//     // TODO: insert return statement here
// }

template <typename T>
inline Stack<T>::~Stack()
{
    if(_data){
        delete[] _data;
    }
}

template <typename T>
inline Stack<T>::Stack(T *elements, int size)
{
    if(size <= 0){
        throw std::runtime_error("Size is not to be negative !! \n");                                            // Modified later
    }

    this->_data = new T[size];

    // now take data from user and insert into the stack
    for(int i=0;i<m_size;i++){
        this->_m_top++;
        this->_data[i] = elements._data[i];
    }

    this->m_size = size;
}

template <typename T>
inline void Stack<T>::push(T val)
{
    _m_top++;
    // if(_m_top >= size){
    //     throw "error \n";
    // }

    _data[_m_top] = val;
    this->m_size++;
}

template <typename T>
inline void Stack<T>::pop()
{
    if(this->m_size == 0){
        throw "error\n";
    }
    
    // this->_data[this->_m_top--];

    this->m_size--;
    this->_m_top--;
}

template <typename T>
inline T Stack<T>::peek()
{
    // if(_size == 0)
    if(_m_top == -1 || _data.size() == 0){
        throw std::runtime_error("Data is empty !! \n");
    }
    return _data[_m_top];
    // return T();
}

template <typename T>
inline std::size_t Stack<T>::Size()
{
    // return elements[elements.size()-1];
    return m_size;
    // return size_t();
}

template <typename T>
inline void Stack<T>::operator+(const Stack<T> &rhs)
{
}
