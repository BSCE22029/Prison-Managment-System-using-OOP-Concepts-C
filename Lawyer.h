#ifndef LAWYER_H
#define LAWYER_H

#include "person.h"
#include <string>

class Lawyer : public Person 
{
    private:
        string lawyerID;
        string specialization;
    public:
        Lawyer();
        Lawyer(string name, int age, string address,string lawyerID, string specialization);
        void displayInfo();
        json toJson();
        static Lawyer fromJson(const json& j);
        friend std::ostream& operator<<(std::ostream& os, const Lawyer& lawyer);
        void setName(string name);
        string getName();
        void setLawyerID(string lawyerID);
        string getLawyerID();
        void setSpecialization(string specializatiion);
        string getSpecialization();
        friend istream& operator >>(istream& is,Lawyer& obj);
};


#endif // LAWYER_H
