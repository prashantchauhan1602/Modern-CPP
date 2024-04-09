#ifndef PROJECT_H
#define PROJECT_H

#include<iostream>
#include<functional>

class Project
{
private:
    std::string _project_name {""};
    int _project_id{-1};

public:
    Project() = delete;

    Project(const Project&) = delete;
    Project operator=(const Project&) = delete;

    Project(Project &&) = delete;
    Project& operator=(Project&&) = delete;

    ~Project() = default;

    std::string projectName() const { return _project_name; }
    void setProjectName(const std::string &project_name) { _project_name = project_name; }

    int projectId() const { return _project_id; } 

    Project(std::string name, int id);
};




#endif // PROJECT_H
