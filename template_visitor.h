#ifndef VISITOR_H
#define VISITOR_H

#include "standard_header.h"
#include <string>

template<typename VisitorIDType, typename RelationshipType>
class Visitor : public Person {
private:
    VisitorIDType visitorID;
    RelationshipType relationship;

public:
    Visitor(std::string name, int age, std::string address, VisitorIDType visitorID, RelationshipType relationship);
    ~Visitor();
    void displayInfo();
    std::string getname();
    int getage();
    std::string getaddress();
    VisitorIDType getvisitorID();
    RelationshipType getrelationship();
    json toJSON();
    void saveVisitorRecord(Visitor<VisitorIDType, RelationshipType> visitor, std::string filename);
    friend std::ostream& operator<<(std::ostream& os, const Visitor<VisitorIDType, RelationshipType>& visitor);
};

template<typename VisitorIDType, typename RelationshipType>
Visitor<VisitorIDType, RelationshipType>::Visitor(std::string name, int age, std::string address, VisitorIDType visitorID, RelationshipType relationship)
    : Person(name, age, address), visitorID(visitorID), relationship(relationship) {}

template<typename VisitorIDType, typename RelationshipType>
Visitor<VisitorIDType, RelationshipType>::~Visitor() {}

template<typename VisitorIDType, typename RelationshipType>
void Visitor<VisitorIDType, RelationshipType>::displayInfo() {
    std::cout << "Visitor Information:" << std::endl;
    std::cout << "Name: " << name << ", Age: " << age << ", Address: " << address << std::endl;
    std::cout << "Visitor ID: " << visitorID << ", Relationship: " << relationship << std::endl;
}
 
template<typename VisitorIDType, typename RelationshipType>
std::string Visitor<VisitorIDType, RelationshipType>::getname() {
    return name;
}

template<typename VisitorIDType, typename RelationshipType>
int Visitor<VisitorIDType, RelationshipType>::getage() {
    return age;
}

template<typename VisitorIDType, typename RelationshipType>
std::string Visitor<VisitorIDType, RelationshipType>::getaddress() {
    return address;
}

template<typename VisitorIDType, typename RelationshipType>
VisitorIDType Visitor<VisitorIDType, RelationshipType>::getvisitorID() {
    return visitorID;
}

template<typename VisitorIDType, typename RelationshipType>
RelationshipType Visitor<VisitorIDType, RelationshipType>::getrelationship() {
    return relationship;
}

template<typename VisitorIDType, typename RelationshipType>
json Visitor<VisitorIDType, RelationshipType>::toJSON() {
    json visitorJson;
    visitorJson["name"] = name;
    visitorJson["age"] = age;
    visitorJson["address"] = address;
    visitorJson["visitorID"] = visitorID;
    visitorJson["relationship"] = relationship;
    return visitorJson;
}

template<typename VisitorIDType, typename RelationshipType>
void Visitor<VisitorIDType, RelationshipType>::saveVisitorRecord(Visitor<VisitorIDType, RelationshipType> visitor, std::string filename) {
    // Implement saveVisitorRecord function here
}

template<typename VisitorIDType, typename RelationshipType>
std::ostream& operator<<(std::ostream& os, const Visitor<VisitorIDType, RelationshipType>& visitor) {
    os << "Visitor Information:" << std::endl;
    os << "Name: " << visitor.name << ", Age: " << visitor.age << ", Address: " << visitor.address << std::endl;
    os << "Visitor ID: " << visitor.visitorID << ", Relationship: " << visitor.relationship << std::endl;
    return os;
}

#endif // VISITOR_H
