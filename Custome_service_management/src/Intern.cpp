#include "Intern.h"
#include<bits/stdc++.h>

Intern::Intern():Person(),Student(),Employee(),internship_period(0)
{
    //ctor
    generatePassword();
    total_interns++;

}

int Intern::total_interns=0;

void Intern::generatePassword()
{
    Employee::generatePassword();
}

void Intern::displayinfo()
{
    std::cout<<"Name\t\t\t: "<<Student::getName()<<std::endl;
    std::cout<<"Phone number\t\t: "<<Student::getPhone_no()<<std::endl;
    std::cout<<"Address\t\t\t: "<<Student::getAddress()<<std::endl;
    std::cout<<"Email\t\t\t: "<<Student::getEmail()<<std::endl;
    //std::cout<<"Password "<<Employee::password<<std::endl;
    std::cout<<"Intern ID\t\t: "<<getInternid()<<std::endl;
    std::cout<<"Internship period\t: "<<internship_period<<std::endl;
    std::cout<<"Designation\t\t: "<<Employee::getDesignation()<<std::endl;
    if(Employee::getProjectId()>0)
    std::cout<<"Project ID\t\t: "<<Employee::getProjectId()<<std::endl;

}

void Intern::setinfo(std::string nam,std::string phn,std::string addr,std::string em,std::string cors,int period)
{
    Student::setName(nam);
    Student::setPhone_no(phn);
    Student::setAddress(addr);
    Student::setEmail(em);
    Employee::setDesignation(cors);
    setPeriod(period);
}

Intern::~Intern()
{
    delete[] password;
}

