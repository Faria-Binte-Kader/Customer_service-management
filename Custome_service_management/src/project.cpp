#include "project.h"
#include<bits/stdc++.h>

Project::Project():status("Unfinished")
{
    //ctor
    total_projects++;
    calcDeliveryDate();
    setStatus(delivery_date);
}

Project::Project(Customer c, Employee e1,Employee e2, Employee e3, double cst, int tm, std::string des):cust(c),emp1(e1),emp2(e2),emp3(e3),cost(cst),project_time(tm),description(des),status("Unfinished")
{
    //ctor
    total_projects++;
    calcDeliveryDate();
    setStatus(delivery_date);
}

int Project::total_projects=0;

Project::~Project()
{
    //dtor
}

Date Project::calcDeliveryDate()
{
    delivery_date.day=cust.getDate().day;
    delivery_date.year=cust.getDate().year+project_time/12;
    delivery_date.month=cust.getDate().month+project_time-(delivery_date.year-cust.getDate().year)*12;
}

void Project::setStatus(Date del_date)
{
    Date current_date,time_passed;
    time_t t=time(NULL);
    tm* timePtr = localtime(&t);
    current_date.day=timePtr->tm_mday;
    current_date.month=(timePtr->tm_mon)+1;
    current_date.year=(timePtr->tm_year)+1900;
    time_passed.day=current_date.day-del_date.day;
    time_passed.month=current_date.month-del_date.month;
    time_passed.year=current_date.year-del_date.year;
    if(time_passed.day<=0 && time_passed.month<=0 && time_passed.year>0)
        time_passed.year--;
    if(time_passed.day<0)
        time_passed.day=31+time_passed.day;
    if(time_passed.month<0)
        time_passed.month=12+time_passed.month-1;
    int days_passed;
    days_passed=time_passed.year*365+time_passed.month*30+time_passed.day;
    if(days_passed>0)
        status="Finished";
    else if(days_passed<0)
        status="Unfinished";
}

void Project::setInfo(Customer c, Employee e1,Employee e2, Employee e3,double cst)
{
    setCost(cst);
    emp1=e1;
    emp2=e2;
    emp3=e3;
    emp1.setProjectId(projectId);
    emp2.setProjectId(projectId);
    emp3.setProjectId(projectId);
    c.setCost(cst);
    std::cout<<"Member 1: "<<std::endl;
    emp1.displayinfo();
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Member 2: "<<std::endl;
    emp2.displayinfo();
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Member 3: "<<std::endl;
    emp3.displayinfo();
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Total Cost: "<<getCost()<<std::endl;

}

void Project::projectDetails()
{
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Project id: "<<getProjectId()<<std::endl;
    std::cout<<"Member 1 id: "<<emp1.getEmployeeID()<<std::endl;
    std::cout<<"Member 2 id: "<<emp2.getEmployeeID()<<std::endl;
    std::cout<<"Member 3 id: "<<emp3.getEmployeeID()<<std::endl;
    //std::cout<<"Customer id: "<<getProjectId()<<std::endl;
}

