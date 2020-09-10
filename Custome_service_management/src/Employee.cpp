#include"Employee.h"
#include<bits/stdc++.h>
Employee::Employee():Person(),designation(Designation::Web_Development),experience(0)
{
    total_employee++;
    setPosition();
    setSalary();
    calcBonus();
    setProjectId(0);
    generatePassword();
}
Employee::Employee(std::string nam,std::string phn,std::string addr,std::string em,std::string des,int ex):Person(nam,phn,addr,em),designation(Designation::Web_Development),experience(0)
{
    total_employee++;
    setDesignation(des);
    setExperience(ex);
    setPosition();
    setSalary();
    calcBonus();
    setProjectId(0);
    generatePassword();
    std::cout<<"Total employee"<<total_employee<<std::endl;
}
Employee::~Employee()
{
   delete[] password;
}

int Employee::total_employee=0;

void Employee::setPosition()
{
    if(experience<5) position="Entry Level";
    else if(experience>=5&&experience<10) position="Junior";
    else position="Senior";
}
void Employee::setSalary()
{
    if(experience<5)
    {
        salary=30000+experience*2000;
    }
    else if(experience>=5&&experience<10)
    {
        salary=50000+(experience-5)*5000;
    }
    else if(experience>=10)
    {
        salary=100000+(experience-10)*10000;
    }
}
void Employee::setDesignation(std::string val)
{
    if(val=="Web Development")
        designation=Designation::Web_Development;
    else if(val=="Data Science")
        designation=Designation::Data_Science;
    else if(val=="Application Development")
        designation=Designation::Application_Development;
    else if(val=="Mobile Development")
        designation=Designation::Mobile_Development;
    else if(val=="Embedded Systems")
        designation=Designation::Embedded_Systems;
    else if(val=="Cloud Computing")
        designation=Designation::Cloud_Computing;
    else
        std::cout<<"Invalid designation input for employee "<<getName()<<std::endl;
}
std::string Employee::getDesignation()
{
    if(designation==Designation::Web_Development)
        return std::string("Web Development");
    else if(designation==Designation::Mobile_Development)
        return std::string("Mobile Development");
    else if(designation==Designation::Data_Science)
        return std::string("Data Science");
    else if(designation==Designation::Application_Development)
        return std::string("Application Development");
    else if(designation==Designation::Embedded_Systems)
        return std::string("Embedded Systems");
    else if(designation==Designation::Cloud_Computing)
        return std::string("Cloud Computing");
    else
        return std::string("");
}
void Employee::calcBonus()
{
    bonus=getSalary();
    bonus=bonus/10;
}

void Employee::displayinfo()
{
    Person::displayinfo();
    std::cout<<"Employee ID\t\t: "<<getEmployeeID()<<std::endl;
    std::cout<<"Designation\t\t: "<<getDesignation()<<std::endl;
    std::cout<<"Experience\t\t: "<<getExperience()<<std::endl;
    std::cout<<"Position\t\t: "<<getPosition()<<std::endl;
    std::cout<<"Salary\t\t\t: "<<getSalary()<<std::endl;
    std::cout<<"Project ID\t\t: "<<getProjectId()<<std::endl;
}
void Employee::generatePassword()
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

void Employee::setinfo(std::string nam,std::string phn,std::string addr,std::string em,std::string des,int ex)
{
    Person::setName(nam);
    Person::setPhone_no(phn);
    Person::setAddress(addr);
    Person::setEmail(em);
    setDesignation(des);
    setExperience(ex);
    setPosition();
    setSalary();
    calcBonus();
}
Employee Employee::operator =(Employee& e1)
{

    employee_id=e1.employee_id;
    name=e1.name;
    phone_no=e1.phone_no;
    address=e1.address;
    email=e1.email;
    designation=e1.designation;
    experience=e1.experience;
    projectid=e1.projectid;
    position=e1.position;
    salary=e1.salary;
    bonus=e1.bonus;
    return *this;

}

