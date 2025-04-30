//#include"standard_header.h"
#include<iostream>
using namespace std;
#include "police_station.h"

// default constructor
Policestation::Policestation()
{
    this->name="N/A";
    this->location="N/A";
}

// parameterized constructor
Policestation::Policestation(string name,string location)
{
    this->name;
    this->location=location;
}

// add case to specific police station
void Policestation::addCase(Case* cas)
{
    cases.push_back(cas);
}

// add officers to police station
void Policestation::addOfficer(PoliceOfficer* officer)
{
    this->officers.push_back(officer);
}

// add civilian to police station
void Policestation::addCivilian(Civilian civilian)
{

    fstream add("civilians.json",ios::in);
    json j,ad;
    ad=json::array();
    add>>ad;
    add.close();
    add.open("civilians.json",ios::out);
    j["name"]=civilian.getname();
    j["age"]=civilian.getage();
    j["address"]=civilian.getaddress();
    j["education"]=civilian.geteducationLevel();
    j["job"]=civilian.getjob();
    ad.push_back(j);
    add<<ad.dump(4);
    add.close();
}

// to add prisoner to a police station
void Policestation::addPrisoner(Prisoner  prisoner)
{
    this->prisoners.push_back(prisoner);
}

// to display the civilian record
void Policestation::display() const
{
    fstream display("civilians.json",ios::in);
    json j;
    display>>j;
    display.close();
    cout<<" Civilian record:-\n";
    for(auto data:j)
    {
        cout<<"\tName:"<<data["name"]<<endl;
        cout<<"\tAge:"<<data["age"]<<endl;
        cout<<"\tAddress:"<<data["address"]<<endl;
        cout<<"\tEducation"<<data["education"]<<endl;
        cout<<"\tJob:"<<data["job"]<<endl;
        cout<<"=====================================================================\n\n";
    }
}