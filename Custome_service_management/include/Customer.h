#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <Person.h>


class Customer : public Person
{
    public:
        Customer();
        virtual ~Customer();

        int Gettime() { return time; }
        void Settime(int val) { time = val; }
        double Getbudget() { return budget; }
        void Setbudget(double val) { budget = val; }
        string Getrequirement() { return requirement; }
        void Setrequirement(string val) { requirement = val; }

    protected:

    private:
        int time;
        double budget;
        string requirement;
};

#endif // CUSTOMER_H
