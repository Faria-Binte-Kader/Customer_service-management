#include"Customer.h"
#include"Employee.h"
#include"Student.h"
#include"Intern.h"
#include"Project.h"
#include"Company.h"
#include<ctime>
#include<string>
#include<bits/stdc++.h>
int M1;
int M2;
int M3;
int Total_project;
double Cost;
using namespace std;

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
bool generateOption(Customer &c,Employee e[],int total)
{
    double b=c.getBudget();
    int t=c.getDuration();
    string w=c.getWork();
    int index[100][3],option[100][3],ex[100][3],op;
    double cost[100];
    Senior senior[100];
    Junior junior[100];
    Entry entry[100];
    int s=0,j=0,en=0,cnt=0;
    double temp,temp2,temp3,pro;
    for(int i=0; i<total; i++)
    {
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Senior"&&(e[i].getBonus()*t)<=b&&e[i].getProjectId()==0)
        {
            senior[s].idx=i;
            senior[s].bonus=e[i].getBonus()*t;
            senior[s].ID=e[i].getEmployeeID();
            senior[s].expr=e[i].getExperience();
            s++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Junior"&&(e[i].getBonus()*t)<=b&&e[i].getProjectId()==0)
        {
            junior[j].idx=i;
            junior[j].bonus=e[i].getBonus()*t;
            junior[j].ID=e[i].getEmployeeID();
            junior[j].expr=e[i].getExperience();
            j++;
        }
        if(e[i].getDesignation()==w&&e[i].getPosition()=="Entry Level"&&(e[i].getBonus()*t)<=b&&e[i].getProjectId()==0)
        {
            entry[en].idx=i;
            entry[en].bonus=e[i].getBonus()*t;
            entry[en].ID=e[i].getEmployeeID();
            entry[en].expr=e[i].getExperience();
            en++;
        }
    }
    for(int i=0; i<s; i++)
    {
        temp=senior[i].bonus;
        for(int k=0; k<j; k++)
        {
            if((temp+junior[k].bonus)>b)
                break;
            else
                temp2=temp+junior[k].bonus;
            for(int l=0; l<en; l++)
            {
                pro=(temp2+entry[l].bonus)*50/100;
                if((temp2+entry[l].bonus+pro)>b)
                    break;
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
        cout<<"No team available within budget"<<endl;
        return false;
    }
    for(int i=0; i<cnt; i++)
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
    M1=index[op-1][0];
    M2=index[op-1][1];
    M3=index[op-1][2];
    Cost=cost[op-1];
    cout<<"Do you want to confirm?"<<endl;
    cout<<"1. Yes 2. No"<<endl;
    int confirm;
    cin>>confirm;
    if(confirm==1)
        return true;
    else if(confirm==2)
        return false;
}
Student stdReceiveInfo(Student &s)
{
    string nam,phn,addr,em,w,w1,w2,garbage;
    double crsfee;
    int drtn=0;
    getline(cin,garbage);    //dummy getline
    cout<<"Enter your name: ";
    getline(cin,nam);
    cout<<"Enter your contact no.: ";
    getline(cin,phn);
    cout<<"Enter your address: ";
    getline(cin,addr);
    cout<<"Enter your email: ";
    cin>>em;
    cout<<"Enter the type:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
    cin>>w1>>w2;
    w=w1+" "+w2;
    if(w=="Web Development")
    {
        crsfee=10000;
        drtn=90;
    }
    else if(w=="Mobile Development")
    {
        crsfee=11000;
        drtn=90;
    }
    else if(w=="Data Science")
    {
        crsfee=15000;
        drtn=120;
    }
    else if(w=="Application Development")
    {
        crsfee=10000;
        drtn=60;
    }
    else if(w=="Embedded Systems")
    {
        crsfee=15000;
        drtn=120;
    }
    else if(w=="Cloud Computing")
    {
        crsfee=11000;
        drtn=75;
    }
    Date dt2;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    dt2.day=dt1->tm_mday;
    dt2.month=1+dt1->tm_mon;
    dt2.year=1900+dt1->tm_year;
    s.setInfo(nam,phn,addr,em,w,crsfee,dt2,drtn,"Not completed yet");
    return s;
}

Employee empReceiveInfo(Employee &e)
{
    string nam,phn,addr,em,desc,garbage,w,w1,w2;
    double b;
    //WorkType w;
    getline(cin,garbage);    //dummy getline
    cout<<"Enter Employee's name: ";
    getline(cin,nam);
    cout<<"Enter Employee's contact no.: ";
    getline(cin,phn);
    cout<<"Enter Employee's address: ";
    getline(cin,addr);
    cout<<"Enter Employee's email: ";
    cin>>em;
    cout<<"Enter Designation: ";
    cin>>w1>>w2;
    w=w1+" "+w2;
    //w=static_cast<WorkType>(wk);
    cout<<"Enter experience time: ";
    cin>>b;
    //getline(cin,garbage);

    e.setinfo(nam,phn,addr,em,w,b);
    return e;
}

Customer custReceiveInfo(Customer &c)
{
    string nam,phn,addr,em,desc,garbage;
    double b;
    int t,wk;
    WorkType w;
    getline(cin,garbage);    //dummy getline
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

Employee* intrReceiveInfo(Student &s,Employee* i)
{
    string nam,phn,addr,em,d;
    int p;
    nam=s.getName();
    phn=s.getPhone_no();
    addr=s.getAddress();
    em=s.getEmail();
    d=s.getCourse();
    i=new Intern();
    i->setinfo(nam,phn,addr,em,d,30);
    return i;
}

int main()
{
    Date d(24,4,2020);
    Total_project=0;
    int Total_customer=0;
    int Total_student=0;
    int Total_intern=0;
    int et=0;
    Employee e[100];
    Customer c[20];
    Student s[50];
    s[0].setInfo("Nisa","123","abc","def","Web Development",10.0,d,90,"A");
    string pas=s[0].getPassword();
    cout<<"Login as student using Nisa and this password to check intern\n";
    cout<<pas<<endl;  //to check intern, login using name- Nisa , and password from the first line
    Total_student++;
    Project *p[10];
    Company co1("ABC");
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
    et+=20;
    Employee* intern[20];
    for(int i=0; i<et; i++)
    {
        co1.addEmployee(e[i]);
    }
    cout<<"WELCOME!\n\n";
    while(1)
    {

        cout<<"1. Sign up\n";
        cout<<"2. Login\n";
        cout<<"3. Administrator\n";
        cout<<"4. Exit\n";
        cout<<"Press 1,2,3 or 4\n";
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"1. User\n";
            cout<<"2. Student\n";
            int i;
            cin>>i;
            if(i==1)
            {

                Total_customer++;
                custReceiveInfo(c[Total_customer-1]);
                cout<<"Here's your password\n\n";
                char* pass=c[Total_customer-1].getPassword();
                cout<<pass<<endl;
                cout<<"Would you like to change your password?\n1.Yes\n2.No\n";
                int paschoic;
                cin>>paschoic;
                if(paschoic==1)
                {
                    cout<<"Please create a password (12 characters maximum)"<<endl;
                    cin>>pass;
                    c[Total_customer-1].setPassword(pass);
                    cout<<"You've chosen to use "<<c[Total_customer-1].getPassword()<<" as your password."<<endl;
                }
                else if(paschoic==2)
                {
                    cout<<"You've chosen to use "<<c[Total_customer-1].getPassword()<<" as your password."<<endl;
                }
                cout<<"Please login to continue\n\n";
            }

            else if(i==2)
            {
                Total_student++;
                stdReceiveInfo(s[Total_student-1]);
                cout<<"Here's your password\n\n";
                char* pass=s[Total_student-1].getPassword();
                cout<<pass<<endl;
                cout<<"Would you like to change your password?\n1.Yes\n2.No\n";
                int paschoic;
                cin>>paschoic;
                if(paschoic==1)
                {
                    cout<<"Please create a password (12 characters maximum)"<<endl;
                    cin>>pass;
                    s[Total_student-1].setPassword(pass);
                    cout<<"You've chosen to use "<<s[Total_student-1].getPassword()<<" as your password."<<endl;
                }
                else if(paschoic==2)
                {
                    cout<<"You've chosen to use "<<s[Total_student-1].getPassword()<<" as your password."<<endl;
                }
                cout<<"Please login to continue\n\n";

            }
        }

        else if(n==2)
        {
            cout<<"1. User\n";
            cout<<"2. Student\n";
            int i;
            cin>>i;
            if(i==1)
            {
                cout<<"Enter your username: ";
                string name,pass,pass2;
                cin>>name;
                int b;
                for(int j=0; j<Total_customer ; j++)
                    if(name==c[j].getName())
                    {
                        pass=c[j].getPassword();
                        b=j;
                    }

                cout<<"Enter password: ";
                cin>>pass2;
                if(pass==pass2)
                {
                    if(c[b].GetProjectId()==0)
                    {

                        cout<<"Choose a group of 3 employees as your preference\n\n";
                        if(generateOption(c[Total_customer-1],e,et)==true)
                        {
                            p[Total_project]=new Project();
                            p[Total_project]->setInfo(c[Total_customer-1],e[M1],e[M2],e[M3],Cost);
                            int b=p[Total_project]->getProjectId();
                            co1.addCustomer(c[Total_customer-1]);
                            co1.editProjectid(c[Total_customer-1],e[M1],e[M2],e[M3],p[Total_project]->getProjectId());
                            Total_project++;

                        }
                        co1.updateCustomerlist();
                        co1.updateEmployeelist();
                    }
                    else
                    {
                        cout<<"Project details:\n\n";
                        for(int k=0; k<Total_project; k++)
                        {
                            if(p[k]->getProjectId()==c[b].GetProjectId())
                                p[k]->projectDetails();
                        }
                    }
                }
                else
                {
                    cout<<"Incorrect password. Login again\n\n";
                }

            }

            else if(i==2)
            {
                //
                cout<<"Enter your username: ";
                string name,pass,pass2;
                cin>>name;
                int b;
                for(int j=0; j<Total_student ; j++)
                    if(name==s[j].getName())
                    {
                        pass=s[j].getPassword();
                        b=j;
                    }

                cout<<"Enter password: ";
                cin>>pass2;
                if(pass==pass2)
                {
                    s[b].displayinfo();
                    if(s[b].isQualified()==true && (Total_intern==0 || intern[Total_intern-1]->getName()!=s[b].getName()))
                    {
                        cout<<"We are glad to offer you as an intern to help you gain experience"<<endl;
                        cout<<"Do you want to work the internship?"<<endl;
                        cout<<"1. Yes 2. No"<<endl;
                        int a;
                        cin>>a;
                        if(a==1)
                        {
                            Total_intern++;
                            intern[Total_intern-1]=intrReceiveInfo(s[b],intern[Total_intern-1]);
                            cout<<"We will contact you via email with more information. Congratulations!\n\n";
                            intern[0]->displayinfo();
                        }
                        else if(a==2)
                            cout<<"Hope to see you again!\n\n";
                    }
                    else if(s[b].isQualified()==true && intern[Total_intern-1]->getName()==s[b].getName())
                    {
                        cout<<"You are already an Intern.\n\n";
                        intern[0]->displayinfo();
                    }

                }
                else
                {
                    cout<<"Incorrect password. Login again\n\n";
                }

            }
        }

        else if(n==3)
        {
            while(1)
            {
                cout<<endl;
                cout<<"1. Add Employee\n";
                cout<<"2. Show Employee List\n";
                cout<<"3. Show Customer List\n";
                cout<<"4. Show Project List\n";
                cout<<"5. Show Course and Student Information\n";
                cout<<"6. Show Intern List\n";
                cout<<"7. Go Back\n\n";

                int n;
                cin>>n;

                if(n==1)
                {
                    empReceiveInfo(e[et]);
                    //e1.setinfo("k","123","abc","def","Web Development",11);
                    co1.addEmployee(e[et]);
                    et++;
                }

                else if(n==2)
                {
                    co1.showemployee();
                }

                else if(n==3)
                {
                    if(Total_customer==0)
                        cout<<"No Customers to show"<<endl;
                    else
                        co1.showCustomer();
                }

                else if(n==4)
                {
                    for(int i=0; i<Total_project; i++)
                        p[i]->projectDetails();
                }

                else if(n==5)
                {
                    int w=0,a=0,c=0,e=0,m=0, d=0;
                    for(int i=0; i<Total_student; i++)
                    {
                        if(s[i].getCourse()=="Web Development" && s[i].hasCompleted()==false)
                            w++;
                        else if(s[i].getCourse()=="Mobile Development" && s[i].hasCompleted()==false)
                            m++;
                        else if(s[i].getCourse()=="Application Development" && s[i].hasCompleted()==false)
                            a++;
                        else if(s[i].getCourse()=="Cloud Computing" && s[i].hasCompleted()==false)
                            c++;
                        else if(s[i].getCourse()=="Data Science" && s[i].hasCompleted()==false)
                            d++;
                        else if(s[i].getCourse()=="Embedded Systems" && s[i].hasCompleted()==false)
                            e++;
                    }
                    cout<<endl;
                    cout<<"Web Development : "<<w<<endl;
                    cout<<"Mobile Development : "<<m<<endl;
                    cout<<"Application Development : "<<a<<endl;
                    cout<<"Cloud Computing : "<<c<<endl;
                    cout<<"Data Science : "<<d<<endl;
                    cout<<"Embedded Systems : "<<e<<endl;

                }

                else if(n==6)
                {
                    if(Total_intern==0)
                        cout<<"No interns to show\n";
                    else
                    {
                        for(int i=0; i<Total_intern; i++)
                        {
                            intern[i]->displayinfo();
                            cout<<endl;
                        }
                    }
                }

                else if(n==7)
                {
                    break;
                }
            }

        }

        else if(n==4)
        {
            break;
        }

    }

    for(int i=0; i<Total_intern; i++)
        delete intern[i];
    for(int i=0; i<Total_project; i++)
        delete p[i];
    return 0;

}
