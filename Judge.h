#ifndef JUDGE_H
#define JUDGE_H

#include "person.h"
#include <string>

class Judge : public Person 
{
    private :
        string judgeID;
        string specialization;
        // Private constructor to prevent external instantiation
        Judge(string name, int age, string address,string judgeID,string specialization);
    public:
        // Deleted copy constructor and assignment operator to prevent copying
        Judge(const Judge&) = delete;
        Judge& operator=(const Judge&) = delete;
        // Public static method to access the singleton instance
        static Judge& getInstance();
         ~Judge();
         void displayInfo();
};


#endif // JUDGE_H
