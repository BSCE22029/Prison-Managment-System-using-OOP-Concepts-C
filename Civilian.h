#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "person.h"
#include <string>

// is a sub class of person
class Civilian:public Person
{
    private:
        string job;
        string educationLevel;
    public:
        Civilian();
        Civilian( string name, int age,string address,string job,  string educationLevel);
        ~Civilian();
        string getname();
        int getage();
        string getaddress();
        string getjob();
        string geteducationLevel();
        void displayInfo();
        friend istream& operator >>(istream& is,Civilian& obj);
};

#endif // CIVILIAN_H
