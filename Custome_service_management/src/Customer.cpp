#include"Customer.h"
#include<ctime>
#include<bits/stdc++.h>
Customer::Customer():Person(),budget(0.0),duration(0),description(""),assigned_date(0,0,0),work(WorkType::Web_Development)
{
    total_customer++;
    generatePassword();
    SetProjectId(0);
}
Customer::Customer(std::string nam,std::string phn,std::string addr,std::string em,double b,int t,std::string desc,Date d,WorkType w):Person(nam,phn,addr,em),budget(0.0),duration(0),description(""),assigned_date(0,0,0),work(WorkType::Web_Development)
{
    setBudget(b);
    setDuration(t);
    setDescription(desc);
    setDate(d);
    setWork(w);
    total_customer++;
    generatePassword();
    SetProjectId(0);
}
Customer::~Customer()
{
    delete[] password;
}
int Customer::total_customer=0;
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

bool Customer::isServed()
{
    Date dt2;
    dt2.day=assigned_date.day;
    dt2.month=assigned_date.month+getDuration();
    dt2.year=assigned_date.year;
    if(dt2.day==0&&dt2.month==0&&dt2.year==0) return 0;
    if(dt2.month>12) dt2.year++;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    if(1900+dt1->tm_year>dt2.year) return 1;
    if(1900+dt1->tm_year==dt2.year)
    {
        if(1+dt1->tm_mon>dt2.month) return 1;
        else if(1+dt1->tm_mon==dt2.month)
        {
            if(dt1->tm_mday>=dt2.day) return 1;
            else return 0;
        }
        else return 0;
    }
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
    for(int i=0; i<5; i++)
    {
        password[cnt]=upper[rand()%26];
        cnt++;
    }
    for(int i=0; i<4; i++)
    {
        password[cnt]=lower[rand()%26];
        cnt++;
    }
    password[cnt]=number[rand()%10];
    cnt++;
    for(int i=0; i<2; i++)
    {
        password[cnt]=special[rand()%14];
        cnt++;
    }
    password[cnt]='\0';
}
void Customer::displayinfo()
{
    Person::displayinfo();
    std::cout<<"Customer ID\t\t: "<<getCustID()<<std::endl;
    std::cout<<"Budget\t\t\t: "<<getBudget()<<std::endl;
    std::cout<<"Duration\t\t: "<<getDuration()<<std::endl;
    std::cout<<"Cost\t\t\t: "<<getCost()<<std::endl;
    std::cout<<"Description\t\t: "<<getDescription()<<std::endl;
    std::cout<<"Date Assigned\t\t: "<<getDate().day<<"/"<<getDate().month<<"/"<<getDate().year<<std::endl;
    std::cout<<"Project Type\t\t: "<<getWork()<<std::endl;
    std::cout<<"Project ID\t\t: "<<GetProjectId()<<std::endl;
    std::cout<<"Project Condition\t: ";
    if(isServed()) std::cout<<"Served."<<std::endl;
    else std::cout<<"Not served yet."<<std::endl;
}
void Customer::setinfo(std::string nam,std::string phn,std::string addr,std::string em,double b,int t,std::string desc,Date dt2,WorkType w)
{
    Person::setName(nam);
    Person::setPhone_no(phn);
    Person::setAddress(addr);
    Person::setEmail(em);
    setBudget(b);
    setDuration(t);
    setDescription(desc);
    setDate(dt2);
    setWork(w);
}

Customer Customer::operator =(Customer& c1)
{

    cust_id=c1.cust_id;
    name=c1.name;
    phone_no=c1.phone_no;
    address=c1.address;
    email=c1.email;
    budget=c1.budget;
    duration=c1.duration;
    description=c1.description;
    assigned_date=c1.assigned_date;
    work=c1.work;
    project_id=c1.project_id;
    final_cost=c1.final_cost;
    return *this;

}


