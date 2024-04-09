#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<iostream>
template<typename T>

class Queue
{
private:
    T* data {nullptr};
    int front {-1};
    int rear {-1};
    int m_size {0};

public:
    Queue() = default;

    Queue(const Queue<T>&) = delete;
    Queue<T>& operator=(const Queue<T>&) = delete;

    Queue(const Queue<T>&&) = delete;
    Queue<T>& operator=(const Queue<T>&&) = delete;

    ~Queue() = default;

    Queue(T* elements , int m_size);

    void insertData(T val);
    void deleteData();

    void top();
    void sizeQueue();

    bool isEmpty();

    void printQueue();


};
#endif // QUEUE_HPP

template <typename T>
inline Queue<T>::Queue(T* elements, int size)
{
    if(size <= 0){
        throw std::runtime_error("Size is not valid !! \n");
    }
    this->data = new T[size];

    for(int i=0;i<size;i++){
        this->data[i] = elements[i];
        this->rear++;
    }
    this->m_size = size;
}

template <typename T>
inline void Queue<T>::insertData(T val)
{
    this->rear+1;
    data[rear] = val;
    this->m_size+1;
}

template <typename T>
inline void Queue<T>::deleteData()
{
    if(m_size == 0 || front == rear){
        std::runtime_error("There in nothing to deleted !! \n");
    }
    this->front++;
    this->m_size--;
}

template <typename T>
inline void Queue<T>::top()
{
    if(m_size == 0){
        throw std::runtime_error("Top is not exists !! \n");
    }

    std::cout << "Top element is : " <<  data[++front] << "\n";
    
}

template <typename T>
inline void Queue<T>::sizeQueue()
{
    std::cout << "m_size of queue is " << m_size << '\n';
}

template <typename T>
inline bool Queue<T>::isEmpty()
{
    if(m_size == 0 || rear == -1 || front == rear){
        return true;
    }   
    else{
        return false;
    } 
    
}

template <typename T>
inline void Queue<T>::printQueue()
{
    // if(m_size == 0){
    //     throw std::runtime_error("Size is zero - Nothing to print !! \n");
    // }

    if(front == rear){
        throw std::runtime_error("Queue is empty as all elements are deleted !!\n");
    }

    for(int i=front+1;i<=rear;i++){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}
