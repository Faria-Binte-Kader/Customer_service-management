#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
struct Date
{
    int day;
    int month;
    int year;
    Date()
    {

    }
    Date(int d,int m,int y):day(d),month(m),year(y)
    {

    }
};
class Person
{
protected:
    std::string name;
    std::string phone_no;
    std::string address;
    std::string email;
    char *password;
public:
    Person();
    Person(std::string nam,std::string phn,std::string addr,std::string em);
    virtual ~Person();
    std::string getName()
    {
        return name;
    }
    void setName(std::string val)
    {
        name=val;
    }
    std::string getPhone_no()
    {
        return phone_no;
    }
    void setPhone_no(std::string val)
    {
        phone_no=val;
    }
    std::string getAddress()
    {
        return address;
    }
    void setAddress(std::string val)
    {
        address=val;
    }
    std::string getEmail()
    {
        return email;
    }
    void setEmail(std::string val)
    {
        email=val;
    }
    char* getPassword()
    {
        return password;
    }
    void setPassword(char *c);
    virtual void generatePassword()=0;
    void displayinfo();
};
#endif
