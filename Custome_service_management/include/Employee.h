#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <Person.h>


class Employee : public Person
{   protected:
        string experties;
        int experience;
        string worksas;
        double salary;
        int workingfor;
        int employee_id;
        static int id;
        Customer customer[10];
    public:
        Employee(string nam,long long int phn,string addr,string em,string exp,int ex,string work);
        virtual ~Employee();

        string Getexperties() { return experties; }
        void Setexperties(string val) { experties = val; }
        int Getexperience() { return experience; }
        void Setexperience(int val) { experience = val; }
        string Getworksas() { return worksas; }
        void Setworksas(string val) { worksas = val; }
        double Getsalary() { return salary; }
        void Setsalary(double val) { salary = val; }
        void addCustomer(Customer c);
        bool removeCustomer(int index);
        void getEmployee_id();
        void setEmployeeId(int id);
        int getSalary();
        double calcsalary();
        //int getGroupId();  //implement later
        //void password_generator();
};

#endif // EMPLOYEE_H
