#pragma once
#include <iostream>
using namespace std;
#include "civilian.h"

// default constructor
Civilian::Civilian()
{
    this->name="N/A";
    this->address="N/A";
    this->age=0;
    this->educationLevel="N/A";
    this->job="N/A";
}

// parameterized constructor also call the constructor of person class
Civilian::Civilian(string name, int age, string address,string job, string educationLevel)
: Person(name, age, address), job(job), educationLevel(educationLevel) {}

// destructor does nothing
Civilian::~Civilian() {}

// polymorphism
void Civilian::displayInfo()
{
    cout << "Civilian Information:" << endl;
    cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    cout << "Job: " << job << ", Education Level: " << educationLevel << endl;
}

// getter
string Civilian::getname()
{
    return name;
}

//getter
int Civilian::getage()
{
    return age;
}

// getter
string Civilian::getaddress()
{
    return address;
}

// getter
string Civilian::getjob()
{
    return job;
}

// getter
string Civilian::geteducationLevel()
{
    return educationLevel;
}

// friend function and operator overloading
istream& operator >>(istream& is,Civilian& obj) // used in case 5 of calling
{
    cout<<"Enter the name of civilian:";
    getline(is>>ws,obj.name);
    cout<<"Enter the age of civilian:";
    is>>obj.age;
    cout<<"Enter the address of civilian:";
    getline(is>>ws,obj.address);
    cout<<"Enter the educational level of civilian:";
    getline(is>>ws,obj.educationLevel);
    cout<<"Enter the job of civilian:";
    getline(is>>ws,obj.job);
    return is;
}