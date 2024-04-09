#include"DataOperation.h"

int main(){
    DataOperation* ptr = DataOperation::getInstance(10);

    //Not static function ----> requires object and ptr
    // We are storing only address of ptr not the data....[ IMPORTANT ]

    std::thread t1 (&DataOperation::ProducerInput, ptr); 
    std::thread t2 (&DataOperation::CustomerOperation, ptr); 

    if(t1.joinable()){
        t1.join();
    }

    if(t2.joinable()){
        t2.join();
    }
}
