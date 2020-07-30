#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Person.h"
#include<bits/stdc++.h>
enum class WorkType{Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};
class Customer:virtual public Person
{
protected:
    double budget;
    int duration;
    double final_cost=0.0;
    std::string description;
    //int project_id;
    Date assigned_date;
    WorkType work;
public:
    long long int cust_id=1000+total_customer;
    static int total_customer;
    Customer();
    Customer(std::string nam,std::string phn,std::string addr,std::string em,double b,int t,std::string desc,Date d,WorkType w);
    virtual ~Customer();
    double getBudget()
    {
        return budget;
    }
    void setBudget(double val)
    {
        budget=val;
    }
    int getDuration()
    {
        return duration;
    }
    void setDuration(int val)
    {
        duration=val;
    }
    int getCost()
    {
        return final_cost;
    }
    void setCost(int val)
    {
        final_cost=val;
    }
    std::string getDescription()
    {
        return description;
    }
    void setDescription(std::string val)
    {
        description=val;
    }
    /*int GetProjectId()
    {
        return project_id;
    }
    void SetProjectId(int val)
    {
        project_id=val;
    }*/
    Date getDate()
    {
        return assigned_date;
    }
    void setDate(Date val)
    {
        assigned_date=val;
    }
    std::string getWork();
    void setWork(WorkType val)
    {
        work=val;
    }
    bool isServed();
    void generatePassword();
    void displayinfo();
    void setinfo(std::string nam,std::string phn,std::string addr,std::string em,double b,int t,std::string desc,Date dt2,WorkType w);
};
#endif
