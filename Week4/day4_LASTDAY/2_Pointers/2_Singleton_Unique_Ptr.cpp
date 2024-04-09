#include<iostream>
#include<memory>

class Operation;
using OperationPtr = std::unique_ptr<Operation>;

class Operation
{
private:
    static OperationPtr _instances;


   Operation() = default;
   Operation(const Operation &) = delete;
   Operation &operator=(const Operation &) = delete;
   
   Operation(Operation &&) = default;
   Operation &operator=(Operation &&) = delete;
   
public:
   
   static OperationPtr& GetInstance(){
        if(_instances){
            return _instances;
        }

        else{
            _instances.reset( new Operation() );
            return _instances;
        }
   }
   ~Operation() = default;
};

int main(){
    OperationPtr& ptr = Operation::GetInstance();              // &ptr ----> works only !!
}




