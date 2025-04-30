#ifndef PROJECT_GROUP_HHH_CRIMINAL_H
#define PROJECT_GROUP_HHH_CRIMINAL_H

#include"standard_header.h"
#include"person.h"

// sub class of person class
class Criminal:public Person
{
    private:
        string criminal_record;
        bool wanted_status;
    public:
        Criminal();
        Criminal(string name,int age,string address,string criminal_record,bool wanted_status);
        void updateRecord(string new_record);
        void updateWantedStatus(bool status);
        string getname();
        int getage();
        string getaddress();
        string getcriminal_record();
        bool getwanted_status();
        json toJson();
        static Criminal* fromJson(const json& j);
        void writeToJsonFile(string filename,json data);
        void readFromJsonFile(string filename);
};


#endif //PROJECT_GROUP_HHH_CRIMINAL_H
