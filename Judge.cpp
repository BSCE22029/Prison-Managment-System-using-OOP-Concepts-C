#include "Judge.h"
#include <iostream>

// Define static instance of Judge
static Judge* judgeInstance = nullptr;

Judge::Judge(string name, int age, string address,
             string judgeID, string specialization)
    : Person(name, age, address), judgeID(judgeID), specialization(specialization) {}

Judge& Judge::getInstance() {
    // Create a new instance if it doesn't exist
    if (!judgeInstance) {
        judgeInstance = new Judge("Singleton Judge", 40, "Singleton Address", "J123", "General");
    }
    return *judgeInstance;
}

Judge::~Judge() {
    // Clean up the instance on destruction
    delete judgeInstance;
}

void Judge::displayInfo()  {
    cout << "Judge Information:" << endl;
    Person::displayInfo();
    cout << "Judge ID: " << judgeID << ", Specialization: " << specialization << endl;
}
/*
 // Get the singleton instance of Judge
    Judge& singletonJudge = Judge::getInstance();

    // Display information of the singleton Judge
    singletonJudge.displayInfo();
*/