#include<iostream>

/*
    Function categories : 
        1: function exists in parent and child both, but it is not marked virtual

        2: function only exists in parent, not overridden, not marked virtual
            (like roadtax is not in evCar but also in diesel and petrolCar)

        3: function exists in parent and child both, implemented in both and
             marked as virtual
*/
class Parent
{
private:
    std::string _surname;
public:
    

    void non_virtual_func_in_parent_child(){
        std::cout << "Parent output from \n";
    }

    void ParentOnlyFunctionTest(){
        std::cout<<"Namaste jii \n";
    }

    /* 3 : function exists in parent and child both, implemented in both and 
                marked as virtual

            Works with upcasting 
    */
    virtual void Display(){
        std::cout << "Parent class display function called \n";
    }

    Parent(std::string surname)
        : _surname{surname}
        {
        }

    ~Parent(){
        std::cout << "Parent Deconstructor called !! \n" ;
    }
};

class Child : public Parent
{
private:
    std::string _name;
public:
    Child(std::string surname, std::string name)
        : Parent(surname)
        {
            _name = name;
        }

    void Display() override{
        std::cout << "Child class display function called \n";
    }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    ~Child(){
        std::cout << "Parent Deconstructor called !! \n";
    };
};


/*
    Rule 1 : 
        In case of upcasting,
            for non-virtual function, compiler doesn't care about object RHS
            for virtual function, compiler will surely consider object type also
            by finding the hirerachy
*/
int main(){
   auto* p1 = new Parent("Satyam");
    // p1->Test();
    p1->Display(); //pointer parent : object parent
 
    // p1 = new Child("sattu", "siddhu");
    p1->Display(); //pointer parent : object child

    // p1 = new Child("xyz", "abc");
    // std::cout<<"Name of child is : " << p1->name() << std::endl; 

        // [Because it is non virtual data function]
        // Non virtual function -----> only works on pointer type

        // Dynamic Cast is used if you want a functionality that exists only in child class
        // utilizing the parent pointer BUT BY CONVERTING INTO CHILD 
        
        // Dynamic cast is only ---->    pointer to pointer and reference to reference

    
    // Child* cptr = dynamic_cast<Child*>(p1);

    // Mandatory to check : 
        // If pointer then check by nullptr 

    // if(cptr == nullptr){
    //     std::cerr << "Conversion failed \n";
    // }
    // else{
    //     std::cout<<"Name of child is : " << cptr->name() << std::endl;
    // }

    // DownCasting is not safe...It is a very risky practise...
    // Because all the functionalities of parent class is present in child but not vice versa..

        // try catch block used for this....
    
    // Parent p("xyz");
    // try
    // {
    //     Child& ch = dynamic_cast<Child&>(p);
    //     ch.name();        //Risky practise
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch(const std::bad_cast& e)
    // {
    //     std::cerr << "Casting way too risky, It failed " << '\n';
    // }
    
    
}

/*
    Upcasting : (virtual or pure virtually to be used....[mainly pure virtual])
        taking reference or pointer of subtype and assigning it to user refernce
        or pointer of parent type (respectively)

                            Car

    c1                         c2                        c3
    EvCar                   petrolCar                dieselCar

    Car* arr[3] = {c1{}, c2{}, c3{}};
    for(Car* c : arr){
        c -> display();
    }

    Objective : Create object of different child classes and store/process them collectively.

    While doing this, if a functionality is different in these classes, execute the
    correct version of functionality based on type !

    Concept : Method / Function Overiding

    What is the base for this idea ?  ------> Polymorphism

    Syntactically, how does compiler known function will be changed in child class?
    Ans:  Depends on abstract class or not..

    How does compiler know this..?
    Ans: Based on lack/existence of at least one pure virtual function...
*/


/*
    // DownCasting is not safe...It is a very risky practise...

    // Because all the functionalities of parent class is present in child but not vice versa..
*/



/*

    Encapsulation : (related to data member)
        eg : user may call the function but don't know how our data member will works

        // This can be done by Data binding 

*/
