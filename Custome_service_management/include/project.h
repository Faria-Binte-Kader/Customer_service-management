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
        const int projectId=10000+total_projects;
        Employee emp1,emp2,emp3;
        Customer cust;
        int project_time; //in months
        std::string description;
        Date delivery_date;
        std::string status;
        double cost;
    public:
        Project();
        Project(Customer c, Employee e1,Employee e2, Employee e3, double cst, int tm, std::string des);
        virtual ~Project();
        int getProjectId(){return projectId;}
        int getTime(){return project_time;}
        void setStatus(Date del_date);
        std::string getStatus(){return status;}
        Date getDeliveryDate(){return delivery_date;}
        Date calcDeliveryDate();
        double getCost(){return cost;}
};

#endif // PROJECT_H
