#include"Company.h"
#include<iostream>

Company::Company(std::string name):nextSerial(1),totalEmployee(0),totalCustomer(0)
{
    //ctor
    this->name=name;
}

Company::~Company()
{
    //dtor
}

bool Company::add(Customer c,int EmployeeIndex)
{
    if(EmployeeIndex>totalEmployee) return false;
    else
    {
        c.SetcustomerId(nextSerial++);
        if(!employees[EmployeeIndex].addCustomer(c)) return false;
        else
        {
            totalCustomer++;
            return true;
        }
    }
}

void Company::showStatus()
{
    std::cout<<name<<std::endl;
    std::cout<<"Total Added Customer: "<<totalCustomer<<std::endl;
    std::cout<<"Total Employee: "<<totalEmployee<<std::endl;
    std::cout<<"-----"<<std::endl;
    for(int i=0; i<totalEmployee; i++)
    {
        std::cout<<employees[i].Getname()<<" has following customers\n";
        for(int j=0; j<employees[i].GetnoOfCustomerTakenCare(); j++)
        {
            std::cout<<employees[i].getCustomerName(j)<<std::endl;
        }
        if(i+1<totalEmployee)std::cout<<"-----"<<std::endl;
    }

}
bool Company::addEmployee(Employee e)
{
    if(totalEmployee+1>100) return false;
    else
    {
        employees[totalEmployee++]=e;
        return true;
    }
}
bool Company::served(int customerID)
{
    for(int i=0; i<totalEmployee; i++)
    {
        for(int j=0; j<employees[i].GetnoOfCustomerTakenCare(); j++)
        {
            if(employees[i].getCustomer(j).GetcustomerId()==customerID)
            {
                if(employees[i].removeCustomer(j))
                {
                    totalCustomer--;
                    return true;
                }
            }
        }
    }
    return false;
}
