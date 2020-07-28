#include "Person.h"
#include<bits/stdc++.h>
using namespace std;

Person::Person()
{}
Person::Person(string nam,string phn,string addr,string em):name(""),phone_no(0),address(""),email("")
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
            password=new char[strlen(c)+1];
            strcpy(password,c);
        }

void Person::displayinfo()
{
    cout<<"Name: "<<Getname()<<endl;
    cout<<"Phone number: "<<Getphone_no()<<endl;
    cout<<"City: "<<Getaddress()<<endl;
    cout<<"Email: "<<Getemail()<<endl;
}
