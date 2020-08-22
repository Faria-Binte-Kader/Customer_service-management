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
      std::cout<<"Name: "<<Student::getName()<<std::endl;
      std::cout<<"Phone number: "<<Student::getPhone_no()<<std::endl;
      std::cout<<"Address: "<<Student::getAddress()<<std::endl;
      std::cout<<"Email: "<<Student::getEmail()<<std::endl;
      //std::cout<<"Password "<<Employee::password<<std::endl;
      std::cout<<"Intern id: "<<getInternid()<<std::endl;
      std::cout<<"Internship period: "<<internship_period<<std::endl;
      std::cout<<"Designation: "<<Employee::getDesignation()<<std::endl;
      //std::cout<<"Projectid: "<<getProjectid()<<std::endl;

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
    //dtor
}
