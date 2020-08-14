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
    //const
    int employee_id=2001+total_employee;
    //int no_of_projects;
    int projectid;
    double bonus;
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
    //void setEmployeeID(int a) {employee_id=a;}
    //void addCustomer(Customer c);
    //bool removeCustomer(int index);
    double getBonus()
    {
        return bonus;
    }
    void calcBonus();
    //int getno_ofprojects();
    char* getPassword();
    void generatePassword();
    void displayinfo();
    void setinfo(std::string nam,std::string phn,std::string addr,std::string em,std::string des,int ex);
    int getProjectId() {return projectid;}
    void setProjectId(int a) {projectid=a;}
    Employee operator =(Employee& e1);
};
#endif
