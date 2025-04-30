#include"function.h"

void writeCivilianDataToFile( Civilian civilian) {
    // Create JSON object to store civilian data
    json civilianData;
    civilianData["name"] = civilian.getname();
    civilianData["age"] = civilian.getage();
    civilianData["address"] = civilian.getaddress();
    civilianData["job"] = civilian.getjob();
    civilianData["educationLevel"] = civilian.geteducationLevel();
// Write JSON datas
    ofstream outputFile("civilians.json");
    if (outputFile.is_open()) {
        outputFile <<setw(4) << civilianData <<endl;
        outputFile.close();
        cout << "Civilian data stored successfully." <<endl;
    } else {
        cout << "Error opening file: " <<endl;
    }
}

Civilian readCivilianDataFromFile() {
    // Open the JSON file
    ifstream inputFile("civilians.json");
    if (!inputFile.is_open()) {
    cout << "Error opening file: " << endl;
        // Return a default-constructed Civilian object if file opening fails
        return ;
    }

    // Parse the JSON data
    json jsonData;
    inputFile >> jsonData;
    inputFile.close();

    // Extract civilian data from JSON object
    string name = jsonData["name"];
    int age = jsonData["age"];
    string address = jsonData["address"];
    string job = jsonData["job"];
    string educationLevel = jsonData["educationLevel"];
    Civilian c(name, age, address, job, educationLevel);
    // Create and return a Civilian object
    return c;
}

