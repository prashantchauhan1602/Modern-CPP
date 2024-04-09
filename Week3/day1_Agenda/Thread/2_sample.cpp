#include<iostream>
#include<thread>      // mandatory
#include<mutex>

std::mutex mt;

void Square(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));


        // Critical Section....
        mt.lock();            // Mutual Exclusion Principle..
        std::cout << " Square of numbers is : "<< arr[i] * arr[i] << " \n ";
        mt.unlock();

    }
}

void Cube(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));   // Greek word



        // Critical Section....
        mt.lock();
        std::cout << " Cube of numbers is : "<< arr[i] * arr[i]* arr[i] << "  \n";
        mt.unlock();
    }
}

int main(){
    int arr[] = {1,2,3,4,5};

    // Square(arr, 5);
    // Cube(arr,5);

    std::thread t1(&Square, arr, 5);
    std::thread t2(&Cube, arr,5 );

    if(t1.joinable()){
        t1.join();      // main thread should now wait till t1 is finished !! [ block till t1 is finished !! ]
    }

    if(t2.joinable()){
        t2.join();     // main thread should now wait till t2 is finished !! [ block till t2 is finished !! ]
    }

    std::cout << "Goodbye\n";
}

/*
    If thread named as X acquired the mutex, then all other have to wait...

    CRITICAL SECTION  ------------------> use Mutex lock
*/
