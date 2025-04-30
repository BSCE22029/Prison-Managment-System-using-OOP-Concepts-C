#include"standard_header.h"
#include"person.h"

Person::Person()
{
    this->name="";
    this->address="";
    this->age=0;
}

Person::Person(string name, int age,string address)
{
    this->name=name;
    this->age=age;
    this->address=address;
}

void Person::displayInfo()
{
    cout<<"jh";
}
//Person::~Person() {}
