#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <Person.h>
#include<bits/stdc++.h>

using namespace std;

enum class Designation {Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};

class Employee : virtual public Person
{
protected:
    Designation designation;
    int experience;
    string position;
    double salary;
    static int employee_id;
    int no_of_projects;
    double bonus;
    //Customer customer[10];
public:
    Employee();
    Employee(string nam,string phn,string addr,string em,Designation des,int ex,double salary,int nopro);
    virtual ~Employee();

    string Getdesignation();
    void Setdesignation(Designation val)
    {
        designation = val;
    }
    int Getexperience()
    {
        return experience;
    }
    void Setexperience(int val)
    {
        experience = val;
    }
    string Getposition()
    {
        return position;
    }
    void Setposition(int val);
    double Getsalary()
    {
        return salary;
    }
    void Setsalary(double val)
    {
        salary = val;
    }
    //void addCustomer(Customer c);
    //bool removeCustomer(int index);
    void getEmployee_id();
    static void setEmployeeId(int id)
    {
        employee_id=id;
    };
    double getbonus();
    void calcbonus();
    int getno_ofprojects();
    void generatePassword();
    void displayinfo();

    //int getGroupId();  //implement later



};

int Employee::employee_id=0;
#endif // EMPLOYEE_H
