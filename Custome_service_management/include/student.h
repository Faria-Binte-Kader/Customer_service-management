#ifndef STUDENT_H
#define STUDENT_H
#include"Person.h"
#include<bits/stdc++.h>
enum class Available_Courses {Web_Development,Mobile_Development,Data_Science,Application_Development,Embedded_Systems,Cloud_Computing};
class Student:virtual public Person
{
protected:
    Available_Courses course;
    double course_fee;
    Date starting_date;
    int course_duration;
    std::string grade;
    static int total_students;
    const int student_id=3001+total_students;
public:
    Student();
    Student(std::string nam,std::string phn,std::string addr,std::string em,std::string cors,double corsfe, Date strtdat,int drtn,std::string grd);
    virtual ~Student();
    std::string getCourse();
    void setCourse(std::string c);
    double getCourseFee()
    {
        return course_fee;
    }
    void setCourseFee(int cf)
    {
        course_fee=cf;
    }
    Date getStartingDate()
    {
        return starting_date;
    }
    void setStartingDate(Date st)
    {
        starting_date=st;
    }
    int getCourseDuration()
    {
        return course_duration;
    }
    void setCourseDuration(int cd)
    {
        course_duration=cd;
    }
    std::string getGrade()
    {
        return grade;
    }
    void setGrade(std::string g);
    bool isQualified();
    void generatePassword();
    char* getPassword();
    void displayinfo();

    void setInfo(std::string nam,std::string phn,std::string addr,std::string em,std::string cors,double corsfe, Date strtdat,int drtn,std::string grd);
    bool hasCompleted();
    //void setStudentId(Available_Courses c);
    long long int getStudentId()
    {
        return student_id;
    }
};
#endif
