#ifndef STUDENT_H
#define STUDENT_H

#include <Person.h>


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
    void setStudentId(Available_Courses c);
    long long int getStudentId(){return student_id;}

protected:
    Available_Courses course;
    double course_fee;
    Date starting_date;
    int course_duration;
    string grade;


    long long int student_id=200031001+total_students+1;//starts from 31001 because student is our 3rd class xD
    static int total_students; //if student_id creates any problem it's because of this one
private:

};

#endif // STUDENT_H
