#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Person.h"
#include<bits/stdc++.h>
struct Date
{
    int day;
    int month;
    int year;
    Date()
    {

    }
    Date(int d,int m,int y):day(d),month(m),year(y)
    {

    }
};
enum class WorkType{Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};
class Customer:virtual public Person
{
protected:
    double budget;
    int duration;
    double final_cost;
    std::string description;
    //int project_id;
    Date assigned_date;
    WorkType work;
public:
    static int cust_id;
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
    bool isServed(Date dt);
    void generatePassword();
    void displayinfo();
};
int Customer::cust_id=1000;
#endif
