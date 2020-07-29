#include"Customer.h"
#include"Employee.h"
#include"Student.h"
#include<ctime>
#include<string>
#include<bits/stdc++.h>
using namespace std;
Customer custReceiveInfo(Customer &c)
{
    string nam,phn,addr,em,desc,garbage;
    double b;
    int t,wk;
    WorkType w;
    cout<<"Enter your name: ";
    getline(cin,nam);
    cout<<"Enter your contact no.: ";
    getline(cin,phn);
    cout<<"Enter your address: ";
    getline(cin,addr);
    cout<<"Enter your email: ";
    cin>>em;
    cout<<"Enter your budget: ";
    cin>>b;
    cout<<"Enter the time(in months 1-24): ";
    cin>>t;
    cout<<"Enter the type:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
    cin>>wk;
    w=static_cast<WorkType>(wk);
    getline(cin,garbage);
    cout<<"Enter description: ";
    getline(cin,desc);
    Date dt2;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    dt2.day=dt1->tm_mday;
    dt2.month=1+dt1->tm_mon;
    dt2.year=1900+dt1->tm_year;
    c.setinfo(nam,phn,addr,em,b,t,desc,dt2,w);
    return c;
}
int main()
{
    Customer c1,c3;
    c1=custReceiveInfo(c1);
    c1.displayinfo();
    Customer c2("a b c","0000","sh sdj l","bhjhhj",70000,3,"hvhjbjh gvhbjhvg hghh",Date(1,2,2020),WorkType::Application_Development);
    c2.displayinfo();
    c3.displayinfo();
    cout<<endl;
    Employee e1("a b c","0000","sh sdj l","bhjhhj","Web_Development",7);
    Employee e2;
    e1.displayinfo();
    e2.displayinfo();
    cout<<endl;
    Student s1("a b c","0000","sh sdj l","bhjhhj","Web_Development",1000,Date(1,2,2020),2,"A");
    Student s2;
    s1.displayinfo();
    s2.displayinfo();
    return 0;
}
