#include "Project.h"
#include<bits/stdc++.h>

Project::Project():status("Unfinished")
{
    //ctor
    total_projects++;
    //calcDeliveryDate();
    //setStatus();
}

Project::Project(Customer &c, Employee &e1,Employee &e2, Employee &e3, double cst, int tm, std::string des):cost(cst),project_time(tm),description(des),status("Unfinished")
{
    //ctor
    cust=&c;
    emp[0]=&e1;
    emp[1]=&e2;
    emp[2]=&e3;
    total_projects++;
    calcDeliveryDate();
    setStatus();
}

int Project::total_projects=0;

Project::~Project()
{
    //dtor
}

Date Project::calcDeliveryDate()
{
    delivery_date.day=cust->getDate().day;
    delivery_date.year=cust->getDate().year+project_time/12;
    delivery_date.month=cust->getDate().month+project_time-(delivery_date.year-cust->getDate().year)*12;
    if(delivery_date.month>12)
    {
        delivery_date.year=delivery_date.year+delivery_date.month/12;
        delivery_date.month=delivery_date.month-12;
    }
}

void Project::setStatus()
{
    Date dt2;
    dt2.day=cust->getDate().day;
    dt2.month=cust->getDate().month+cust->getDuration();
    dt2.year=cust->getDate().year;
    if(dt2.month>12) dt2.year++;
    time_t now=time(0);
    tm* dt1=localtime(&now);
    if(1900+dt1->tm_year>dt2.year) status="Finished";
    if(1900+dt1->tm_year==dt2.year)
    {
        if(1+dt1->tm_mon>dt2.month) status="Finished";
        else if(1+dt1->tm_mon==dt2.month)
        {
            if(dt1->tm_mday>=dt2.day) status="Finished";
            else status="Unfinished";
        }
        else status="Unfinished";
    }
    else status="Unfinished";
}

void Project::setInfo(Customer &c, Employee &e1,Employee &e2, Employee &e3,double cst)
{
    /*cust=&c;
    emp[0]=&e1;
    emp[1]=&e2;
    emp[2]=&e3;
    emp[0]->setProjectId(projectId);
    emp[1]->setProjectId(projectId);
    emp[2]->setProjectId(projectId);
    cust->setCost(cst);
    cust->SetProjectId(projectId);
    setCost(cst);
    project_time=cust->getDuration();
    calcDeliveryDate();
    setStatus();*/
    e1.setProjectId(projectId);
    e2.setProjectId(projectId);
    e3.setProjectId(projectId);
    c.setCost(cst);
    c.SetProjectId(projectId);
    setCost(cst);
    cust=&c;
    emp[0]=&e1;
    emp[1]=&e2;
    emp[2]=&e3;
    project_time=cust->getDuration();
    calcDeliveryDate();
    setStatus();
    std::cout<<"Customer: "<<std::endl;
    c.displayinfo();
    std::cout<<"Member 1: "<<std::endl;
    std::cout<<"Name\t\t\t: "<<emp[0]->getName()<<std::endl;
    std::cout<<"Email\t\t\t: "<<emp[0]->getEmail()<<std::endl;
    std::cout<<"Contact no\t\t: "<<emp[0]->getPhone_no()<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Member 2: "<<std::endl;
    std::cout<<"Name\t\t\t: "<<emp[1]->getName()<<std::endl;
    std::cout<<"Email\t\t\t: "<<emp[1]->getEmail()<<std::endl;
    std::cout<<"Contact no\t\t: "<<emp[1]->getPhone_no()<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Member 3: "<<std::endl;
    std::cout<<"Name\t\t\t: "<<emp[2]->getName()<<std::endl;
    std::cout<<"Email\t\t\t: "<<emp[2]->getEmail()<<std::endl;
    std::cout<<"Contact no\t\t: "<<emp[2]->getPhone_no()<<std::endl;
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Total Cost\t\t: "<<getCost()<<std::endl;

}

void Project::addIntern(Employee* i)
{
    intr=i;
    //intr->displayinfo();
    total_intern++;
}

void Project::projectDetails()
{
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Project ID\t\t: "<<getProjectId()<<std::endl;
    std::cout<<"Customer ID\t\t: "<<cust->getCustID()<<std::endl;
    std::cout<<"Member 1 ID\t\t: "<<emp[0]->getEmployeeID()<<std::endl;
    std::cout<<"Member 2 ID\t\t: "<<emp[1]->getEmployeeID()<<std::endl;
    std::cout<<"Member 3 ID\t\t: "<<emp[2]->getEmployeeID()<<std::endl;
    if(total_intern>0)
        std::cout<<"Intern ID\t\t: "<<intr->getEmployeeID()<<std::endl;
    std::cout<<"Project Time\t\t: "<<getProjectTime()<<" months"<<std::endl;
    std::cout<<"Project Description\t: "<<cust->getDescription()<<std::endl;
    std::cout<<"Status\t\t\t: "<<getStatus()<<std::endl;
    std::cout<<"Delivery Date\t\t: "<<getDeliveryDate().day<<"/"<<getDeliveryDate().month<<"/"<<getDeliveryDate().year<<std::endl;
    std::cout<<"Project Cost\t\t: "<<getCost()<<std::endl;
    //std::cout<<"Customer id: "<<getProjectId()<<std::endl;
}
