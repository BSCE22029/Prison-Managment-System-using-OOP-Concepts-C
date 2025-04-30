#include"standard_header.h"
#include "victim.h"

// default constructor 
template<typename T>
Victim<T>::Victim()
{
    this->address="N/A";
    this->age=0;
    this->name="";
    this->statement="N/A";
    this->victimId="N/A";
}

// parameterized constructor also called the constructor of person class
template<typename T>
Victim<T>::Victim(T name,int age,T address,T victimId,T statement):Person(name,age,address)
{
    this->statement=statement;
    this->victimId=victimId;
}

// to update the case statement
template<typename T>
void Victim<T>::updateStatement(T newStatement)
{
    this->statement=newStatement;
}

// convert the data from class to json
template<typename T>
json Victim<T>::toJson()
{
    json j;
    j["id"]=this->victimId;
    j["name"]=this->name;
    j["age"]=this->age;
    j["address"]=this->address;
    j["statement"]=this->statement;
    return j;   
}

// convert the data from json to class type
template<typename T>
Victim<T> Victim<T>::fromJson(const json& j)
{
    Victim<T> obj;
    obj.victimId=j["id"];
    obj.name=j["name"];
    obj.age=j["age"];
    obj.address=j["address"];
    obj.statement=j["statement"];
    return obj;
}

template class Victim<string>;