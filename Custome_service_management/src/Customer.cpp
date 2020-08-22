#include"Company.h"
#include<iostream>
Company::Company():name(""),totalEmployee(0),totalCustomer(0)
{
    total_company++;
}
Company::Company(std::string nam):name(nam),totalEmployee(0),totalCustomer(0)
{
    total_company++;
    setName(nam);
}
Company::~Company()
{

}
int Company::total_company=0;
void Company::addCustomer(Customer c)
{
    customers[totalCustomer]=c;
    totalCustomer++;
}
void Company::addEmployee(Employee e)
{
    employees[totalEmployee]=e;
    totalEmployee++;
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
        employees[i].displayinfo();
        std::cout<<std::endl;
    }
    for(int i=0;i<totalCustomer;i++)
    {
        customers[i].displayinfo();
        std::cout<<std::endl;
    }
}
