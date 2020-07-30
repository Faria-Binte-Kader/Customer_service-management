#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Person.h"
#include<bits/stdc++.h>
enum class Designation{Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};
class Employee:virtual public Person
{
protected:
    Designation designation;
    int experience;
    std::string position;
    double salary;
    static int total_employee;
    int employee_id=2000+total_employee;
    //int no_of_projects;
    //double bonus;
    //Customer customer[10];
public:
    Employee();
    Employee(std::string nam,std::string phn,std::string addr,std::string em,std::string des,int ex);
    virtual ~Employee();
    std::string getDesignation();
    void setDesignation(std::string val);
    int getExperience()
    {
        return experience;
    }
    void setExperience(int val)
    {
        experience=val;
    }
    std::string getPosition()
    {
        return position;
    }
    void setPosition();
    double getSalary()
    {
        return salary;
    }
    void setSalary();
    int getEmployeeID()
    {
        return employee_id;
    }
    void setEmployeeID(Designation d);
    //void addCustomer(Customer c);
    //bool removeCustomer(int index);
    /*double getbonus()
    {
        return bonus;
    }
    void calcbonus()
    {

    }*/
    //int getno_ofprojects();
    void generatePassword();
    void displayinfo();
    //int getGroupId();
};
#endif
