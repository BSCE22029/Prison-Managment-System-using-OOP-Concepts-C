#ifndef PROJECT_GROUP_HHH_CASE_H
#define PROJECT_GROUP_HHH_CASE_H

#include"standard_header.h"
#include"criminal.h"
#include"evidence.h"
#include"victim.h"
#include"lawyer.h"
#include"punishment.h"
#include"forensic_laboratory.h"
// aggregates the above declared classes
template<typename T>
class Victim;

class Case 
{
    private:
        string case_number,details,status,category,date;
        vector<Criminal*> suspects;
        vector<Evidence*> evidences;
        vector<Victim<string>*> victims;
        vector<Lawyer> lawyers;
        vector<Punishment*> punishments;
        vector<ForensicLaboratory*> forensicLaboratorys;
        map<string,string> assign;
    public:
        Case();
        Case(string case_number,string details,string status,string category,string date);
        void displayInfo();
        void addSuspects(Criminal *criminal); // aggregation that a case can have multiple suspects
        void updateStatus(string new_status); 
        void addEvidence(Evidence *evidence); // aggregation that a case can have multiple evidence
        void addVictim(Victim<string>*victim); // aggregation that a case can have multiple victims
        void addForensicLab(ForensicLaboratory *lab); // aggregation that a case can include multiple labs
        void addPunishments(Punishment* punishment);// aggregation that a case can have multiple punishments
        void addLawyer(Lawyer lawyer);
        void assignCase(string caseNum,string officerId); // to assign case to a specific officer
        vector<Criminal*> getSuspect();
        json toJson();
        static Case fromJson(const json& j);
        string getcase_number();
        string getdetails();
        string getstatus();
        string getcategory();
        friend ostream& operator <<(ostream& os,Case & cas);
};


#endif //PROJECT_GROUP_HHH_CASE_H
