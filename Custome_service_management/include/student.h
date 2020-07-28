#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>


struct Date
{
    int day;
    int mon;
    //string month;
    int year;
    Date(){}
    Date(int d,int m,int y):day(d),mon(m),year(y){}
};

enum class Available_Courses {Web_Development,Data_Science,Application_Development,Embedded_systems,Cloud_Computing};

class Student :virtual public Person
{
public:
    Student();
    Student(string nam,string phn,string addr,string em,string cors,double corsfe, Date strtdat,int drtn,string grd);
    virtual ~Student();
    string getCourse();
    void setCourse(string c);
    double getCourseFee(){return course_fee;}
    void setCourseFee(int cf){course_fee=cf;}
    Date getStartingDate(){return starting_date;}
    void setStartingDate(Date st){starting_date=st;}
    int getCourseDuration(){return course_duration;}
    void setCourseDuration(int cd){course_duration=cd;}
    string getGrade(){return grade;}
    void setGrade(string g);
    void dispalyinfo();
    bool isQualified();
    void generatePassword();
    char* getPassword();
    void displayinfo();

    bool hasCompleted();

protected:
    Available_Courses course;
    double course_fee;
    Date starting_date;
    int course_duration;
    string grade;


    int student_id;
private:

};

#endif // STUDENT_H
