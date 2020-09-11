#ifndef COMPANY_H
#define COMPANY_H
#include<string>
#include"Customer.h"
#include"Employee.h"
#include"project.h"
class Company
{
protected:
    std::string name;
    int totalEmployee;
    int totalCustomer;
    int totalStaff;
    int totalProject;
    Customer* customers[500];
    Employee* employees[500];
    Project* projects[100];
public:
    Company();
    Company(std::string name);
    ~Company();
    void addCustomer(Customer &c);
    void addEmployee(Employee &e);
    void addIntern(Employee* i);
    void addProject(Project &p);
    void showProject();
    //void showStatus();
    void showemployee();
    void showCustomer();
    void showIntern();
    void updateEmployeelist();
    void updateCustomerlist();
    void editProjectid(Customer &c1,Employee &e1,Employee &e2,Employee &e3,int pid);
    int getTotalStaff() { return totalStaff; }
    std::string getName()
    {
        return name;
    }
    void setName(std::string val)
    {
        name=val;
    }
};
#endif // COMPANY_H


