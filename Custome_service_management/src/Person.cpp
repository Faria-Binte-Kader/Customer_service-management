#include"Person.h"
#include<bits/stdc++.h>
Person::Person():name(""),phone_no(0),address(""),email("")
{

}
Person::Person(std::string nam,std::string phn,std::string addr,std::string em):name(nam),phone_no(phn),address(addr),email(em)
{
    SetName(nam);
    SetPhone_no(phn);
    SetAddress(addr);
    SetEmail(em);
    password=new char[1];
    strcpy(password,"");
}
Person::~Person()
{
    delete[] password;
}
void Person::SetPassword(char *c)
{
    delete[] password;
    password=new char[strlen(c)+1];
    strcpy(password,c);
}
void Person::displayinfo()
{
    std::cout<<"Name: "<<GetName()<<std::endl;
    std::cout<<"Phone number: "<<GetPhone_no()<<std::endl;
    std::cout<<"Address: "<<GetAddress()<<std::endl;
    std::cout<<"Email: "<<GetEmail()<<std::endl;
}
