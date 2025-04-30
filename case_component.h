#ifndef CASE_CPP_CASE_COMPONENT_H
#define CASE_CPP_CASE_COMPONENT_H

#include<iostream>
using namespace std;
#include<string>
class CaseComponent
{
        public:
                virtual void display()const=0;// pure virtual function for abstract class
};


#endif //CASE_CPP_CASE_COMPONENT_H
