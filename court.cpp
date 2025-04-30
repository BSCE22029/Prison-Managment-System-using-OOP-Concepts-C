#include "court.h"
#include <iostream>

Court::Court(string courtID, string location)
    : courtID(courtID), location(location) {}

Court::~Court() {
    // Clean up memory for associated judges and cases
    for (auto judge : judges) {
        delete judge;
    }
    // for (auto courtCase : cases) {
    //     delete courtCase;
    // }
}

void Court::addJudge(Judge* judge) {
    judges.push_back(judge);
}

// void Court::addCase(Case* courtCase) {
//     cases.push_back(courtCase);
//}

void Court::displayInfo()  {
    cout << "Court Information:" << endl;
    cout << "Court ID: " << courtID << ", Location: " << location << endl;

    cout << "Judges:" << endl;
    for (auto judge : judges) {
        judge->displayInfo();
    }

    cout << "Cases:" << endl;
    // for (auto courtCase : cases) {
    //     courtCase->displayInfo();
    // }
}
