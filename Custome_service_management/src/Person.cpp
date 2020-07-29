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
void Person::setPassword(char *c)
{
    delete[] password;
    password=new char[strlen(c)+1];
    strcpy(password,c);
}
void Person::displayinfo()
{
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"Phone number: "<<getPhone_no()<<std::endl;
    std::cout<<"Address: "<<getAddress()<<std::endl;
    std::cout<<"Email: "<<getEmail()<<std::endl;
}
