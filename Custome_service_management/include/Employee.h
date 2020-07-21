#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <Person.h>


class Employee : public Person
{
    public:
        Employee();
        virtual ~Employee();

        string Getexperties() { return experties; }
        void Setexperties(string val) { experties = val; }
        string Getworksas() { return worksas; }
        void Setworksas(string val) { worksas = val; }
        double Getsalary() { return salary; }
        void Setsalary(double val) { salary = val; }

    protected:

    private:
        string experties;
        string worksas;
        double salary;
};

#endif // EMPLOYEE_H
