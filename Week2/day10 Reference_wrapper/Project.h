#ifndef PROJECT_H
#define PROJECT_H

class Project
{
private:
    int _project_id;
    float _budget;
public:

    Project() = delete;

    Project(const Project&) = delete;
    Project operator=(Project&) = delete;

    Project(Project&&) = default;
    Project& operator=(Project&&) = delete;

    ~Project() = default;

    int projectId() const { return _project_id; }
    void setProjectId(int project_id) { _project_id = project_id; }

    float budget() const { return _budget; }
    void setBudget(float budget) { _budget = budget; }

    Project(int id, float budget);
    
    friend std::ostream& operator<<(std::ostream& os, const Project& rhs);
};

#endif // PROJECT_H
