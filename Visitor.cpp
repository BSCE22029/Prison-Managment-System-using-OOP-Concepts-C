#include "visitor.h"
#include <iostream>

Visitor::Visitor(string name, int age,string address ,int visitorID, string relationship)
    : Person(name, age, address), visitorID(visitorID), relationship(relationship) {}

Visitor::~Visitor() {}

void Visitor::displayInfo()  {
    cout << "Visitor Information:" << std::endl;
    cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    cout << "Visitor ID: " << visitorID << ", Relationship: " << relationship << endl;
}

string Visitor:: getname()
{
    return name;
}
int Visitor::getage()
{
    return age;
}
string Visitor::getaddress()
{
    return address;
}
int Visitor::getvisitorID()
{
    return visitorID;
}
string Visitor::getrelationship()
{
    return relationship;
}
json Visitor::toJSON() {
    json visitorJson;
    visitorJson["name"] = name;
    visitorJson["age"] = age;
    visitorJson["address"] = address;
    visitorJson["visitorID"] = visitorID;
    visitorJson["relationship"] = relationship;
    return visitorJson;
}

void Visitor:: saveVisitorRecord(Visitor visitor,string filename) {
    // Read existing records if any
    ifstream file(filename);
    json records;
    if (file.is_open()) {
        file >> records;
        file.close();
    }

    // Add new visitor record
    records["visitors"].push_back(visitor.toJSON());

    // Write updated records to file
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << setw(4) << records << endl;
        outFile.close();
        cout << "Visitor record saved successfully." << endl;
    } else {
        cout << "Error: Unable to open " << filename << " for writing." << endl;
    }
}
ostream& operator<<(ostream& os,  Visitor visitor) {
    os << "Visitor Information:" << endl;
    os << "Name: " << visitor.name << ", Age: " << visitor.age << ", Address: " << visitor.address << endl;
    os << "Visitor ID: " << visitor.visitorID << ", Relationship: " << visitor.relationship << endl;
    return os;
}