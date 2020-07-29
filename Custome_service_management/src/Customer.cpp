#include"Customer.h"
#include<ctime>
#include<bits/stdc++.h>
Customer::Customer():Person(),budget(0.0),duration(0),description(""),assigned_date(0,0,0),work(WorkType::Web_Development)
{
    cust_id++;
    generatePassword();
}
Customer::Customer(std::string nam,std::string phn,std::string addr,std::string em,double b,int t,std::string desc,Date d,WorkType w):Person(nam,phn,addr,em),budget(b),duration(t),assigned_date(d.day,d.month,d.year),work(w)
{
    setBudget(b);
    setDuration(t);
    setDescription(desc);
    //setProjectId(pid);
    setDate(d);
    setWork(w);
    cust_id++;
    generatePassword();
}
Customer::~Customer()
{

}
std::string Customer::getWork()
{
    if(work==WorkType::Web_Development)
        return std::string("Web Development");
    else if(work==WorkType::Mobile_Development)
        return std::string("Mobile Development");
    else if(work==WorkType::Data_Science)
        return std::string("Data Science");
    else if(work==WorkType::Application_Development)
        return std::string("Application Development");
    else if(work==WorkType::Embedded_Systems)
        return std::string("Embedded Systems");
    else if(work==WorkType::Cloud_Computing)
        return std::string("Cloud Computing");
    else
        return std::string("");
}
bool Customer::isServed(Date dt)
{
    Date dt2;
    dt2.day=assigned_date.day;
    dt2.month=assigned_date.month+getDuration();
    dt2.year=assigned_date.year;
    if(dt2.month>12) dt2.year++;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    if((dt1->tm_mday==dt2.day)&&(1+dt1->tm_mon==dt2.month)&&(1900+dt1->tm_year==dt2.year)) return 1;
    else return 0;
}
void Customer::generatePassword()
{
    delete[] password;
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char number[]="0123456789";
    char special[]="!@#$%&-_(),:{}";
    password=new char[15];
    int cnt=0;
    for(int i=0;i<5;i++)
    {
        password[cnt]=upper[rand()%26];
        cnt++;
    }
    for(int i=0;i<4;i++)
    {
        password[cnt]=lower[rand()%26];
        cnt++;
    }
    password[cnt]=number[rand()%10];
    cnt++;
    for(int i=0;i<2;i++)
    {
        password[cnt]=special[rand()%14];
        cnt++;
    }
    password[cnt]='\0';
}
void Customer::displayinfo()
{
    Person::displayinfo();
    std::cout<<"ID: "<<cust_id<<std::endl;
    std::cout<<"Budget: "<<getBudget()<<std::endl;
    std::cout<<"Duration: "<<getDuration()<<std::endl;
    std::cout<<"Cost: "<<getCost()<<std::endl;
    std::cout<<"Date Assigned: "<<getDate().day<<"/"<<getDate().month<<"/"<<getDate().year<<"/"<<std::endl;
    std::cout<<"Project Type: "<<getWork()<<std::endl;
}
