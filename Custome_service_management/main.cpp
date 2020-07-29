#include"Customer.h"
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
void receiveInfo(Customer &c1)
{
    string nam,phn,addr,em,desc;
    double b;
    int t,wk;
    WorkType w;
    cout<<"Enter your name: ";
    getline(cin,nam);
    cout<<endl;
    cout<<"Enter your contact no.: ";
    cin>>phn;
    cout<<endl;
    cout<<"Enter your address: ";
    getline(cin,addr);
    cout<<endl;
    cout<<"Enter your email: ";
    cin>>em;
    cout<<endl;
    cout<<"Enter your budget: ";
    cin>>b;
    cout<<endl;
    cout<<"Enter the time(in months 1-24): ";
    cin>>t;
    cout<<endl;
    cout<<"Enter the type(0.Web_Development/1.Mobile_Development/2.Data_Science/3.Application_Development/4.Embedded_Systems/5.Cloud_Computing): ";
    cin>>wk;
    w=static_cast<WorkType>(wk);
    cout<<endl;
    cout<<"Enter description: ";
    getline(cin,desc);
    cout<<endl;
    Date dt2;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    dt2.day=dt1->tm_mday;
    dt2.month=dt1->tm_mon;
    dt2.year=dt1->tm_year;
//    c1.SetName(nam);
//    c1.SetPhone_no(phn);
//    c1.SetAddress(addr);
//    c1.SetEmail(em);
//    c1.setBudget(b);
//    c1.setDuration(t);
//    c1.setDescription(desc);
//    c1.setDate(dt2);
//    c1.setWork(w);
    c1(nam,phn,addr,em,b,t,desc,dt2,w);
}
int main()
{
    Customer c1;
    receiveInfo(c1);
    c1.displayinfo();
    return 0;
}
