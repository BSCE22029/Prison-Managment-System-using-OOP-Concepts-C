#include "standard_header.h"
#include "criminal.h"

// Default constructor
Criminal::Criminal() {
    this->address = "N/A";
    this->criminal_record = "N/A";
    this->age = 0;
    this->name = "";
    this->wanted_status = false;
}

// Parameterized constructor
Criminal::Criminal(string name, int age, string address, string criminal_record, bool wanted_status) : Person(name, age, address) {
    this->criminal_record = criminal_record;
    this->wanted_status = wanted_status;
}

// Update criminal record
void Criminal::updateRecord(string new_record) {
    this->criminal_record = new_record;
}

// Update wanted status
void Criminal::updateWantedStatus(bool status) {
    this->wanted_status = status;
}

// Get the name of criminal
string Criminal::getname() {
    return name;
}

// Get the age of criminal  
int Criminal::getage() {
    return age;
}

// Get address of criminal
string Criminal::getaddress() {
    return address;
}

// Get the records of criminal
string Criminal::getcriminal_record() {
    return criminal_record;
}

// Get the wanted status of criminal
bool Criminal::getwanted_status() {
    return wanted_status;
}

// Convert the data to JSON
json Criminal::toJson() {
    json j;
    j["name"] = this->name;
    j["age"] = this->age;
    j["address"] = this->address;
    j["CriminalRecord"] = this->criminal_record;
    j["WantedStatus"] = this->wanted_status;
    return j;
}

// Convert the data from JSON to class type
Criminal* Criminal::fromJson(const json& j) {
    Criminal* obj = new Criminal();
    obj->name = j["name"];
    obj->age = j["age"];
    obj->address = j["address"];
    obj->criminal_record = j["CriminalRecord"];
    obj->wanted_status = j["WantedStatus"];
    return obj;
}

// Write criminal data to a JSON file
void Criminal::writeToJsonFile(string filename, json data) {
    try {
        fstream file(filename,ios::out|ios::app);
        if (file.is_open()) {
            file << data.dump(4); // Dump JSON data with indentation
            cout << "Data written to " << filename << " successfully." << endl;
        } else {
            throw runtime_error("Unable to open file: " + filename);
        }
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
}

// Read criminal data from a JSON file
void Criminal::readFromJsonFile(string filename) {
    try {
        ifstream file(filename);
        if (file.is_open()) {
            json data;
            file >> data;
            cout << "Data read from " << filename << ":" << endl;
            for (auto item : data) {
                // Assuming each item in the JSON array is a Criminal object
                Criminal* criminal = Criminal::fromJson(item);
                cout << "Name: " << criminal->getname() << endl;
                cout << "Age: " << criminal->getage() << endl;
                cout << "Address: " << criminal->getaddress() << endl;
                cout << "Criminal Record: " << criminal->getcriminal_record() << endl;
                cout << "Wanted Status: " << (criminal->getwanted_status() ? "Wanted" : "Not Wanted") << endl;
                cout << endl;
                delete criminal; // Free memory allocated for each criminal object
            }
        } else {
            throw runtime_error("Unable to open file: " + filename);
        }
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
    }
}
