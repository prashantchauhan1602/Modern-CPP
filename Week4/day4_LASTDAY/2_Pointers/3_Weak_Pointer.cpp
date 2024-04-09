#include<iostream>
#include<memory>
#include<thread>

void Magic(std::shared_ptr<int>& p2){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << *p2 << std::endl;
}

int main(){
    std::shared_ptr<int>ptr;
    if(ptr.reset(new int); ptr){
        Magic(ptr);
    }


    ///////////////////////////
    // THIS LINE IS TENSION WALA LINE 

    // WEAK POINTER CAN BE CONVERTED INTO SHARED PTR, IF OWNERSHIP IS REMAINING TILL NOW !!

    std::weak_ptr<int> wp(ptr);     // wp is stalking or observing or tracking in it !!

    /*
        Creates a new std::shared_ptr that shares ownership of the managed object. 
        If there is no managed object, i.e. *this is empty, 
        then the returned shared_ptr also is empty. 
    */
    if(wp.lock()){                   // SIMPLY CHECKS OWNER IS PRESENT OR NOT !!
        std::cout << "OWNER PRESENT \n";
        std::cout << *ptr;

        std::shared_ptr new_owner = wp.lock();       // CONVERT OWNERSHIP !! 
    }
    else{
        std::cout << "OWNER NOT PRESENT !! \n";
    }
    
}
