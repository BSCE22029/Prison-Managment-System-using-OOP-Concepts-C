#ifndef PROJECT_GROUP_HHH_PERSON_H
#define PROJECT_GROUP_HHH_PERSON_H

#pragma once
#include <string>
using namespace std;  

class Person 
{
    protected:
        string name;
        int age;
        string address;
    public:
        Person();
        Person(string name, int age,string address);

       // virtual ~Person();
        virtual void displayInfo();
};

#endif //PROJECT_GROUP_HHH_PERSON_H
