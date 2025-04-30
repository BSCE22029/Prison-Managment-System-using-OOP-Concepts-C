#ifndef PUNISHMENT_H
#define PUNISHMENT_H
#pragma once
//#include"user_defined.h"
using namespace std;
#include <string>


class Punishment 
{
    private:
        string type;
        string duration;
    public:
        Punishment();
        Punishment(string type,string duration);
        void settype(string type);
        void setduration(string duration);
        string getType() ;
        string getDuration() ;
        void displayInfo() ;
        json toJson();
        static Punishment fromJson(const json& j);
        void readFromJsonFile(string filename);
};

#endif // PUNISHMENT_H
