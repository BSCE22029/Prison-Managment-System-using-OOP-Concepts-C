#include "police_officer.h"
#include <iostream>

PoliceOfficer::PoliceOfficer(string name, int age,string address,string badgeNumber,string rank)
    : Person(name, age, address), badgeNumber(badgeNumber), rank(rank) {}

PoliceOfficer::~PoliceOfficer() {}

void PoliceOfficer::assignCase(Case* cas) {
    casesAssigned.push_back(cas);
}

void PoliceOfficer::updateRank(string newRank) {
    rank = newRank;
}

void PoliceOfficer::displayInfo() {
    Person::displayInfo();
    cout << "Badge Number: " << badgeNumber << ", Rank: " << rank << endl;
}

// void PoliceOfficer::displayPoliceOfficerInfo(PoliceOfficer officer) {
//     cout << "Police Officer Information:" << endl;
//     cout << "Name: " << officer.name << endl; // 'name' is accessible because the function is a friend of PoliceOfficer
//     cout << "Age: " << officer.age << endl; // 'age' is accessible because the function is a friend of PoliceOfficer
//     cout << "Address: " << officer.address << endl; // 'address' is accessible because the function is a friend of PoliceOfficer
//     cout << "Badge Number: " << officer.badgeNumber << endl; // 'badgeNumber' is accessible because it's a member of PoliceOfficer
//     cout << "Rank: " << officer.rank << endl; // 'rank' is accessible because it's a member of PoliceOfficer
// }
// void PoliceOfficer::storePoliceOfficerDataToJson(vector<PoliceOfficer> officers,string filename) {
//     json j;
//     for (auto officer : officers) {
//         json officerData;
//         officerData["name"] = officer.name;
//         officerData["age"] = officer.age;
//         officerData["address"] = officer.address;
//         officerData["badgeNumber"] = officer.badgeNumber;
//         officerData["rank"] = officer.rank;
//         j["officers"].push_back(officerData);
//     }
    
//     ofstream file(filename);
//     file << j.dump(4); // Pretty print JSON with 4 spaces indentation
//     file.close();
// }
// void PoliceOfficer:: readPoliceOfficerDataFromJson(string filename) {
//     ifstream file(filename);
//     if (!file.is_open()) {
//         cout<< "Error: Unable to open file " << filename <<endl;
//         return;
//     }

//     json j;
//     file >> j;

//     cout << "Police Officers Information:" << endl;
//     for (auto officerData : j["officers"]) {
//         cout << "Name: " << officerData["name"] << endl;
//         cout << "Age: " << officerData["age"] << endl;
//         cout << "Address: " << officerData["address"] << endl;
//         cout << "Badge Number: " << officerData["badgeNumber"] << endl;
//         cout << "Rank: " << officerData["rank"] << endl;
//         cout << endl;
//     }

//     file.close();
// }
// Inside the PoliceOfficer class declaration
// bool operator==( PoliceOfficer other)  {
//     return badgeNumber == other.badgeNumber;
// }

void PoliceOfficer::storePoliceOfficerDataToJson(vector<PoliceOfficer> officers, string filename) {
    json j;
    for (auto officer : officers) {
        json officerData;
        officerData["name"] = officer.name;
        officerData["age"] = officer.age;
        officerData["address"]=officer.address;
        officerData["badgeNumber"] = officer.badgeNumber;
        officerData["rank"] = officer.rank;
        j["officers"].push_back(officerData);
    }
    
    ofstream file(filename);
    file << j.dump(4); // Pretty print JSON with 4 spaces indentation
    file.close();
}
void PoliceOfficer::readPoliceOfficerDataFromJson(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    json j;
    file >> j;

    cout << "Police Officers Information:" << endl;
    for (auto& officerData : j["officers"]) {
        cout << "Name: " << officerData["name"] << ", Age: " << officerData["age"] << ", Address: " << officerData["address"] << ", ";
        cout << "Badge Number: " << officerData["badgeNumber"] << ", Rank: " << officerData["rank"] << endl;
    }

    file.close();
}