#include"Customer.h"
#include"Employee.h"
#include"Student.h"
#include<ctime>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct Senior
{
    double bonus;
    int ID;
    int expr;
};
struct Junior
{
    double bonus;
    int ID;
    int expr;
};
struct Entry
{
    double bonus;
    int ID;
    int expr;
};
void generateOption(double b,string w,Employee e[])
{
    int option[100][3],ex[100][3];
    double cost[100];
    Senior senior[100];
    Junior junior[100];
    Entry entry[100];
    int s=0,j=0,en=0,cnt=0;
    double pro=(b*25)/100;
    double temp;
    b=b-pro;
    for(int i=0;i<10;i++)
    {
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Senior"&&e[i].getBonus()<=b)
        {
            senior[s].bonus=e[i].getBonus();
            senior[s].ID=e[i].getEmployeeID();
            senior[s].expr=e[i].getExperience();
            s++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Junior"&&e[i].getBonus()<=b)
        {
            junior[j].bonus=e[i].getBonus();
            junior[j].ID=e[i].getEmployeeID();
            junior[j].expr=e[i].getExperience();
            j++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Entry Level"&&e[i].getBonus()<=b)
        {
            entry[en].bonus=e[i].getBonus();
            entry[en].ID=e[i].getEmployeeID();
            entry[en].expr=e[i].getExperience();
            en++;
        }
    }
    for(int i=0;i<s;i++)
    {
        temp=senior[i].bonus;
        for(int k=0;k<j;k++)
        {
            temp=temp+junior[k].bonus;
            if(temp>b) break;
            for(int l=0;l<en;l++)
            {
                temp=temp+entry[l].bonus;
                if(temp>b) break;
                else
                {
                    cost[cnt]=temp+pro;
                    option[cnt][0]=senior[i].ID;
                    option[cnt][1]=junior[k].ID;
                    option[cnt][2]=entry[l].ID;
                    ex[cnt][0]=senior[i].expr;
                    ex[cnt][1]=junior[k].expr;
                    ex[cnt][2]=entry[l].expr;
                    cnt++;
                }
            }
        }
    }
    for(int i=0;i<cnt;i++)
    {
        cout<<"Option: "<<i+1<<endl;
        cout<<"Member 1: "<<option[i][0]<<" [Experience: "<<ex[i][0]<<"]"<<endl;
        cout<<"Member 2: "<<option[i][1]<<" [Experience: "<<ex[i][1]<<"]"<<endl;
        cout<<"Member 3: "<<option[i][2]<<" [Experience: "<<ex[i][2]<<"]"<<endl;
        cout<<"Cost: "<<cost[i]<<endl;
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
}
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
    Employee e[10];
    e[0].setinfo("a","123","abc","def","Web Development",11);
    e[1].setinfo("b","123","abc","def","Web Development",15);
    e[2].setinfo("c","123","abc","def","Data Science",11);
    e[3].setinfo("d","123","abc","def","Web Development",9);
    e[4].setinfo("e","123","abc","def","Data Science",5);
    e[5].setinfo("f","123","abc","def","Data Science",7);
    e[6].setinfo("g","123","abc","def","Web Development",4);
    e[7].setinfo("h","123","abc","def","Data Science",3);
    e[8].setinfo("i","123","abc","def","Data Science",2);
    e[9].setinfo("j","123","abc","def","Web Development",1);
    for(int i=0;i<10;i++)
    {
        e[i].displayinfo();
        cout<<endl;
        cout<<endl;
    }
    generateOption(1000000,"Web Development",e);
    return 0;
}
