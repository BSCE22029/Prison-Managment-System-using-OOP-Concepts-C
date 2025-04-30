#ifndef VISITOR_H
#define VISITOR_H
#pragma once
#include"standard_header.h"
#include "person.h"
#include <string>
#include<fstream>
using namespace std;

class Visitor : public Person {
private:
    int visitorID;
    string relationship;

public:
    Visitor(string name, int age,string address,
            int visitorID, string relationship);
    virtual ~Visitor();
string getname();
int getage();
string getaddress();
int getvisitorID();
string getrelationship();
     void displayInfo() ;
    json toJSON();
    void saveVisitorRecord(Visitor visitor,string filename);
   friend ostream& operator<<(ostream& os,  Visitor visitor);
};

#endif // VISITOR_H
