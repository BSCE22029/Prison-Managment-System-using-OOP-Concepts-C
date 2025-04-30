#include "forensic_laboratory.h"
#include <iostream>

// default constructor
ForensicLaboratory::ForensicLaboratory()
{
    location="N/A";
}

// parameterized constructor
ForensicLaboratory::ForensicLaboratory(string location)
{
    this->location=location;
}

// add equipments in the forensic laboratory
void ForensicLaboratory::addEquipment(string equipmentItem) 
{
    equipment.push_back(equipmentItem); // add the name of equipment
}

// to get the location of lab
string ForensicLaboratory::getLocation()  
{
    return location;
}

// get the equipments in the lab
vector<string> ForensicLaboratory::getEquipment()  
{
    return equipment;
}

// display the iinformation of lab
void ForensicLaboratory::displayInfo()  
{
    cout << "Forensic Laboratory Information:" << endl;
    cout << "Location: " << location << endl;
    cout << "Equipment:" << endl;
    for (auto item : equipment) {
        cout << "- " << item << endl;
    }
}

// convert the class type to json
json ForensicLaboratory::toJSON()
{
    json j;
    j["location"]=location;
    for(const auto data:equipment)
    {
        j["equipment"].push_back(data);
    }
    return j;
}

// convert data from json to class type
ForensicLaboratory ForensicLaboratory::fromJson(const json& j)
{
    ForensicLaboratory obj;
    obj.location=j["location"];
    for(const auto data:j["equipment"])
    {
        obj.equipment.push_back(data);
    }
    return obj;
}
void ForensicLaboratory::storeDataToJson(string filename) {
    json labJson = toJSON(); // Convert class data to JSON
    fstream outFile(filename,ios::out|ios::app);
    if (outFile.is_open()) {
        outFile << setw(4) << labJson << endl; // Write JSON data to file
        outFile.close();
        cout << "Data stored in JSON format successfully." << endl;
    } else {
        cout << "Error: Unable to open " << filename << " for writing." << endl;
    }
}

// Read data from JSON file and display
void ForensicLaboratory::readDataFromJson(string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error: Unable to open " << filename << " for reading." << endl;
        return;
    }

    json labJson;
    inFile >> labJson; // Read JSON data from file

    // Convert JSON data to class type
    ForensicLaboratory lab = fromJson(labJson);

    // Display information
    lab.displayInfo();

    inFile.close();
}