#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Person.h"

using namespace std;

struct Date
{
    int day;
    int month;
    //string month;
    int year;
    Date() {}
    Date(int d,int m,int y):day(d),month(m),year(y) {}
};

enum class WorkType {Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};
class Customer:virtual public Person
{
protected:
    double budget;
    int time;
    double final_cost;
    string description;
    //int project_id;
    Date assigned_date;
    WorkType work;
public:
    static int cust_id;
    Customer();
    Customer(string n,string ph,string ad,string em,double b,int t,string desc,Date d,WorkType w);
    virtual ~Customer();
    double GetBudget()
    {
        return budget;
    }
    void SetBudget(double val)
    {
        budget=val;
    }
    int GetTime()
    {
        return time;
    }
    void SetTime(int val)
    {
        time=val;
    }
    int GetCost()
    {
        return final_cost;
    }
    void SetCost(int val)
    {
        final_cost=val;
    }
    string GetDescription()
    {
        return description;
    }
    void SetDescription(string val)
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

    Date GetDate()
    {
        return assigned_date;
    }
    void SetDate(Date val)
    {
        assigned_date=val;
    }
    string getWork();
    void SetWork(WorkType val)
    {
        work=val;
    }
    bool isServed(Date dt);
    void generatePassword();
    void displayinfo();
};
int Customer::cust_id=1000;
#endif

