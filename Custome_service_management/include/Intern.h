#ifndef INTERN_H
#define INTERN_H
#include "Student.h"
#include "Employee.h"
#include<bits/stdc++.h>


class Intern: public Student,Employee
{
    protected:
        int intership_period;
        static int total_interns;
        const int intern_id=4001+total_interns;

    public:
        Intern();
        virtual ~Intern();
        void setPeriod(int a) { intership_period=a; }
        int getPeriod() { return intership_period; }
        void generatePassword();
        void displayinfo();
        int getInternid(){return intern_id;}
        void setinfo(std::string nam,std::string phn,std::string addr,std::string em,std::string cors,int period);
        //void assignproject();
        //void setProjectid();
        //int getProjectid();
};

#endif // INTERN_H*/
