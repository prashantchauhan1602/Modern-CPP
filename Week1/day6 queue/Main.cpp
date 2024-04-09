#include<iostream>
#include"Queue.hpp"

int main(){

    int arr[5] = {1,2,3,4,5}; //
    Queue<int> qs(arr, 5);

    // qs.insertData(10);
    // qs.insertData(20);
    // qs.insertData(30);
    // qs.insertData(40);
    // qs.insertData(50);
    // qs.insertData(60);

    // qs.deleteData();
    // qs.deleteData();
    // qs.deleteData();

    // std::string arr[5] {"ab","cd","ef","gh","ij"};
    // Queue<std::string> qs(arr, 5);

    // qs.insertData("abc");
    // qs.insertData("bcd");
    // qs.insertData("cde");
    // qs.insertData("def");
    // qs.insertData("efg");
    // qs.insertData("fgh");

    // qs.deleteData();
    // qs.deleteData();
    // qs.deleteData();
    // qs.deleteData();
    // qs.deleteData();

    if(qs.isEmpty()){
        // throw std::runtime_error ("Queue is empty !! \n");
        std::cout << "Queue is empty !! \n";
    }
    else{
        std::cout << "Queue is not empty !! \n";
    }

    qs.sizeQueue();
    qs.printQueue();
    qs.top();

}
