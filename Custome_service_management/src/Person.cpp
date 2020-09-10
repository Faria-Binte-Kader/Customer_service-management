#include"Person.h"
#include<bits/stdc++.h>
Person::Person():name(""),phone_no(""),address(""),email("")
{
    password=new char[1];
    strcpy(password,"");
}
Person::Person(std::string nam,std::string phn,std::string addr,std::string em):name(nam),phone_no(phn),address(addr),email(em)
{
    setName(nam);
    setPhone_no(phn);
    setAddress(addr);
    setEmail(em);
    password=new char[1];
    strcpy(password,"");
}

Person::~Person()
{
    delete[] password;
}

std::string Person::getPassword()
{
    std::string pas=password;
    return pas;
}

void Person::setPassword(std::string c)
{
    delete[] password;
    password=new char[sizeof(c)+1];
    strcpy(password,c.c_str());
}

void Person::displayinfo()
{
    std::cout<<"Name\t\t\t: "<<getName()<<std::endl;
    std::cout<<"Phone number\t\t: "<<getPhone_no()<<std::endl;
    std::cout<<"Address\t\t\t: "<<getAddress()<<std::endl;
    std::cout<<"Email\t\t\t: "<<getEmail()<<std::endl;
}
