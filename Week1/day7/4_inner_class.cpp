/*

    Scenario 1 :

        I want to design a customer retail
        Selling website

        -Customer (name, age, gender, Customer)
        -Customer(roomNo/ flatNO, location , citya, state , pincode)

        Customer HAS A Customer :         [Has a relationship]
            Ques 1: Would you make Customer outside of CUstomer ?
                    If yes - is it Aggregation or Composition...?
                    If No - Inner Class will be used


*/

// Inner class are implicitly friend...
#include <iostream>

class Customer
{
    // Easiest way - Make this class as public [but it is not good enough]
public:
    class Address
    {
    private:
        std::string _location;
        unsigned int _pincode;
        unsigned short _house_number;
        std::string _street_name;
        std::string _state;

    public:
        Address() = delete;

        Address(const Address &) = default;
        Address &operator=(const Address &) = default;

        Customer::Address::Address(std::string location, unsigned int pincode, unsigned short houseNumber, std::string streetName, std::string state)
            : _location{location}, _pincode{pincode}, _house_number{houseNumber},
              _street_name{streetName}, _state{state}
        {
        }

        Address(Address &) = delete;
        Address &operator=(Address &) = delete;

        ~Address() = default;

        Address(std::string location, unsigned int pincode, unsigned short houseNumber,
                std::string streetName, std::string state);

        unsigned int pincode() const { return _pincode; }

        std::string location() const { return _location; }
        void setLocation(const std::string &location) { _location = location; }

        unsigned short houseNumber() const { return _house_number; }
        void setHouseNumber(unsigned short house_number) { _house_number = house_number; }

        std::string streetName() const { return _street_name; }
        void setStreetName(const std::string &street_name) { _street_name = street_name; }

        std::string state() const { return _state; }

        inline friend std::ostream &operator<<(std::ostream &os, const Address &rhs)
        {
            os << "_location: " << rhs._location
               << " _pincode: " << rhs._pincode
               << " _house_number: " << rhs._house_number
               << " _street_name: " << rhs._street_name
               << " _state: " << rhs._state;
            return os;
        }
    };

public:
    Customer() = delete;

    Customer(const Customer &) = default;
    Customer &operator=(const Customer &) = default;

    Customer(Customer &) = delete;
    Customer &operator=(Customer &) = delete;

    ~Customer() = default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    // Customer(std::string name, int age, Address address);

    // Address customerAddress() const { return _customer_address; }

private:
    std::string _name;
    int _age;
    Address _customer_address;
};

/*

    Object....

    name | age |   inner class object
                        |
                        |
                        location | pincode | houseNumber | streetName | state
*/




int main()
{
    Customer c1("Dev", 22,
                Customer::Address("DullaKheri", 247776, 132, "Rana Street", "UP"));

    std::cout << c1.customerAddress().pincode();
}

/*
    Name of the inner class is to be public...
    Constructor of inner class is also to be public...
    Other all member we can decide...



    class customer{
        public:
            Member functions
            Declaration of address
                public:
                    Member function address

                private:
                    data member of address

        private:
            _name,
            age,
            _customer_address


        Approach 2 : 

        Make an object of inner class in upper class public section....
        Declare inner class after upper class..

        class UpperClass :: InnerClass{};



        Homework :
            How to access private data member and function by using outer class..
            Do the same code by using forward declaration...
    }
*/
