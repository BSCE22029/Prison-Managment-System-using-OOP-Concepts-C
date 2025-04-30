#include "prisoner.h"
#include"person.h"
#include <iostream>
#pragma once

Prisoner::Prisoner()
{
    prisonerID=" ";
    sentence=" ";
    releaseDate=" ";
    // this->name=" ";
    // this->age=0;
    // this->address=" ";

}

Prisoner::Prisoner(string name,int age,string address,string prisonerID,string sentence,string releaseDate):Person(name, age, address)
{
    this->prisonerID=prisonerID;
    this->sentence=sentence;
    this->releaseDate=releaseDate;
}

//Prisoner::~Prisoner() {}
string Prisoner::getPrisonerID()  
{
    return prisonerID;
}

string Prisoner::getSentence()  
{
    return sentence;
}

string Prisoner::getReleaseDate()  
{
    return releaseDate;
}

void Prisoner::updateSentence(string newSentence) 
{
    this->sentence = newSentence;
}

void Prisoner::updateReleaseDate(string newReleaseDate) 
{
    this->releaseDate = newReleaseDate;
}

void Prisoner::displayInfo()  {
    cout << "Prisoner Information:" << endl;
    Person::displayInfo();
    cout << "Prisoner ID: " << prisonerID << ", Sentence: " << sentence << ", Release Date: " << releaseDate << endl;
}
json Prisoner:: toJSON()
{
return{
    {"name", name},
    {"age", age},
    {"address", address},
    {"prisonerID", prisonerID},
    {"sentence", sentence},
    {"releaseDate", releaseDate}
};
}

istream& operator>>(istream& is,Prisoner &obj)
{
    cout<<"Enter the name of prisoner:";
    is>>obj.name;
    cout<<"Enter the age of prison:";
    is>>obj.age;
    cout<<"Enter the address of prison:";
    is>>obj.address;
    cout<<"Enter the sentence of prison:";
    is>>obj.sentence;
    cout<<"Enter the release date of prison:";
    is>>obj.releaseDate;
    return is;
}