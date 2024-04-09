/*
    class Vehicle {

        public: 

            virtual void display() = 0;
            virtual void vehicleRegistrationNumber(){
                std::cout << "Vehicle registered by normal rules \n";
            }
    };

    class Car : public Vehicle {

        public:

            void display() override {
                std::cout << "Hello from car class \n";
            }

            virtual void vehicleRegistrationNumber() override{
                std::cout << "Car registered by normal rules \n";
            }

    };

    class Bike : public Vehicle {

        public:

            void display() override{
                std::cout << "Bike display ";
            }

    };


    VTABLES : These are records of virtual function and their loactiaon in code segment..

    RULES FOR VTABLES : 

    Rule 1: A Vtable will be always made for class that contains at least 1 virtual function

    Rule 2: A child class that inherits from a parent containing a Vtable has to make its own Vtable also..

    Rule 3: The location where the Vtable for a class "X" is stored is recorder in VPTR..

    Rule 4 : Exact data structure level implementation of a VTabel is not standardized..



    int main(){
        Vehicle* ptr = new Car();

        ptr->display();

        a) WHat is the pert : Vehicle
        b)Does Vehicle class have any mention of Display member ?  
            If no - compile time error
            If yes - proceed further 

        c) What is the type of nature of display function ?
             Non - virtual function : Go to question X
             For Virtual function : Go to question Y

        X) IS the function concrete or abstract ?
            If concrete - call function from pointer class
            If abstarct --> compile time error

        Y) WHat is the type fo the object ?
            - FIND THE VTABLE FOR OBJECT TYPE
            - FIND THE ADDRESS OF DISPLAY FOR OBJECTTYPE::DISPLAY



    VTABLE WORKING : 

    VTABLE for Vehicle : 
        [display : 000x10H]
        [registerVehicle : 000x20H]      <---------------
                                                        |                                                  
    VTABLE for Car :                                    |
        [display : 000x11H]                             |
        [registerVehicle : 000x21H]                     |
                                                        |
    VTABLE for Bike :                                   |
        [display : 000x12H]                             |
        [registerVehicle : ] ---------------------------|        

    VPTR : 
        It is a static ptr
        It is a hidden member...

        static VTable* vptr = 345H;



*/
