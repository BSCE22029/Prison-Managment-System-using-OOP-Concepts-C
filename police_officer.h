#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#pragma once
using namespace std;
#include "person.h"
#include "case.h" // Include necessary headers for related classes
#include <string>
#include <vector>

class PoliceOfficer : public Person 
{
    private:
        string badgeNumber;
        string rank;
        vector<Case*> casesAssigned;
    public:
        PoliceOfficer(string name, int age,string address,string badgeNumber,string rank);
        virtual ~PoliceOfficer();
        void assignCase(Case* cas);
        void updateRank(string newRank);
        virtual void displayInfo() ;
       // friend void displayPoliceOfficerInfo(PoliceOfficer officer);
  //   friend void storePoliceOfficerDataToJson(vector<PoliceOfficer> officers,string filename);
   //  void readPoliceOfficerDataFromJson(string filename);
// bool operator==(PoliceOfficer other);
//ostream operator<<(ostream os,PoliceOfficer officer);
void storePoliceOfficerDataToJson(vector<PoliceOfficer> officers, string filename);
void readPoliceOfficerDataFromJson(string filename);
};

#endif // POLICEOFFICER_H
