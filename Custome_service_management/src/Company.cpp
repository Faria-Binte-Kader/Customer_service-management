#include"Company.h"
#include<iostream>
Company::Company():name(""),totalEmployee(0),totalCustomer(0)
{
    total_company++;
    //std::cout<<"Total company"<<total_company<<std::endl;
}
Company::Company(std::string nam):name(nam),totalEmployee(0),totalCustomer(0)
{
    total_company++;
    //std::cout<<"Total company"<<total_company<<std::endl;
    setName(nam);
}
Company::~Company()
{
}
int Company::total_company=0;
void Company::addCustomer(Customer &c)
{
    customers[totalCustomer]=&c;
    totalCustomer++;
}
void Company::addEmployee(Employee &e)
{
    employees[totalEmployee]=&e;
    totalEmployee++;
}
void Company::updateCompanyInfo(Customer &c1,Employee &e1,Employee &e2,Employee &e3,int pid)
{
    int cnt=0;
    for(int i=0;i<totalEmployee;i++)
    {
        if(e1.getEmployeeID()==employees[i]->getEmployeeID())
        {
            e1.setProjectId(pid);
            cnt++;
        }
        if(e2.getEmployeeID()==employees[i]->getEmployeeID())
        {
            e2.setProjectId(pid);
            cnt++;
        }
        if(e3.getEmployeeID()==employees[i]->getEmployeeID())
        {
            e3.setProjectId(pid);
            cnt++;
        }
        if(cnt==3) break;
    }
    for(int i=0;i<totalCustomer;i++)
    {
        if(c1.getCustID()==customers[i]->getCustID())
        {
            c1.SetProjectId(pid);
            break;
        }
    }
}
void Company::showStatus()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"ID: "<<company_id<<std::endl;
    std::cout<<"Total Customer: "<<totalCustomer<<std::endl;
    std::cout<<"Total Employee: "<<totalEmployee<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
    for(int i=0;i<totalEmployee;i++)
    {
        employees[i]->displayinfo();
        std::cout<<std::endl;
    }
    for(int i=0;i<totalCustomer;i++)
    {
        customers[i]->displayinfo();
        std::cout<<std::endl;
    }
}
