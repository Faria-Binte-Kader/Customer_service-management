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
bool generateOption(Customer* &c,Employee* e[],int total)
{
    double b=c->getBudget();
    int t=c->getDuration();
    string w=c->getWork();
    int index[100][3],option[100][3],ex[100][3],op;
    double cost[100];
    Senior senior[100];
    Junior junior[100];
    Entry entry[100];
    int s=0,j=0,en=0,cnt=0;
    double temp,temp2,temp3,pro;
    for(int i=0; i<total; i++)
    {
        if(e[i]->getDesignation()==w&&e[i]->getPosition()=="Senior"&&(e[i]->getBonus()*t)<=b&&e[i]->getProjectId()==0)
        {
            senior[s].idx=i;
            senior[s].bonus=e[i]->getBonus()*t;
            senior[s].ID=e[i]->getEmployeeID();
            senior[s].expr=e[i]->getExperience();
            s++;
        }
        if(e[i]->getDesignation()==w&&e[i]->getPosition()=="Junior"&&(e[i]->getBonus()*t)<=b&&e[i]->getProjectId()==0)
        {
            junior[j].idx=i;
            junior[j].bonus=e[i]->getBonus()*t;
            junior[j].ID=e[i]->getEmployeeID();
            junior[j].expr=e[i]->getExperience();
            j++;
        }
        if(e[i]->getDesignation()==w&&e[i]->getPosition()=="Entry Level"&&(e[i]->getBonus()*t)<=b&&e[i]->getProjectId()==0)
        {
            entry[en].idx=i;
            entry[en].bonus=e[i]->getBonus()*t;
            entry[en].ID=e[i]->getEmployeeID();
            entry[en].expr=e[i]->getExperience();
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
        cout<<"Option\t\t: "<<i+1<<endl;
        cout<<"Member 1\t: "<<option[i][0]<<" [Experience: "<<ex[i][0]<<" years]"<<endl;
        cout<<"Member 2\t: "<<option[i][1]<<" [Experience: "<<ex[i][1]<<" years]"<<endl;
        cout<<"Member 3\t: "<<option[i][2]<<" [Experience: "<<ex[i][2]<<" years]"<<endl;
        cout<<"Cost\t\t: "<<cost[i]<<endl;
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
Student* stdReceiveInfo(Student* s)
{
    string nam,phn,addr,em,w,wkk,garbage;
    double crsfee;
    int drtn=0,wk;
    getline(cin,garbage);    //dummy getline
    cout<<"Enter your name: ";
    getline(cin,nam);
    cout<<"Enter your contact no.: ";
    getline(cin,phn);
    cout<<"Enter your address: ";
    getline(cin,addr);
    cout<<"Enter your email: ";
    cin>>em;
    cout<<"Enter department:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
    cin>>wkk;
    if((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90)||wkk[0]<48||wkk[0]>53)
    {
        while(1)
        {
            cout<<"Error. Please enter a valid value for department."<<endl;
            cout<<"Enter department:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
            cin>>wkk;
            if(!((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90)||wkk[0]<48||wkk[0]>53))
                break;
        }
    }
    wk=stoi(wkk);
    if(wk==0)
        w="Web Development";
    else if(wk==1)
        w="Mobile Development";
    else if(wk==2)
        w="Data Science";
    else if(wk==3)
        w="Application Development";
    else if(wk==4)
        w="Embedded Systems";
    else if(wk==5)
        w="Cloud Computing";
    getline(cin,garbage);
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
    s=new Student();
    s->setInfo(nam,phn,addr,em,w,crsfee,dt2,drtn,"Not completed yet");
    return s;
}

Employee* empReceiveInfo(Employee* e)
{
    string nam,phn,addr,em,desc,garbage,wkk,w;
    double b;
    int wk;
    getline(cin,garbage);    //dummy getline
    cout<<"Enter Employee's name: ";
    getline(cin,nam);
    cout<<"Enter Employee's contact no.: ";
    getline(cin,phn);
    cout<<"Enter Employee's address: ";
    getline(cin,addr);
    cout<<"Enter Employee's email: ";
    cin>>em;
    cout<<"Enter designation:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
    cin>>wkk;
    if((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90)||wkk[0]<48||wkk[0]>53)
    {
        while(1)
        {
            cout<<"Error. Please enter a valid value for designation."<<endl;
            cout<<"Enter designation:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
            cin>>wkk;
            if(!((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90)||wkk[0]<48||wkk[0]>53))
                break;
        }
    }
    wk=stoi(wkk);
    if(wk==0)
        w="Web Development";
    else if(wk==1)
        w="Mobile Development";
    else if(wk==2)
        w="Data Science";
    else if(wk==3)
        w="Application Development";
    else if(wk==4)
        w="Embedded Systems";
    else if(wk==5)
        w="Cloud Computing";
    getline(cin,garbage);
    cout<<"Enter experience time: ";
    cin>>b;
    //getline(cin,garbage);
    e=new Employee();
    e->setinfo(nam,phn,addr,em,w,b);
    return e;
}

Customer* custReceiveInfo(Customer* c)
{
    string nam,phn,addr,em,desc,garbage;
    string bj,ti,wkk;
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
    cin>>bj;
    if((bj[0]>=97 && bj[0]<=123)||(bj[0]>=65 && bj[0]<=90))
    {
        while(1)
        {
            cout<<"Error. Please enter a valid amount."<<endl;
            cout<<"Enter your budget: ";
            cin>>bj;
            if(!((bj[0]>=97 && bj[0]<=123)||(bj[0]>=65 && bj[0]<=90)))
                break;
        }
    }
    b=stod(bj);
    cout<<"Enter the time(in months 1-24): ";
    cin>>ti;
    if((ti[0]>=97 && ti[0]<=123)||(ti[0]>=65 && ti[0]<=90))
    {
        while(1)
        {
            cout<<"Error. Please enter a valid value for time."<<endl;
            cout<<"Enter the time(in months 1-24): ";
            cin>>ti;
            if(!((ti[0]>=97 && ti[0]<=123)||(ti[0]>=65 && ti[0]<=90)))
                break;
        }
    }
    t=stoi(ti);
    cout<<"Enter the type:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
    cin>>wkk;
    if((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90))
    {
        while(1)
        {
            cout<<"Error. Please enter a valid value for type."<<endl;
            cout<<"Enter the type:\n0.Web Development\n1.Mobile Development\n2.Data Science\n3.Application Development\n4.Embedded Systems\n5.Cloud Computing"<<endl;
            cin>>wkk;
            if(!((wkk[0]>=97 && wkk[0]<=123)||(wkk[0]>=65 && wkk[0]<=90)))
                break;
        }
    }
    wk=stoi(wkk);
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
    c=new Customer();
    c->setinfo(nam,phn,addr,em,b,t,desc,dt2,w);
    return c;
}

Employee* intrReceiveInfo(Student &s,Employee* i)
{
    string nam,phn,addr,em,d;
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
    int Free_intern=Total_intern;
    int et=0;
    Employee* e[100];
    Customer* c[20];
    Student* s[50];
    s[0]=new Student();
    s[0]->setInfo("Nisa","123","abc","def","Web Development",10.0,d,90,"A");
    string pas=s[0]->getPassword();
    cout<<"Login as student using Nisa and this password to check intern\n";
    cout<<pas<<endl;  //to check intern, login using name- Nisa , and password from the first line
    Total_student++;
    Project p[10];
    Company co1("ABC");
    for(int i=0; i<60; i++)
    {
        e[i]=new Employee();
    }
    e[0]->setinfo("a","123","abc","def","Web Development",11);
    cout<<e[0]->getPassword()<<" use this password to check employee login for name 'a'"<<endl;
    e[1]->setinfo("b","123","abc","def","Web Development",15);
    e[2]->setinfo("c","123","abc","def","Data Science",11);
    e[3]->setinfo("d","123","abc","def","Web Development",9);
    e[4]->setinfo("e","123","abc","def","Data Science",5);
    e[5]->setinfo("f","123","abc","def","Data Science",7);
    e[6]->setinfo("g","123","abc","def","Web Development",4);
    e[7]->setinfo("h","123","abc","def","Data Science",3);
    e[8]->setinfo("i","123","abc","def","Data Science",2);
    e[9]->setinfo("j","123","abc","def","Web Development",1);
    e[10]->setinfo("k","123","abc","def","Web Development",11);
    e[11]->setinfo("l","123","abc","def","Web Development",15);
    e[12]->setinfo("m","123","abc","def","Data Science",11);
    e[13]->setinfo("n","123","abc","def","Web Development",9);
    e[14]->setinfo("o","123","abc","def","Data Science",5);
    e[15]->setinfo("p","123","abc","def","Data Science",7);
    e[16]->setinfo("q","123","abc","def","Web Development",4);
    e[17]->setinfo("r","123","abc","def","Data Science",3);
    e[18]->setinfo("s","123","abc","def","Data Science",2);
    e[19]->setinfo("t","123","abc","def","Web Development",1);
    e[20]->setinfo("a1","123","abc","def","Mobile Development",11);
    e[21]->setinfo("b1","123","abc","def","Mobile Development",15);
    e[22]->setinfo("c1","123","abc","def","Embedded Systems",11);
    e[23]->setinfo("d1","123","abc","def","Mobile Development",9);
    e[24]->setinfo("e1","123","abc","def","Embedded Systems",5);
    e[25]->setinfo("f1","123","abc","def","Embedded Systems",7);
    e[26]->setinfo("g1","123","abc","def","Mobile Development",4);
    e[27]->setinfo("h1","123","abc","def","Embedded Systems",3);
    e[28]->setinfo("i1","123","abc","def","Embedded Systems",2);
    e[29]->setinfo("j1","123","abc","def","Mobile Development",1);
    e[30]->setinfo("k1","123","abc","def","Mobile Development",11);
    e[31]->setinfo("l1","123","abc","def","Mobile Development",15);
    e[32]->setinfo("m1","123","abc","def","Embedded Systems",11);
    e[33]->setinfo("n1","123","abc","def","Mobile Development",9);
    e[34]->setinfo("o1","123","abc","def","Embedded Systems",5);
    e[35]->setinfo("p1","123","abc","def","Embedded Systems",7);
    e[36]->setinfo("q1","123","abc","def","Mobile Development",4);
    e[37]->setinfo("r1","123","abc","def","Embedded Systems",3);
    e[38]->setinfo("s1","123","abc","def","Embedded Systems",2);
    e[39]->setinfo("t1","123","abc","def","Mobile Development",1);
    e[40]->setinfo("a2","123","abc","def","Application Development",11);
    e[41]->setinfo("b2","123","abc","def","Application Development",15);
    e[42]->setinfo("c2","123","abc","def","Cloud Computing",11);
    e[43]->setinfo("d2","123","abc","def","Application Development",9);
    e[44]->setinfo("e2","123","abc","def","Cloud Computing",5);
    e[45]->setinfo("f2","123","abc","def","Cloud Computing",7);
    e[46]->setinfo("g2","123","abc","def","Application Development",4);
    e[47]->setinfo("h2","123","abc","def","Cloud Computing",3);
    e[48]->setinfo("i2","123","abc","def","Cloud Computing",2);
    e[49]->setinfo("j2","123","abc","def","Application Development",1);
    e[50]->setinfo("k2","123","abc","def","Application Development",11);
    e[51]->setinfo("l2","123","abc","def","Application Development",15);
    e[52]->setinfo("m2","123","abc","def","Cloud Computing",11);
    e[53]->setinfo("n2","123","abc","def","Application Development",9);
    e[54]->setinfo("o2","123","abc","def","Cloud Computing",5);
    e[55]->setinfo("p2","123","abc","def","Cloud Computing",7);
    e[56]->setinfo("q2","123","abc","def","Application Development",4);
    e[57]->setinfo("r2","123","abc","def","Cloud Computing",3);
    e[58]->setinfo("s2","123","abc","def","Cloud Computing",2);
    e[59]->setinfo("t2","123","abc","def","Application Development",1);
    et+=60;
    Employee* intern[20];
    for(int i=0; i<et; i++)
    {
        co1.addEmployee(*e[i]);
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
                c[Total_customer-1]=custReceiveInfo(c[Total_customer-1]);
                cout<<"Here's your password\n\n";
                string pass;
                pass=c[Total_customer-1]->getPassword();
                cout<<pass<<endl;
                cout<<endl;
                string pass1;
                cout<<"Would you like to change your password?\n1.Yes\n2.No\n";
                int paschoic;
                cin>>paschoic;
                if(paschoic==1)
                {
                    cout<<"Please create a password (12 characters maximum)"<<endl;
                    cin>>pass1;
                    c[Total_customer-1]->setPassword(pass1);
                    cout<<"You've chosen to use "<<c[Total_customer-1]->getPassword()<<" as your password."<<endl;
                }
                else if(paschoic==2)
                {
                    cout<<"You've chosen to use "<<c[Total_customer-1]->getPassword()<<" as your password."<<endl;
                }

                cout<<"Please login to continue\n\n";
            }

            else if(i==2)
            {
                Total_student++;
                s[Total_student-1]=stdReceiveInfo(s[Total_student-1]);
                cout<<"Here's your password\n";
                string pass;
                pass=s[Total_student-1]->getPassword();
                cout<<pass<<endl;
                cout<<endl;
                string pass1;
                cout<<"Would you like to change your password?\n1.Yes\n2.No\n";
                int paschoic;
                cin>>paschoic;
                if(paschoic==1)
                {
                    cout<<"Please create a password (12 characters maximum)"<<endl;
                    cin>>pass1;
                    s[Total_student-1]->setPassword(pass1);
                    cout<<"You've chosen to use "<<s[Total_student-1]->getPassword()<<" as your password."<<endl;
                }
                else if(paschoic==2)
                {
                    cout<<"You've chosen to use "<<s[Total_student-1]->getPassword()<<" as your password."<<endl;
                }
                cout<<"Please login to continue\n\n";

            }

        }

        else if(n==2)
        {
            cout<<"1. User\n";
            cout<<"2. Student\n";
            cout<<"3. Employee\n";
            int i;
            cin>>i;
            if(i==1)
            {
                cout<<"Enter your username: ";
                string name,pass,pass2;
                cin>>name;
                int b=-1;
                for(int j=0; j<Total_customer ; j++)
                {

                    if(name==c[j]->getName())
                    {
                        pass=c[j]->getPassword();
                        b=j;
                        break;
                    }
                }
                if(b==-1)
                    cout<<"Not a valid username"<<endl;
                else
                {
                    cout<<"Enter password: ";
                    cin>>pass2;
                    //cout<<"real password: "<<pass<<endl;
                    if(pass==pass2)
                    {
                        if(c[b]->GetProjectId()==0)
                        {

                            if(generateOption(c[b],e,et)==true)
                            {
                                string projectname,garbage;
                                cout<<"You've chosen a group of 3 employees as your preference for your project.\n\n";
                                getline(cin,garbage);
                                cout<<"Give your project a name. Enter name--"<<endl;
                                getline(cin,projectname);
                                p[Total_project].setInfo(*c[b],*e[M1],*e[M2],*e[M3],Cost,projectname);
                                if(Free_intern>0)
                                    p[Total_project].addIntern(intern[Free_intern-1]);
                                int bp=p[Total_project].getProjectId();
                                if(Free_intern>0)
                                {
                                    intern[Free_intern-1]->setProjectId(bp);
                                    Free_intern--;
                                }
                                c[b]->setCost(Cost);
                                co1.addCustomer(*c[b]);
                                co1.editProjectid(*c[b],*e[M1],*e[M2],*e[M3],p[Total_project].getProjectId());
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
                                if(p[k].getProjectId()==c[b]->GetProjectId())
                                    p[k].projectDetails();
                            }
                        }
                    }
                    else
                    {
                        cout<<"Incorrect password. Login again\n\n";
                    }
                }
            }

            else if(i==2)
            {
                //
                cout<<"Enter your username: ";
                string name,pass,pass2;
                cin>>name;
                int b=-1;
                for(int j=0; j<Total_student ; j++)
                {
                    if(name==s[j]->getName())
                    {
                        pass=s[j]->getPassword();
                        b=j;
                    }
                }
                if(b==-1)
                    cout<<"Not a valid username"<<endl;
                else
                {
                    cout<<"Enter password: ";
                    cin>>pass2;
                    if(pass==pass2)
                    {
                        s[b]->displayinfo();
                        if(s[b]->isQualified()==true && (Total_intern==0 || intern[Total_intern-1]->getName()!=s[b]->getName()))
                        {
                            cout<<"We are glad to offer you as an intern to help you gain experience"<<endl;
                            cout<<"Do you want to take the internship?"<<endl;
                            cout<<endl;
                            cout<<"1. Yes 2. No"<<endl;
                            int a;
                            cin>>a;
                            if(a==1)
                            {
                                Total_intern++;
                                Free_intern++;
                                intern[Total_intern-1]=intrReceiveInfo(*s[b],intern[Total_intern-1]);
                                int int_id=intern[Total_intern-1]->getInternid();
                                intern[Total_intern-1]->setEmployeeID(int_id);
                                cout<<"We will contact you via email with more information. Congratulations!\n\n";
                                intern[Total_intern-1]->displayinfo();
                                co1.addIntern(intern[Total_intern-1]);
                            }
                            else if(a==2)
                                cout<<"Hope to see you again!\n\n";
                        }
                        else if(s[b]->isQualified()==true && intern[Total_intern-1]->getName()==s[b]->getName())
                        {
                            cout<<"You are already an Intern.\n\n";
                            intern[Total_intern-1]->displayinfo();
                        }

                    }
                    else
                    {
                        cout<<"Incorrect password. Login again\n\n";
                    }

                }
            }

            else if(i==3)
            {
                cout<<"Enter your username: ";
                string name,pass2;
                cin>>name;
                int b=-1;
                for(int j=0; j<et ; j++)
                {
                    if(name==e[j]->getName())
                    {
                        b=j;
                    }
                }
                if(b==-1)
                    cout<<"Not a valid username"<<endl;
                else
                {
                    cout<<"Enter password: ";
                    cin>>pass2;
                    if(e[b]->getPassword()==pass2)
                    {
                        e[b]->displayinfo();
                        string pass1;
                        cout<<"Would you like to change your password?\n1.Yes\n2.No\n";
                        int paschoic;
                        cin>>paschoic;
                        if(paschoic==1)
                        {
                            cout<<"Please create a password (12 characters maximum)"<<endl;
                            cin>>pass1;
                            e[b]->setPassword(pass1);
                            cout<<"You've chosen to use "<<e[b]->getPassword()<<" as your password."<<endl;
                        }
                        else if(paschoic==2)
                        {
                            cout<<"You've chosen to use "<<e[b]->getPassword()<<" as your password."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"Incorrect password. Login again\n\n";
                    }

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
                    e[et]=empReceiveInfo(e[et]);
                    co1.addEmployee(*e[et]);
                    cout<<endl;
                    cout<<e[et]->getName()<<" has been added as an Employee."<<endl;
                    et++;
                }

                else if(n==2)
                {
                    cout<<"Total Employee: "<<et<<endl;
                    cout<<endl;
                    co1.showemployee();
                }

                else if(n==3)
                {
                    if(Total_customer==0)
                        cout<<"No Customers to show"<<endl;
                    else
                    {
                        cout<<"Total Customer: "<<Total_customer<<endl;
                        cout<<endl;
                        co1.showCustomer();
                    }
                }

                else if(n==4)
                {
                    if(Total_project==0)
                        cout<<"No Projects to show"<<endl;
                    else
                    {
                        for(int i=0; i<Total_project; i++)
                            p[i].projectDetails();
                    }
                }

                else if(n==5)
                {
                    int w=0,a=0,c=0,e=0,m=0, d=0;
                    for(int i=0; i<Total_student; i++)
                    {
                        if(s[i]->getCourse()=="Web Development" && s[i]->hasCompleted()==false)
                            w++;
                        else if(s[i]->getCourse()=="Mobile Development" && s[i]->hasCompleted()==false)
                            m++;
                        else if(s[i]->getCourse()=="Application Development" && s[i]->hasCompleted()==false)
                            a++;
                        else if(s[i]->getCourse()=="Cloud Computing" && s[i]->hasCompleted()==false)
                            c++;
                        else if(s[i]->getCourse()=="Data Science" && s[i]->hasCompleted()==false)
                            d++;
                        else if(s[i]->getCourse()=="Embedded Systems" && s[i]->hasCompleted()==false)
                            e++;
                    }
                    cout<<endl;
                    cout<<"Web Development\t\t: "<<w<<endl;
                    cout<<"Mobile Development\t: "<<m<<endl;
                    cout<<"Application Development\t: "<<a<<endl;
                    cout<<"Cloud Computing\t\t: "<<c<<endl;
                    cout<<"Data Science\t\t: "<<d<<endl;
                    cout<<"Embedded Systems\t: "<<e<<endl;
                }
                else if(n==6)
                {
                    if(Total_intern==0)
                        cout<<"No interns to show\n";
                    else
                    {
                        cout<<"Total Intern: "<<Total_intern<<endl;
                        cout<<endl;
                        co1.showIntern();
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
    delete[] intern;
    delete[] e;
    delete[] c;
    delete[] s;
    return 0;

}

/*
2
2
Nisa
Hw<YCpYj&2fU
1
1
1
Tasmia
4534545
fgfvdf
fvfddv
10000000
24
4
sdfgefgfdb
2
2
1
Tasmia
AAYKQrxyc7_#
32
1
*/
/*
1
1
Tasmia
4534545
fgfvdf
fvfddv
10000000
24
4
sdfgefgfdb
1
1
abc
4534545
fgfvdf
fvfddv
10000000
24
4
sdfgefgfdb
*/
