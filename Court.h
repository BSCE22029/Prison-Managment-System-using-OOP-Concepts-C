#ifndef PROJECT_GROUP_HHH_COURT_H
#define PROJECT_GROUP_HHH_COURT_H

#include"standard_header.h"
#include"user_defined.h"
#include"judge.h"
// #include <string>
#include <vector>
// #include "judge.h" // Include Judge class for associated judges
// //#include "case.h"  // Include Case class for associed cases
#include"case.h"

class Court 
{
    private:
        //vector<Case *> cases;
        string courtID;
        string location;
        vector<Judge*> judges;
        //vector<Case*> cases;
    public:
        Court(string courtID, string location); 
        virtual ~Court();
        void addJudge(Judge* judge);
        //void addCase(Case* courtCase);
        void displayInfo() ;
};

#endif // COURT_H
