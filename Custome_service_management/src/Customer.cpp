#include"Customer.h"
#include<dos.h>

using namespace std;
Customer::Customer():Person(),budget(0.0),time(0),assigned_date(0,0,0),work(WorkType::Web_Development)
{
    //ctor
    generatePassword();
}
Customer::Customer(string n,string ph,string ad,string em,double b,int t,string desc,Date d,WorkType w):Person(n,ph,ad,em),budget(0.0),time(0),assigned_date(0,0,0),work(WorkType::Web_Development)
{
    SetBudget(b);
    SetTime(t);
    SetDescription(desc);
    //setProjectId(pid);
    SetDate(d);
    SetWork(w);
    generatePassword();
}
Customer::~Customer()
{

}
string Customer::getWork()
{
    if(work==WorkType::Web_Development)
        return string("Web Development");
    else if(work==WorkType::Mobile_Development)
        return string("Mobile Development");
    else if(work==WorkType::Data_Science)
        return string("Data Science");
    else if(work==WorkType::Application_Development)
        return string("Application Development");
    else if(work==WorkType::Embedded_Systems)
        return string("Embedded Systems");
    else if(work==WorkType::Cloud_Computing)
        return string("Cloud Computing");
    else
        return string("");
}
/*bool Customer::isServed(Date dt)
{
    struct date dt;
    Date dt2;
    dt2.day=assigned_date.day;
    dt2.month=assigned_date.month+GetTime();
    dt2.year=assigned_date.year;
    if(dt2.month>12) dt2.year++;
    Customer::GetDate(&dt);
    if((dt.da_day==dt2.day)&&(dt.da_month==dt2.month)&&(dt.da_year==dt2.year)) return 1;
    else return 0;
}*/
void Customer::generatePassword()
{
    delete [] password;
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[]="!@#$%&-_(),:{}";
    char number[]="0123456789";
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
        password[cnt]=special[rand()%18];
        cnt++;
    }
    password[cnt]='\0';

}
void Customer::displayinfo()
{
    Person::displayinfo();
    cout<<"Budget: "<<GetBudget()<<endl;
    cout<<"Time: "<<GetTime()<<endl;
    cout<<"Cost: "<<GetCost()<<endl;
    cout<<"Date Assigned: "<<Getname()<<endl;
    cout<<"Project Type: "<<Getname()<<endl;
}
