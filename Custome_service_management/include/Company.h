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
    static int total_company;
    int company_id=total_company+1;
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
    void editProjectid(int employeeid1,int employeeid2,int employeeid3,int projectid,int customerindex,int cst);
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
