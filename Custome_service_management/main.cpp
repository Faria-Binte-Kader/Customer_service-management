#include"Customer.h"
#include"Employee.h"
#include"Student.h"
#include<ctime>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void createproject(Employee e[],int m1,int m2,int m3)
{
    cout<<"Member 1: "<<endl;
    e[m1].displayinfo();
    cout<<"Member 2: "<<endl;
    e[m2].displayinfo();
    cout<<"Member 3: "<<endl;
    e[m3].displayinfo();
    //Project object will be created. will figure out after project class in done. dont bother :3
}
struct Senior
{
    int idx;
    double bonus;
    int ID;
    int expr;
};
struct Junior
{
    int idx;
    double bonus;
    int ID;
    int expr;
};
struct Entry
{
    int idx;
    double bonus;
    int ID;
    int expr;
};
void generateOption(double b,int t,string w,Employee e[])
{
    int index[100][3],option[100][3],ex[100][3],op;
    double cost[100];
    Senior senior[100];
    Junior junior[100];
    Entry entry[100];
    int s=0,j=0,en=0,cnt=0;
    double temp,temp2,temp3,pro;
    for(int i=0;i<20;i++)
    {
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Senior"&&(e[i].getBonus()*t)<=b)
        {
            senior[s].idx=i;
            senior[s].bonus=e[i].getBonus()*t;
            senior[s].ID=e[i].getEmployeeID();
            senior[s].expr=e[i].getExperience();
            s++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Junior"&&(e[i].getBonus()*t)<=b)
        {
            junior[j].idx=i;
            junior[j].bonus=e[i].getBonus()*t;
            junior[j].ID=e[i].getEmployeeID();
            junior[j].expr=e[i].getExperience();
            j++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Entry Level"&&(e[i].getBonus()*t)<=b)
        {
            entry[en].idx=i;
            entry[en].bonus=e[i].getBonus()*t;
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
            if((temp+junior[k].bonus)>b) break;
            else temp2=temp+junior[k].bonus;
            for(int l=0;l<en;l++)
            {
                pro=((temp2+entry[l].bonus)*50)/100;
                if((temp2+entry[l].bonus+pro)>b) break;
                else
                {
                    temp3=temp2+entry[l].bonus+pro;
                    cost[cnt]=temp3;
                    index[cnt][0]=senior[i].idx;
                    index[cnt][1]=junior[k].idx;
                    index[cnt][2]=entry[l].idx;
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
    if(cnt==0)
    {
        cout<<"No teams available within budget"<<endl;
        return;
    }
    for(int i=0;i<cnt;i++)
    {
        cout<<"Option: "<<i+1<<endl;
        cout<<"Member 1: "<<option[i][0]<<" [Experience: "<<ex[i][0]<<" years]"<<endl;
        cout<<"Member 2: "<<option[i][1]<<" [Experience: "<<ex[i][1]<<" years]"<<endl;
        cout<<"Member 3: "<<option[i][2]<<" [Experience: "<<ex[i][2]<<" years]"<<endl;
        cout<<"Cost: "<<cost[i]<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
    }
    cout<<"Which option do you choose?"<<endl;
    cin>>op;
    createproject(e,index[op-1][0],index[op-1][1],index[op-1][2]);
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
    Employee e[20];
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
    e[10].setinfo("a","123","abc","def","Web Development",11);
    e[11].setinfo("b","123","abc","def","Web Development",15);
    e[12].setinfo("c","123","abc","def","Data Science",11);
    e[13].setinfo("d","123","abc","def","Web Development",9);
    e[14].setinfo("e","123","abc","def","Data Science",5);
    e[15].setinfo("f","123","abc","def","Data Science",7);
    e[16].setinfo("g","123","abc","def","Web Development",4);
    e[17].setinfo("h","123","abc","def","Data Science",3);
    e[18].setinfo("i","123","abc","def","Data Science",2);
    e[19].setinfo("j","123","abc","def","Web Development",1);
    Customer c1;
    custReceiveInfo(c1);
    c1.displayinfo();
    generateOption(c1.getBudget(),c1.getDuration(),c1.getWork(),e);
    return 0;
}
