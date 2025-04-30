#ifndef PROJECT_GROUP_HHH_VICTIM_H
#define PROJECT_GROUP_HHH_VICTIM_H


#include"standard_header.h"
#include"person.h"

// is a sub template class and inherit from person class
class Case; // forward declaration of case class 
template<class T>
class Victim:public Person
{
    private:
        T victimId;
        T statement;
    public:
        Victim();
        Victim(T name,int age,T address,T victimId,T statement);
        void updateStatement(T newStatement);
        json toJson();
        static Victim fromJson(const json& j);
        friend class Case;
};


#endif //PROJECT_GROUP_HHH_VICTIM_H