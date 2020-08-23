#include"Company.h"
#include<bits/stdc++.h>
#include<fstream>
Company::Company():name(""),totalEmployee(0),totalCustomer(0)
{

}
Company::Company(std::string nam):name(nam),totalEmployee(0),totalCustomer(0)
{
    setName(nam);
}
Company::~Company()
{

}
void Company::addCustomer(Customer &c)
{
    customers[totalCustomer]=&c;
    totalCustomer++;
    Company::updateCustomerlist();
}

void Company::addEmployee(Employee &e)
{
    employees[totalEmployee]=&e;
    totalEmployee++;
    Company::updateEmployeelist();
}
/*void Company::showStatus()
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
    /*for(int i=0;i<totalCustomer;i++)
    {
        customers[i]->displayinfo();
        std::cout<<std::endl;
    }}*/


void Company::editProjectid(Customer &c1,Employee &e1,Employee &e2,Employee &e3,int pid)
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

void Company::updateEmployeelist()
{
    std::ofstream fin;
    fin.open("employee.txt");
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    for(int i=0; i<totalEmployee; i++)
    {
        fin<<"Name: "<<employees[i]->getName()<<std::endl;
        fin<<"Phone number: "<<employees[i]->getPhone_no()<<std::endl;
        fin<<"Address: "<<employees[i]->getAddress()<<std::endl;
        fin<<"Email: "<<employees[i]->getEmail()<<std::endl;
        fin <<"ID: "<<employees[i]->getEmployeeID()<<std::endl;
        fin<<"Designation: "<<employees[i]->getDesignation()<<std::endl;
        fin<<"Experience: "<<employees[i]->getExperience()<<std::endl;
        fin<<"Position: "<<employees[i]->getPosition()<<std::endl;
        fin<<"Salary: "<<employees[i]->getSalary()<<std::endl;
        fin<<"Project id: "<<employees[i]->getProjectId()<<std::endl;
        fin<<std::endl;
    }
    fin.close();
}

void Company::updateCustomerlist()
{
   std::ofstream fin;
    fin.open("customer.txt");
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    for(int i=0; i<totalCustomer; i++)
    {
        fin<<"Name: "<<customers[i]->getName()<<std::endl;
        fin<<"Phone number: "<<customers[i]->getPhone_no()<<std::endl;
        fin<<"Address: "<<customers[i]->getAddress()<<std::endl;
        fin<<"Email: "<<customers[i]->getEmail()<<std::endl;
        fin <<"ID: "<<customers[i]->getCustID()<<std::endl;
        fin<<"Budget: "<<customers[i]->getBudget()<<std::endl;
        fin<<"Duration: "<<customers[i]->getDuration()<<std::endl;
        fin<<"Cost: "<<customers[i]->getCost()<<std::endl;
        fin<<"Description: "<<customers[i]->getDescription()<<std::endl;
        fin<<"Date Assigned: "<<customers[i]->getDate().day<<"/"<<customers[i]->getDate().month<<"/"<<customers[i]->getDate().year<<std::endl;
        fin<<"Project Type: "<<customers[i]->getWork()<<std::endl;
        fin<<"Project ID: "<<customers[i]->GetProjectId()<<std::endl;
        fin<<"Project Condition: ";
        if(customers[i]->isServed())
            fin<<"Served."<<std::endl;
        else
            fin<<"Not served yet."<<std::endl;
        fin<<std::endl;
    }
    fin.close();
}

void Company::showemployee()
{
    std::ifstream fin;
    fin.open("employee.txt");
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    std::string a;
    while(getline(fin, a))
    {
        std::cout << a << "\n";
    }
    fin.close();
}

void Company::showCustomer()
{
    std::ifstream fin;
    fin.open("customer.txt");
    if(fin.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    std::string a;
    while(getline(fin, a))
    {
        std::cout << a << "\n";
    }
    fin.close();
}
