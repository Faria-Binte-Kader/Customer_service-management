#include "Person.h"

Person::Person(string nam,long long int phn,string addr,string em):name(""),phone_no(0),address(""),email("")
{
    //ctors
    Setname(nam);
    Setphone_no(phn);
    Setaddress(addr);
    Setemail(em);
}

Person::~Person()
{
    //dtor
}
