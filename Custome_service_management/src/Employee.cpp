#include "Employee.h"

Employee::Employee(string nam,long long int phn,string addr,string em,string exp,int ex,string work):Person(nam,phn,addr,em),experience(""),experience(0),worksas("")
{
    //ctor
    id++;
    Setexperties(exp);
    Setexperience(ex);
    Setworksas(work);
    setEmployeeId(id);
}

Employee::~Employee()
{
    //dtor
}

void Employee::addCustomer(Customer c)
{
    if(workingfor+1>10) cout<<"Occupied"<<endl;
    else
    {
        customer[workingfor]=c;

        workingfor++;
    }
bool Employee::removeCustomer(int index)
{
    if(index+1>workingfor||index<0) return false;
    else if(index+1==workingfor)
    {
        workingfor--;
        return true;
    }
}
	/*double Employee::calcSalary(int experience)
	{



	}*/
