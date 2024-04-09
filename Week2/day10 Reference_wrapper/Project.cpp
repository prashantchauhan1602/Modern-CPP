#include"Project.h"
#include<iostream>

std::ostream& operator<<(std::ostream& os, const Project& rhs){
    os << "_id is : " << rhs._project_id
        << "_budget is : " << rhs._budget;
}

Project::Project(int id, float budget)
    : _project_id{id}, _budget{budget}
{
}
