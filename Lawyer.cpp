#include"standard_header.h"
#include "lawyer.h"

// default constructor
Lawyer::Lawyer()
{
    this->name="";
    this->age=0;
    this->address="N/A";
    this->lawyerID="N/A";
    this->specialization="N/A";
}

// parameterized constructor
Lawyer::Lawyer(string name, int age, string address,string lawyerID, string specialization)
    : Person(name, age, address), lawyerID(lawyerID), specialization(specialization) {}

    void Lawyer:: setName(string name){
       this-> name=name;
    }
      string Lawyer:: getName(){
        return name;
      }
      void Lawyer::setLawyerID(string lawyerID){
        this->lawyerID=lawyerID;
      }
string Lawyer:: getLawyerID(){
    return lawyerID;
}
void Lawyer:: setSpecialization(string specializatiion){
    this->specialization=specialization;
}
string Lawyer:: getSpecialization(){
    return specialization;
}
// display info
void Lawyer::displayInfo() 
{
    cout << "Lawyer Information:" <<endl;
    cout << "Name: " << name << ", Age: " << age << ", Address: " << address << endl;
    cout << "Lawyer ID: " << lawyerID << ", Specialization: " << specialization << endl;
}

// convert data from class type to json
json Lawyer::toJson()
{
    json j;
    j["id"]=this->lawyerID;
    j["name"]=this->name;
    j["age"]=this->age;
    j["specialization"]=this->specialization;
    j["address"]=this->address;
    return j;
}

// convert data from json type to class
Lawyer Lawyer::fromJson(const json& j)
{
    Lawyer obj;
    obj.lawyerID=j["id"];
    obj.name=j["name"];
    obj.age=j["age"];
    obj.specialization=j["specialization"];
    obj.address=j["address"];
    return obj;
}
ostream& operator<<(std::ostream& os, const Lawyer& lawyer) 
{
    os << "Lawyer Information:" << std::endl;
    os << "Name: " << lawyer.name << ", Age: " << lawyer.age << ", Address: " << lawyer.address << std::endl;
    os << "Lawyer ID: " << lawyer.lawyerID << ", Specialization: " << lawyer.specialization << std::endl;
    return os;
}
// operatoe overloading
istream& operator >>(istream& is,Lawyer& obj)
{
    cout<<"Enter the name of Lawyer:";
    getline(is>>ws,obj.name);
    cout<<"Enter the age of lawyer:";
    is>>obj.age;
    cout<<"Enter the id of lawyer:";
    getline(is>>ws,obj.lawyerID);
    cout<<"Enter the address of lawyer:";
    getline(is>>ws,obj.address);
    cout<<"Enter the specialization of lawyer:";
    getline(is>>ws,obj.specialization);
    return is;
}