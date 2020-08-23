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
bool generateOption(Customer &c,Employee e[])
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
    for(int i=0; i<20; i++)
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
                pro=((temp2+entry[l].bonus)*50)/100;
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
        cout<<"No teams available within budget"<<endl;
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

Employee empReceiveInfo(Employee &e)
{
    string nam,phn,addr,em,desc,garbage,w,w1,w2;
    double b;
    int t,wk;
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
    cout<<"Enter Intership Period: "<<endl;
    cin>>p;
    i=new Intern();
    i->setinfo(nam,phn,addr,em,d,p);
    return i;
}

int main()
{
    Total_project=0;
    int Total_customer=0;
    Employee e[20];
    Customer c[20];
    Project p[10];
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

    for(int i=0; i<20; i++)
    {
        co1.addEmployee(e[i]);
    }
    cout<<"WELCOME!\n\n";
    while(1)
    {

        cout<<"1. Login\n";
        cout<<"2. Sign up\n";
        cout<<"3. Administrator\n";
        cout<<"4. Exit\n";
        cout<<"Press 1,2,3 or 4\n";
        int n;
        cin>>n;
        if(n==2)
        {
            string pass;
            Total_customer++;
            custReceiveInfo(c[Total_customer-1]);

            if(generateOption(c[Total_customer-1],e)==true)
            {
                p[Total_project].setInfo(c[Total_customer-1],e[M1],e[M2],e[M3],Cost);
                int b=p[Total_project].getProjectId();
                co1.addCustomer(c[Total_customer-1]);
                co1.editProjectid(M1,M2,M3,b,Total_customer-1,Cost);
                Total_project++;

            }
            co1.updateCustomerlist();
            co1.updateEmployeelist();
        }

        else if(n==3)
        {
            while(1)
            {
                cout<<"1. Add Employee\n";
                cout<<"2. Remove Employee\n";
                cout<<"3. Show Employee List\n";
                cout<<"4. Show Customer List\n";
                cout<<"5. Show Project List\n";
                cout<<"6. Show Course and Student List\n";
                cout<<"7. Show Intern List\n";
                cout<<"8. Show Project List\n";
                cout<<"9. Go Back\n\n";

                int n;
                cin>>n;

                if(n==1)
                {
                    Employee e1;
                    empReceiveInfo(e1);
                    //e1.setinfo("k","123","abc","def","Web Development",11);
                    co1.addEmployee(e1);
                }

                else if(n==3)
                {
                    co1.showemployee();
                }

                else if(n==4)
                {
                    co1.showCustomer();
                }

                else if(n==9)
                {
                    break;
                }
            }

        }

        else if(n==4)
        {
            exit(1);
        }

    }

    /*for(int i=10;i<20;i++)
    {
        co2.addEmployee(e[i]);
    }*/
    /*Employee e1;
    e1.setinfo("k","123","abc","def","Web Development",11);
    co1.addEmployee(e1);
    //co1.showStatus();
    //co2.showStatus();


    /*Customer c1,c2;
    Project p[10];
    custReceiveInfo(c1);
    if(generateOption(c1,e)==true)
    {
        p[Total_project].setInfo(c1,e[M1],e[M2],e[M3],Cost);
        int b=p[Total_project].getProjectId();
        co1.editProjectid(M1,M2,M3,b);
        Total_project++;

    }*/
    //

    //co1.showStatus();
    //co1.showemployee();

    /*custReceiveInfo(c2);
    if(generateOption(c2,e)==true)
    {
        p[Total_project].setInfo(c2,e[M1],e[M2],e[M3],Cost);
        Total_project++;
    }
    p[0].projectDetails();
    //p[1].projectDetails();
    Date d(3,2,20);
    Student s1("Nisa","123","abc","def","Web Development",10.0,d,1,"A");
    Student s2("somestudent","456","xyz","def","Data Science",10.0,d,1,"B");
    Employee* i[2];
    //Intern i1;
    if(s1.isQualified()==true)
    {
        i[0]=intrReceiveInfo(s1,i[0]);
        i[0]->displayinfo();
    }
    if(s2.isQualified()==true)
    {
        i[1]=intrReceiveInfo(s2,i[1]);
        i[1]->displayinfo();
    }
    delete i[0];
    delete i[1];*/
    return 0;

}
