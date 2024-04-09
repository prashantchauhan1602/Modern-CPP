#include<iostream>


// Final keyword can be used for locking the class....and marking the function as final 
    // Not to be extended...
    // We can use containership also...

    // Why people marked final....?
    // Ans : SOLID PRINCIPLE
     
class Demo //final
{
private:
   int _id;
   std::string _name;

public:
    Demo(int id, std::string name = "Dev") : _id{id}, _name{name} {}

    virtual void example();  //final;

};

class Fancy_demo : public Demo                 // because Demo class is final
{
private:
    int _fancyName;

public:
    Fancy_demo(int fancyName) : _fancyName{fancyName}{}

    void example() override;                       // [It works because function is not final]
};


/*
    Virtual function can be override...
    Virtual function may be final....[ now, it doesn't override]

    For eg : 
        In parent class :   
            virtual void example() final{}

        In child class : 
            void example() override     [It gives an error]
*/
