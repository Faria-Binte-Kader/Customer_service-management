#ifndef PERSON_H
#define PERSON_H


class Person
{
    public:
        Person(string nam,long long int phn,string addr,string em);
        virtual ~Person();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        long long int Getphone_no() { return phone_no; }
        void Setphone_no(long long int val) { phone_no = val; }
        string Getaddress() { return address; }
        void Setaddress(string val) { address = val; }
        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

    protected:
        string name;
        long long int phone_no;
        string address;
        string email;
        string password;
};

#endif // PERSON_H
