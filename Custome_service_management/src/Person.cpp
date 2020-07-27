#include "Person.h"
#include<iostream>

Person::Person(string nam,long long int phn,string addr,string em):name(""),phone_no(0),address(""),email("")
{
    //ctors
    Setname(nam);
    Setphone_no(phn);
    Setaddress(addr);
    Setemail(em);
    password=new char[1];
    strcpy(password,"");
}

Person::~Person()
{
    //dtor
    delete[] password;
}
void Person::Setpassword(char *c)
        {
            delete[] password;
            password=new char[strrlen(c)+1];
            strcpy(paasword,c);
        }

void Person::dispalyinfo()
{
    cout<<"Name: "<<Getname()<<endl;
    cout<<"Phone number: "<<Getphone_no()<<endl;
    cout<<"City: "<<Getaddress()<<endl;
    cout<<"Email: "<<Getemail()<<endl;
}
