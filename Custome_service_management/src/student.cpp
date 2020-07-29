#include "student.h"

Student::Student():Person(),course(Available_Courses::Application_Development),course_fee(0),starting_date(0,0,0),course_duration(0),grade(" ")
{
    //ctor
    generatePassword();
    setStudentId(Available_Courses::Application_Development);
    total_students++;
}

Student::Student(std::string nam,std::string phn,std::string addr,std::string em,std::string cors,double corsfe, Date strtdat,int drtn,std::string grd):Person(nam,phn,addr,em),course(Available_Courses::Application_Development),course_fee(0),starting_date(0,0,0),course_duration(0),grade("-1")
{
    //ctor
    setCourse(cors);
    setCourseFee(corsfe);
    setStartingDate(strtdat);
    setCourseDuration(drtn);
    setGrade(grd);
    generatePassword();
    setStudentId(course);
    total_students++;
}

Student::~Student()
{
    //dtor
}

int Student::total_students=-1;

void Student::setStudentId(Available_Courses c)
{
    if(c==Available_Courses::Web_Development)
        student_id=student_id+100;
    else if(c==Available_Courses::Data_Science)
        student_id=student_id+200;
    else if(c==Available_Courses::Application_Development)
        student_id=student_id+300;
    else if(c==Available_Courses::Embedded_systems)
        student_id=student_id+400;
    else if(c==Available_Courses::Cloud_Computing)
        student_id=student_id+500;
    else
         std::cout<<"Student is not enrolled in a valid course"<<std::endl;
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
    std::random_shuffle(rand_pass,rand_pass+12);
    strcpy(password,rand_pass);
}

char* Student::getPassword()
{
    return password;
}

void Student::setCourse(std::string c)
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
        std::cout<<"Invalid Course input for student "<<GetName()<<std::endl;
}

std::string Student::getCourse()
{
    if(course==Available_Courses::Web_Development)
        return std::string("Web Development");
    else if(course==Available_Courses::Data_Science)
        return std::string("Data Science");
    else if(course==Available_Courses::Application_Development)
        return std::string("Application Development");
    else if(course==Available_Courses::Embedded_systems)
        return std::string("Embedded Systems");
    else if(course==Available_Courses::Cloud_Computing)
        return std::string("Cloud Computing");
    else
        return std::string("No Course Found");
}

void Student::displayinfo()
{
    std::cout<<"Student ID\t\t: "<<getStudentId()<<std::endl;
    std::cout<<"Name\t\t\t: "<<GetName()<<std::endl;
    std::cout<<"Contact Number\t\t: "<<GetPhone_no()<<std::endl;
    std::cout<<"Address\t\t\t: "<<GetAddress()<<std::endl;
    std::cout<<"Email\t\t\t: "<<GetEmail()<<std::endl;
    std::cout<<"Course\t\t\t: "<<getCourse()<<std::endl;
    std::cout<<"Course Fee\t\t: "<<getCourseFee()<<std::endl;
    std::cout<<"Starting Date\t\t: "<<starting_date.day<<"/"<<starting_date.month<<"/"<<starting_date.year<<std::endl;
    std::cout<<"Duration\t\t: "<<getCourseDuration()<<std::endl;
    std::cout<<"Grade\t\t\t: "<<getGrade()<<std::endl;
    std::cout<<"Password\t\t: "<<getPassword()<<std::endl;
    std::cout<<"Qualified?\t\t ";
    if(isQualified()) std::cout<<" Yes"<<std::endl;
    else if(!isQualified()) std::cout<<" No"<<std::endl;
    std::cout<<"\n\n"<<std::endl;
}

bool Student::hasCompleted()
{
    Date current_date,time_passed;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    current_date.day=timePtr->tm_mday;
    current_date.month=(timePtr->tm_mon)+1;
    current_date.year=(timePtr->tm_year)+1900;
    time_passed.day=current_date.day-starting_date.day;
    time_passed.month=current_date.month-starting_date.month;
    time_passed.year=current_date.year-starting_date.year;
    if(time_passed.day<=0 && time_passed.month<=0 && time_passed.year>0) time_passed.year--;
    if(time_passed.day<0) time_passed.day=31+time_passed.day;
    if(time_passed.month<0) time_passed.month=12+time_passed.month-1;
    int days_passed;
    days_passed=time_passed.year*365+time_passed.month*30+time_passed.day;
    if(days_passed>=course_duration)
        return true;
    else if(days_passed<course_duration) return false;
}

void Student::setGrade(std::string g)
{
    if(hasCompleted()==true)
        grade=g;
    else
        std::cout<<"Error for student "<<GetName()<<" .Course not finished yet."<<std::endl;
}

bool Student::isQualified()
{
    if(grade=="A" || grade=="B")
        return true;
}
