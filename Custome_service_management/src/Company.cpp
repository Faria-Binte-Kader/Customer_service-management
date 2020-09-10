#include"Company.h"
#include<bits/stdc++.h>
#include<fstream>
Company::Company():name(""),totalEmployee(0),totalCustomer(0),totalStaff(0)
{

}
Company::Company(std::string nam):name(nam),totalEmployee(0),totalCustomer(0),totalStaff(0)
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
    employees[totalStaff]=&e;
    totalEmployee++;
    totalStaff++;
    Company::updateEmployeelist();
}

void Company::addIntern(Employee* i)
{
    employees[totalStaff]=i;
    totalStaff++;
}

void Company::editProjectid(Customer &c1,Employee &e1,Employee &e2,Employee &e3,int pid)
{
    int cnt=0;
    for(int i=0; i<totalEmployee; i++)
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
    for(int i=0; i<totalCustomer; i++)
    {
        if(c1.getCustID()==customers[i]->getCustID())
        {
            c1.SetProjectId(pid);
            break;
        }
    }
}
void Company::showIntern()
{
   for(int i=0; i<totalStaff; i++)
    {
        if(employees[i]->permanent()==false)
        {
           employees[i]->displayinfo();
           std::cout<<std::endl;
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
    for(int i=0; i<totalStaff; i++)
    {
        if(employees[i]->permanent()==true)
        {

        fin<<"Name\t\t\t: "<<employees[i]->getName()<<std::endl;
        fin<<"Phone number\t\t: "<<employees[i]->getPhone_no()<<std::endl;
        fin<<"Address\t\t\t: "<<employees[i]->getAddress()<<std::endl;
        fin<<"Email\t\t\t: "<<employees[i]->getEmail()<<std::endl;
        fin <<"Employee ID\t\t: "<<employees[i]->getEmployeeID()<<std::endl;
        fin<<"Designation\t\t: "<<employees[i]->getDesignation()<<std::endl;
        fin<<"Experience\t\t: "<<employees[i]->getExperience()<<std::endl;
        fin<<"Position\t\t: "<<employees[i]->getPosition()<<std::endl;
        fin<<"Salary\t\t\t: "<<employees[i]->getSalary()<<std::endl;
        fin<<"Project ID\t\t: "<<employees[i]->getProjectId()<<std::endl;
        fin<<std::endl;
    } }
    fin.close();
}

void Company::updateCustomerlist()
{
    std::ofstream fin;
    fin.open("customer.txt");
    if(fin.fail())
    {

        std::cout << "Input file opening failed.\n";

    }

    for(int i=0; i<totalCustomer; i++)
    {
        fin<<"Name\t\t\t: "<<customers[i]->getName()<<std::endl;
        fin<<"Phone number\t\t: "<<customers[i]->getPhone_no()<<std::endl;
        fin<<"Address\t\t\t: "<<customers[i]->getAddress()<<std::endl;
        fin<<"Email\t\t\t: "<<customers[i]->getEmail()<<std::endl;
        fin <<"Customer ID\t\t: "<<customers[i]->getCustID()<<std::endl;
        fin<<"Budget\t\t\t: "<<customers[i]->getBudget()<<std::endl;
        fin<<"Duration\t\t: "<<customers[i]->getDuration()<<std::endl;
        fin<<"Cost\t\t\t: "<<customers[i]->getCost()<<std::endl;
        fin<<"Description\t\t: "<<customers[i]->getDescription()<<std::endl;
        fin<<"Date Assigned\t\t: "<<customers[i]->getDate().day<<"/"<<customers[i]->getDate().month<<"/"<<customers[i]->getDate().year<<std::endl;
        fin<<"Project Type\t\t: "<<customers[i]->getWork()<<std::endl;
        fin<<"Project ID\t\t: "<<customers[i]->GetProjectId()<<std::endl;
        fin<<"Project Condition\t: ";
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

    if ( fin.fail()==true )
    {
        // Empty File
        std::cout<<"Can not open file\n\n";

    }
    else
    {
        std::string a;
        while(getline(fin, a))
        {
            std::cout << a << "\n";
        }
        fin.close();
    }

}

