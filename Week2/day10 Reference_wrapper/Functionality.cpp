#include "Functionality.h"



void CreateObject(ProjectContainer & projects, EmployeeContainer & employees)
{
    projects.push_back(
        Project{11, 9800.60f}
    );

    projects.push_back(
        Project{11, 9800.60f}
    );

    projects.push_back(
        Project{11, 9800.60f}
    );

/*
    In a list container, a new node has to be created based on 
        Rvalue provided of type Project..
*/        

/*
    Step1 : Parameterized ctor will be called...

    Step 2 : Data either move or delete....(so we have to enable atleast move or copy constructor)
*/

    // How I can attach std::make_shared<Employee> to Project...?
        // As it a list, so indexing is not be used...[ We have to use iterators]

    /*
        [     p1     p2    p3]
             *itr     itr    itr       [ Also check iterator is valid or not ]
    */

    // employees.push_back(
    //     std::make_shared<Employee>(101, "Dev", 87650.0f, *itr)
    // );

    /*
        check this itr first [ segmentation fault ]
        Check the code below...
    */
     
    auto itr = projects.begin();
    if(itr != projects.end()){
        employees.push_back(std::make_shared<Employee>(101, "Dev", 985000.0f, *itr++));
    }

    if(itr != projects.end()){
        employees.push_back(std::make_shared<Employee>(104, "Rana", 585000.0f, *itr++));
    }

    if(itr != projects.end()){
        employees.push_back(std::make_shared<Employee>(101, "Dev", 985000.0f, *itr++));
    }

    // We can make a file and fetch the data....(like APIs fetch the data)
}

float FindBudgetBasedOnId(EmployeeContainer &employees, int idFind)
{
    if(employees.empty()){
        throw std::runtime_error("Data is empty !! ");
    }

                // Find out the reason why it is not working ?

    // for(auto itr = employees.begin(); itr != employees.end(); itr++){
    //     if(itr->id() == idFind){
    //         return itr.project().get().budget();
    //     }
    // }

    // For each empl in employees..
    unsigned int count{0};
    for(EmpPointer & emp : employees){
        if(emp->id() == idFind){
            count++;
            return emp->project().get().budget();       // get is used...
        }
    }
    if(count == 0){
        throw std::runtime_error("No data is found based on this id \n");
    }
}

RefContainer FindFirstNProjectReferences(const EmployeeContainer &employees, unsigned int N)
{
    if(employees.empty()){
        throw std::runtime_error("Data is empty");
    }

    if(N <= 0 || N >= employees.size()){
        throw std::runtime_error("N value is invalid !! \n");
    }

    RefContainer result;
    for(EmpPointer emp: employees){
        result.push_back(emp->project());
    }
    return result;
}

bool IsContainerAll50KAboveSalary(const EmployeeContainer& employees)
{
    if(employees.empty()){
        throw std::runtime_error("Data is empty !! ");
    }

    for(EmpPointer emp: employees){
        if(emp->salary() < 50000.0f){
            return false;
        }
    }
    return true;
}

std::size_t EmployeeCountBudgetOver60000(const EmployeeContainer &employees)
{
    if(employees.empty()){
        throw std::runtime_error("Data is empty !! ");
    }
    
    std::size_t counter{0};
    for(EmpPointer emp : employees){
        if(emp->project().get().budget() > 60000){
            counter++;
        }
    }
    return counter;
}

EmployeeContainer FilterEmployeeByPredicate(const EmployeeContainer &employees, std::function<bool(EmpPointer&)> pred)
{
    EmployeeContainer result;
        // For this, we have to enable the copy constructor of std::make_shared<Employee> Class..
                // [ Because we are copying the data from Main container to Result Container]
    
    if(employees.empty()){
        throw std::runtime_error("Data is empty !! ");
    }

    //  Either we have to remove const from here...
            //otherwise we have to add const in function parameter
            //  Main Idea is : Try not to mismatch the parameter type

    for(EmpPointer emp: employees){
        if(pred(emp)){
            result.push_back(emp);
        }
    }

    if(result.empty()){
        throw std::runtime_error("Container is empty - no match found !! ");
    }
    return result;
}

void ComputeTaxBasedOnFormula(const EmployeeContainer &employees, std::function<float(EmpPointer &)> fn)
{
    if(employees.empty()){
        throw std::runtime_error("Data is empty !! ");
    }

    for(EmpPointer emp: employees){
        std::cout << "The tax on employee with employee Id is : " << fn(emp) << "\n";
    }
}

// Curl dependencies...  [sudo apt install curl]
/*
    How to add dependencies in CPP ?
        Ans is : Add simple header file
*/
