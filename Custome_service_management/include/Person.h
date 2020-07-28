#ifndef PERSON_H
#define PERSON_H
#include<iostream>

using namespace std;
class Person
{
    public:
        Person();
        Person(string nam,string phn,string addr,string em);
        virtual ~Person();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getphone_no() { return phone_no; }
        void Setphone_no(string val) { phone_no = val; }
        string Getaddress() { return address; }
        void Setaddress(string val) { address = val; }
        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        char* Getpassword() { return password; }
        void displayinfo();
        virtual void generatePassword() = 0;
    protected:
        string name;
        string phone_no;
        string address;
        string email;
        char *password;

        void Setpassword(char *c);

};

#endif // PERSON_H


