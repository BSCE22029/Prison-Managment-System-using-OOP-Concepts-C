#ifndef PROJECT_GROUP_HHH_PRISONER_H
#define PROJECT_GROUP_HHH_PRISONER_H

#pragma once
#include "person.h"
#include <string>
using namespace std;
#include "nlohmann/json.hpp"
using json = nlohmann::json;


class Prisoner : public Person 
{
    private:
        string prisonerID;
        string sentence;
        string releaseDate;
    public:
        Prisoner();
        Prisoner(string name,int age,string address,string prisonerID,string sentence,string releaseDate);
       // virtual ~Prisoner();
        string getPrisonerID() ;
        string getSentence() ;
        string getReleaseDate() ;
        void updateSentence( string newSentence);
        void updateReleaseDate( string newReleaseDate);
        json toJSON();
        friend istream& operator>>(istream& is,Prisoner &obj);
     void displayInfo() ;
};

#endif //PROJECT_GROUP_HHH_PRISONER_H
