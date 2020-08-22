#ifndef COMPANY_H
#define COMPANY_H

#include<string>
#include"Customer.h"
#include"Employee.h"

class Company
{
public:
    Company(std::string name);
    ~Company();
    bool add(Customer c,int EmployeeIndex);
    void showStatus();
    bool addEmployee(Employee e);
    bool served(int customerID);
protected:
private:
    Employee employees[100];
    int nextSerial;
    int totalEmployee;
    int totalCustomer;
    std::string name;
};

#endif // COMPANY_H
