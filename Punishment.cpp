#include"standard_header.h"
#include"punishment.h"
#include <iostream>

// default constructor
Punishment::Punishment()
{
    this->duration="N/A";
    this->type="N/A";
}

// parameterized constructor
Punishment::Punishment( string type,string duration): type(type), duration(duration){}

// set type of punishmnt
void Punishment:: settype(string type)
{
    this->type=type;
}

// set the duration of punishment
void Punishment:: setduration(string duration)
{
    this->duration=duration;
}

// get type
string Punishment::getType()  
{
    return type;
}

// get duration
string Punishment::getDuration()  
{
    return duration;
}

// display info
void Punishment::displayInfo()  
{
    cout << "Punishment Type: " << type << ", Duration: " << duration << endl;
}

// convert data from class to json type
json Punishment::toJson()
{
    json j;
    j["Type"]=this->type;
    j["Duration"]=this->duration;
    return j;
}

// convert data from json to class type
Punishment Punishment::fromJson(const json& j)
{
    Punishment obj;
    obj.type=j["Type"];
    obj.duration=j["Duration"];
    return obj;
}
void Punishment::readFromJsonFile(string filename) {
    // Open the JSON file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open " << filename << endl;
        return;
    }

    // Parse the JSON data
    json data;
    try {
        file >> data;
    } catch (json::parse_error& e) {
        cout << "Failed to parse " << filename << ": " << e.what() <<endl;
        return;
    }

    // Close the file
    file.close();

    // Process the JSON data
    for (const auto& punishmentJson : data) {
        Punishment punishment;
        punishment.settype(punishmentJson["Type"]);
        punishment.setduration(punishmentJson["Duration"]);
        
        // Do something with the punishment object, such as adding it to a vector or displaying it
        // For example:
        punishment.displayInfo();
    }
}