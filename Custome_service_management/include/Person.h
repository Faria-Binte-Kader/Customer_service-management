#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
class Person
{
protected:
    std::string name;
    std::string phone_no;
    std::string address;
    std::string email;
    char *password;
    void SetPassword(char *c);
public:
    Person();
    Person(std::string nam,std::string phn,std::string addr,std::string em);
    virtual ~Person();
    std::string GetName()
    {
        return name;
    }
    void SetName(std::string val)
    {
        name=val;
    }
    std::string GetPhone_no()
    {
        return phone_no;
    }
    void SetPhone_no(std::string val)
    {
        phone_no=val;
    }
    std::string GetAddress()
    {
        return address;
    }
    void SetAddress(std::string val)
    {
        address=val;
    }
    std::string GetEmail()
    {
        return email;
    }
    void SetEmail(std::string val)
    {
        email=val;
    }
    char* GetPassword()
    {
        return password;
    }
    virtual void generatePassword()=0;
    void displayinfo();
};
#endif
