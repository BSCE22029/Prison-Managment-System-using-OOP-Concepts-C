#ifndef PROJECT_GROUP_HHH_FORENSIC_LABORATORY_H
#define PROJECT_GROUP_HHH_FORENSIC_LABORATORY_H

#pragma once
#include <string>
#include <vector>
#include<fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class ForensicLaboratory 
{
    private:
        string location;
        vector<string> equipment;
    public:
        ForensicLaboratory();
        ForensicLaboratory(string location);
        void addEquipment(string equipmentItem);
        string getLocation() ;
        vector<string> getEquipment() ;
        void displayInfo() ;
        json toJSON();
        static ForensicLaboratory fromJson(const json& j);
        void readDataFromJson( string filename);
        void storeDataToJson(string filename);
};

#endif // FORENSICLABORATORY_H
