#ifndef COMPANY_H
#define COMPANY_H
#include<string>
#include"Customer.h"
#include"Employee.h"
class Company
{
protected:
    std::string name;
    int totalEmployee;
    int totalCustomer;
    Customer* customers[500];
    Employee* employees[500];
public:
    Company();
    Company(std::string name);
    ~Company();
    void addCustomer(Customer &c);
    void addEmployee(Employee &e);
    void showStatus();
    void showemployee();
    void showCustomer();
    void updateEmployeelist();
    void updateCustomerlist();
    void editProjectid(Customer &c1,Employee &e1,Employee &e2,Employee &e3,int pid);
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
