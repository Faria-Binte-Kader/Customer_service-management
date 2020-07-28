#include "student.h"

Student::Student():Person(),course(Available_Courses::Application_Development),course_fee(0),starting_date(0,0,0),course_duration(0),grade(" ")
{
    //ctor
    generatePassword();
}

Student::Student(string nam,string phn,string addr,string em,string cors,double corsfe, Date strtdat,int drtn,string grd):Person(nam,phn,addr,em),course(Available_Courses::Application_Development),course_fee(0),starting_date(0,0,0),course_duration(0),grade("-1")
{
    //ctor
    setCourse(cors);
    setCourseFee(corsfe);
    setStartingDate(strtdat);
    setCourseDuration(drtn);
    setGrade(grd);
    generatePassword();
}

void Student::generatePassword()
{
    char special_character[]="!@#$%&*_-:/<>";
    int sc_length=strlen(special_character);
    char rand_pass[13];
    for(int i=0; i<5; i++)
        rand_pass[i]='A'+rand()%26;
    for(int i=5; i<9; i++)
        rand_pass[i]='a'+rand()%26;
    rand_pass[9]='0'+rand()%10;
    for(int i=10; i<12; i++)
        rand_pass[i]=special_character[rand()%sc_length];
    rand_pass[12]='\0';
    random_shuffle(rand_pass,rand_pass+12);
    strcpy(password,rand_pass);
}

Student::~Student()
{
    //dtor
}

char* Student::getPassword()
{
    return password;
}

void Student::setCourse(string c)
{
    if(c=="Web Development")
        course=Available_Courses::Web_Development;
    else if(c=="Data Science")
        course=Available_Courses::Data_Science;
    else if(c=="Application Development")
        course=Available_Courses::Application_Development;
    else if(c=="Embedded Systems")
        course=Available_Courses::Embedded_systems;
    else if(c=="Cloud Computing")
        course=Available_Courses::Cloud_Computing;
    else
        cout<<"Invalid Course input for student "<<Getname()<<endl;
}

string Student::getCourse()
{
    if(course==Available_Courses::Web_Development)
        return string("Web Development");
    else if(course==Available_Courses::Data_Science)
        return string("Data Science");
    else if(course==Available_Courses::Application_Development)
        return string("Application Development");
    else if(course==Available_Courses::Embedded_systems)
        return string("Embedded Systems");
    else if(course==Available_Courses::Cloud_Computing)
        return string("Cloud Computing");
    else
        return string("No Course Found");
}

void Student::displayinfo()
{
    cout<<"Name\t\t\t: "<<Getname()<<endl;
    cout<<"Contact Number\t\t: "<<Getphone_no()<<endl;
    cout<<"Address\t\t\t: "<<Getaddress()<<endl;
    cout<<"Email\t\t\t: "<<Getemail()<<endl;
    cout<<"Course\t\t\t: "<<getCourse()<<endl;
    cout<<"Course Fee\t\t: "<<getCourseFee()<<endl;
    cout<<"Starting Date\t\t: "<<starting_date.day<<"/"<<starting_date.mon<<"/"<<starting_date.year<<endl;
    cout<<"Duration\t\t: "<<getCourseDuration()<<endl;
    cout<<"Grade\t\t\t: "<<getGrade()<<endl;
    cout<<"Password\t\t: "<<getPassword()<<endl;
    cout<<"Qualified?\t\t ";
    if(isQualified()) cout<<" Yes"<<endl;
    else if(!isQualified()) cout<<" No"<<endl;
    cout<<"\n\n"<<endl;
}

bool Student::hasCompleted()
{
    Date current_date,time_passed;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    current_date.day=timePtr->tm_mday;
    current_date.mon=(timePtr->tm_mon)+1;
    current_date.year=(timePtr->tm_year)+1900;
    time_passed.day=current_date.day-starting_date.day;
    time_passed.mon=current_date.mon-starting_date.mon;
    time_passed.year=current_date.year-starting_date.year;
    if(time_passed.day<=0 && time_passed.mon<=0 && time_passed.year>0) time_passed.year--;
    if(time_passed.day<0) time_passed.day=31+time_passed.day;
    if(time_passed.mon<0) time_passed.mon=12+time_passed.mon-1;
    int days_passed;
    //cout<<time_passed.day<<" "<<time_passed.month<<" "<<time_passed.year<<endl;
    days_passed=time_passed.year*365+time_passed.mon*30+time_passed.day;
    //cout<<days_passed<<endl;
    if(days_passed>=course_duration)
        return true;
    else if(days_passed<course_duration) return false;
}

void Student::setGrade(string g)
{
    if(hasCompleted()==true)
        grade=g;
    else
        cout<<"Error for student "<<Getname()<<" .Course not finished yet."<<endl;
}

bool Student::isQualified()
{
    if(grade=="A" || grade=="B")
        return true;
}
