#ifndef PROJECT_GROUP_HHH_POLICE_STATION_H
#define PROJECT_GROUP_HHH_POLICE_STATION_H

// #include"standard_header.h"
// #include"user_defined.h"
// #include"prisoner.h"
// #include"visitor.h"
// #include"case.h"
// #include"police_officer.h"
#pragma once
using namespace std;
#include<string>
#include<vector>
#include"case.h"
#include"civilian.h"
#include"Visitor.h"
#include"prisoner.h"
#include"police_officer.h"
#include"case_component.h"

class Policestation:public CaseComponent
{
    private:
        string location;
        string name;
        vector<Case*> cases;
        vector<PoliceOfficer*> officers;
        vector<Prisoner> prisoners;
    public:
        Policestation();
        Policestation(string name,string location);
        void addCase(Case* cas);
        void addOfficer(PoliceOfficer* officer);
        void addCivilian(Civilian  civilian);
        void display() const override;
       // void addVisitor(Visitor * visitor);
        void addPrisoner(Prisoner  prisoner);
        //json toJson();
};


#endif //PROJECT_GROUP_HHH_POLICE_STATION_H
