#ifndef LAWYER_H
#define LAWYER_H

#include "standard_header.h"
#include <string>

template<typename T>
class Lawyer : public Person {
private:
    T lawyerID;
    string specialization;

public:
    // Default constructor
    Lawyer();

    // Parameterized constructor
    Lawyer(string name, int age, string address, T lawyerID, string specialization);

    // Display info
    void displayInfo() override;

    // Convert data from class type to JSON
    json toJson();

    // Convert data from JSON type to class
    static Lawyer fromJson(const json& j);
};

// Default constructor
template<typename T>
Lawyer<T>::Lawyer() : lawyerID(T()), specialization("N/A") {}

// Parameterized constructor
template<typename T>
Lawyer<T>::Lawyer(std::string name, int age, std::string address, T lawyerID, std::string specialization)
    : Person(name, age, address), lawyerID(lawyerID), specialization(specialization) {}

// Display info
template<typename T>
void Lawyer<T>::displayInfo() {
    cout << "Lawyer Information:" << endl;
    cout << "Name: " << this->name << ", Age: " << this->age << ", Address: " << this->address << endl;
    cout << "Lawyer ID: " << this->lawyerID << ", Specialization: " << this->specialization << endl;
}

// Convert data from class type to JSON
template<typename T>
json Lawyer<T>::toJson() {
    json j;
    j["id"] = this->lawyerID;
    j["name"] = this->name;
    j["age"] = this->age;
    j["specialization"] = this->specialization;
    j["address"] = this->address;
    return j;
}

// Convert data from JSON type to class
template<typename T>
Lawyer<T> Lawyer<T>::fromJson(const json& j) {
    Lawyer<T> obj;
    obj.lawyerID = j["id"];
    obj.name = j["name"];
    obj.age = j["age"];
    obj.specialization = j["specialization"];
    obj.address = j["address"];
    return obj;
}

#endif // LAWYER_H
