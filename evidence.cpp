#include"standard_header.h"
#include"evidence.h"

// default constructor
Evidence::Evidence()
{
    this->itemId="N/A";
    this->details="N/A";
}

// parameterized constructor
Evidence::Evidence(string itemId,string details)
{
    this->itemId=itemId;
    this->details=details;
}

// to display info of evidence
void Evidence::displayInfo()
{
    cout<<"Item id:"<<this->itemId<<" ,Item name:"<<this->details<<endl;
}

// convert class type object to json
json Evidence::toJson()
{
    json j;
    j["itemId"]=this->itemId;
    j["itemName"]=this->details;
    return j;
}

// convert data from json to class type
Evidence Evidence::fromJson(const json& j)
{
    Evidence obj;
    obj.itemId=j["itemId"];
    obj.details=j["itemName"];
    return obj;
}
