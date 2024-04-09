#include<iostream>

/*
    Function categories : 
        1: function exists in parent and child both, but it is not marked virtual

        2: function only exists in parent, not overridden, not marked virtual
            (like roadtax is not in evCar but also in diesel and petrolCar)

        3: function exists in parent and child both, implemented in both and
             marked as virtual
*/
    

                 // <-----------------------------  ******** ------------------------------>

/*
    Rule 1 : 
        In case of upcasting,
            For non-virtual function, compiler doesn't care about object RHS [ object type ]
               

            For virtual function, compiler will surely consider object type also
            by finding the hirerachy
*/
class Parent
{
private:
    std::string _surname;
public:
    

    virtual void non_virtual_func_in_parent_child(){
        std::cout << "Parent output from \n";
    }

    virtual void ParentOnlyFunctionTest(){
        std::cout<<"Namaste jii Parent \n";
    }
    
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

    void non_virtual_func_in_parent_child(){
        std::cout << "Child output from \n";
    }

    virtual void Display(){
        std::cout << "Child class display function called \n";
    }

    void ParentOnlyFunctionTest() override{
        std::cout<<"Namaste jii Child\n";
    }
    
    ~Child(){
        std::cout << "Parent Deconstructor called !! \n";
    };
};

class Child2: public Child
{
private:
    std::string _fname;
public:
    Child2(std::string surname, std::string name, std::string fname): Child(surname, name){
        _fname = fname;
    }

    void non_virtual_func_in_parent_child(){
        std::cout << "Child2 output from \n";
    }

    void Display() override{
        std::cout << "Child2 class display function called \n";
    }

   
};

/*
    Rule 1 : 
        In case of upcasting,
            for non-virtual function, compiler doesn't care about object RHS
            for virtual function, compiler will surely consider object type also
            by finding the hirerachy
*/

int main(){
   Parent* p1 = new Parent("Dev");                    //pointer parent : object parent
    p1->non_virtual_func_in_parent_child();
    
 
    Parent* p2 = new Child("sattu", "siddhu");           //pointer parent : object parent
    p2->non_virtual_func_in_parent_child();

    Parent* p3 = new Child("dev", "rana");          
    p3->Display();

    
}

/*
        Parent* p1 = new Parent("Dev");
            1. Calling Non-virtual function..

                If the function (that call by ourselves) is non-virtual, then it doesn't depend on object type..
                Whatever function comes first (whether it is of Parent Class and the object of Base Class) 
                    Parent class function will be executed.

            2. Calling Virtual function...

                If the function (that call by ourselves) is virtual, then it depends on object type..
                    Then it goes on hierarchy and call the function of (same class of an object)
                    Important : whether the function is virtual in that class also

                    
            3. If the pointer is of Parent Class, and some function is present in only Child class,
                    then it gives Compilation error
*/
