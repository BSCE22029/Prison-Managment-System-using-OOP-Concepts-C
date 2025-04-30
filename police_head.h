#ifndef CASE_CPP_POLICE_HEAD_H
#define CASE_CPP_POLICE_HEAD_H

#include"standard_header.h"

class PoliceHead 
{
    private:
        static PoliceHead* instancePtr;
        PoliceHead();
    public:
        static PoliceHead* getInstance();
        void addStation(string code,string location);
        ~PoliceHead();// destructor
};


#endif //CASE_CPP_POLICE_HEAD_H
