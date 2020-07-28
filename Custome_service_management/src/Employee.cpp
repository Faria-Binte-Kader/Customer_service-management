#include "Employee.h"
#include<bits/stdc++.h>
using namespace std;

Employee::Employee():Person(),designation(Designation::Web_Development),experience(0),salary(0.0),no_of_projects(0)
{
    //ctor

    employee_id++;
    setEmployeeId(employee_id);
    generatePassword();
}

Employee::Employee(string nam,string phn,string addr,string em,Designation des,int ex,double salary,int nopro):Person(nam,phn,addr,em),designation(Designation::Web_Development),experience(0),salary(0.0),no_of_projects(0)
{
    //ctor
    employee_id++;
    Setdesignation(des);
    Setexperience(ex);
    setEmployeeId(employee_id);
    Setposition(ex);
    generatePassword();
}

Employee::~Employee()
{
    //dtor
}



string Employee::Getdesignation()
{
    if(designation==Designation::Web_Development)
        return string("Web Development");
    else if(designation==Designation::Mobile_Development)
        return string("Mobile Development");
    else if(designation==Designation::Data_Science)
        return string("Data Science");
    else if(designation==Designation::Application_Development)
        return string("Application Development");
    else if(designation==Designation::Embedded_Systems)
        return string("Embedded Systems");
    else if(designation==Designation::Cloud_Computing)
        return string("Cloud Computing");
    else
        return string("");
}
/*void Employee::addCustomer(Customer c)
{
    if(workingfor+1>10) cout<<"Occupied"<<endl;
    else
    {
        customer[workingfor]=c;

        workingfor++;
    }
bool Employee::removeCustomer(int index)
{

    if(index+1>workingfor||index<0) return false;
    else if(index+1==workingfor)
    {
        workingfor--;
        return true;
    }
}*/

void Employee::Setposition(int a)
{
    if(a>=3)
        position="Junior group 1";
    else if(a<=6 && a>3)
        position="Junior group 2";
    else if(a>6)
        position="Senior";
}

void Employee::displayinfo()
{
    Person::displayinfo();
    cout<<Getdesignation()<<endl;
    cout<<Getexperience()<<endl;
    cout<<Getposition()<<endl;
    cout<<Getsalary()<<endl;
    //cout<<getno_ofprojects()<<endl;

}
void Employee::generatePassword()
{
    delete [] password;
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[]="!@#$%&-_(),:{}";
    char number[]="0123456789";
    password= new char[15];
    int b=0;
    for(int i=0; i<5; i++)
    {
        password[b]=upper[rand()%26];
        b++;
    }
    for(int i=0; i<4; i++)
    {
        password[b]=lower[rand()%26];
        b++;
    }
    password[b]=number[rand()%10];
    b++;
    for(int i=0; i<2; i++)
    {
        password[b]=special[rand()%18];
        b++;
    }
    std::random_shuffle(password,password+12);
    password[12]='\0';

}
