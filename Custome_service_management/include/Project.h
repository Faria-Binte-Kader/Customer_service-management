#ifndef PROJECT_H
#define PROJECT_H

#include"Employee.h"
#include"Customer.h"
#include<bits/stdc++.h>
#include<ctime>
class Project
{
protected:
    static int total_projects;
    const int projectId=10001+total_projects;
    Employee emp1,emp2,emp3;
    Customer cust;
    Employee* intr;
    int total_intern=0;
    int project_time; //in months
    std::string description;
    Date delivery_date;
    std::string status;
    double cost;
public:
    Project();
    Project(Customer &c, Employee &e1,Employee &e2, Employee &e3, double cst, int tm, std::string des);
    virtual ~Project();
    int getProjectId()
    {
        return projectId;
    }
    int getProjectTime()
    {
        return project_time;
    }
    void setStatus();
    std::string getStatus()
    {
        return status;
    }
    Date getDeliveryDate()
    {
        return delivery_date;
    }
    Date calcDeliveryDate();
    void setCost(double c)
    {
        cost=c;
    }
    double getCost()
    {
        return cost;
    }
    void setInfo(Customer &c, Employee &e1,Employee &e2, Employee &e3,double cst);
    void addIntern(Employee* i);
    void projectDetails();
};

#endif // PROJECT_H
