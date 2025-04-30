#include"standard_header.h"
#include"case.h"

// default constructor
Case::Case()
{
    this->case_number="N/A";
    this->category="N/A";
    this->date="N/A";
    this->details="N/A";
    this->status="N/A";
}

// parameterized constructor
Case::Case(string case_number,string details,string status,string category,string date)
{
    this->case_number=case_number;
    this->details=details;
    this->status=status;   
    this->category=category;
    this->date=date;
}

// add suspect to case
void Case::addSuspects(Criminal *criminal)
{
    this->suspects.push_back(criminal);
}

// add victim to case
void Case::addVictim(Victim<string> * victim)
{
    this->victims.push_back(victim);
}

// add lawyers associated to case
void Case::addLawyer(Lawyer lawyer)
{
    this->lawyers.push_back(lawyer);
}

// add evidemce associated to case
void Case::addEvidence(Evidence *evidence)
{
    this->evidences.push_back(evidence);
}

// add labs associated with labs
void Case::addForensicLab(ForensicLaboratory* lab)
{
    this->forensicLaboratorys.push_back(lab);
}

// add punishments resulted in a case
void Case::addPunishments(Punishment* punishment)
{
    this->punishments.push_back(punishment);
}

// update status of case i.e: opend,closed
void Case::updateStatus(string new_status)
{
    this->status=new_status;
}

// assign case to a specific officer
void Case::assignCase(string caseNum,string officerNum)
{
    this->assign[caseNum]=officerNum;
}

// get case number
string Case::getcase_number()
{
    return case_number;
}

// get case details
string Case::getdetails()
{
    return details;
}

// get case status
string Case::getstatus()
{
    return this->status;
}

// get category of case
string Case::getcategory()
{
    return category;
}

// display info of case
void Case::displayInfo()
{
    cout<<"case display";
}

vector<Criminal*>Case::getSuspect()
{
    return this->suspects;
}


// convert data from class type to json
json Case::toJson()
{
    json j;
    j["Date"]=this->date;
    j["CaseNumber"]=this->case_number;
    // add the list of victims
    for(const auto data:victims)
    {
        j["Victims"].push_back(data->toJson());
    }
    j["Category"]=this->category;
    j["Detail"]=this->details;
    j["Status"]=this->status;
    // add the list of suspects
    for(const auto data:suspects)
    {
        j["Suspects"].push_back(data->toJson());
    }
    // add list of lawyers related to case
    for(auto data:lawyers)
    {
        j["Lawyers"].push_back(data.toJson()); // here composition exsist
    }
    // add evidences related to case
    for(const auto data:evidences)
    {
        j["Evidences"].push_back(data->toJson());
    }
    // add forensiclab associated in a case
    for(const auto data:forensicLaboratorys)
    {
        j["ForensicLab"].push_back(data->toJSON());
    }
    // add punishments associated in a case
    for(const auto data:punishments)
    {
        j["Punishment"].push_back(data->toJson());
    }
    return j;
}

// convert data from class type to json
Case Case::fromJson(const json& j)
{
    Case obj;
    obj.date=j["Date"];
    obj.case_number=j["CaseNumber"];
    // for(const auto data:j["Victims"])
    // {
    //     // obj.victims.push_back(&Victim::fromJson(data));
    //     obj.addVictim(&Victim::fromJson(data));
    // }
    obj.category=j["Category"];
    obj.details=j["Detail"];
    obj.status=j["Status"];
    // for(const auto data:j["Suspects"])
    // {
    //     // for(auto item:data)
    //     // {
    //     //     cout<<""<<item;
    //     // }
    //     obj.suspects.push_back(Criminal::fromJson(data));
    // }
    // for(const auto data:j["Lawyers"])
    // {
    //     obj.addLawyer(&Lawyer::fromJson(data));
    // }
    // for(const auto data:j["Evidences"])
    // {
    //     obj.addEvidence(&Evidence::fromJson(data));
    // }
    // for(const auto data:j["ForensicLab"])
    // {
    //     obj.addForensicLab(&ForensicLaboratory::fromJson(data));
    // }
    // for(const auto data:j["Punishment"])
    // {
    //     obj.addPunishments(&Punishment::fromJson(data));
    // }
    return obj;
}

ostream& operator <<(ostream& os,Case& cas)
{
    fstream display("cases.json",ios::in);
    json data;
    display>>data;
    display.close();
    for(auto item:data)
    {
        os<<"\tCase Number:"<<item["CaseNumber"]<<endl;
        os<<"\tCase filling date:"<<item["Date"]<<endl;
        os<<"\tType of case:"<<item["Category"]<<endl;
        os<<"\tCase detail:"<<item["Detail"]<<endl;
        os<<"\tCase status:"<<item["Status"]<<endl;
        os<<"\n Victim detail:-\n\n";
        for(auto ele:item["Victims"])
        {
            os<<"\tVictim Id"<<ele["id"]<<endl;
            os<<"\tVictim name:"<<ele["name"]<<endl;
            os<<"\tVictim age:"<<ele["age"]<<endl;
            os<<"\tVictim address:"<<ele["address"]<<endl;
            os<<"\tVictim Statement:"<<ele["statement"]<<endl;
        }
        os<<"\n Suspect detail:-\n\n";
        for(auto ele:item["Suspects"])
        {
            os<<"\tSuspect name:"<<ele["name"]<<endl;
            os<<"\tSuspect age:"<<ele["age"]<<endl;
            os<<"\tSuspect address:"<<ele["address"]<<endl;
            os<<"\tSuspect Criminal Record:"<<ele["CriminalRecord"]<<endl;
            os<<"\tSuspect wanted status:";
            if(ele["WantedStatus"])
            {
                os<<"Yes"<<endl;
            }
            else
            {
                os<<"No"<<endl;
            }
        }
        os<<"\n Laywers detail:-\n\n";
        for(auto ele:item["Lawyers"])
        {
            os<<"\tLawyer id:"<<ele["id"]<<endl;
            os<<"\tLawyer name:"<<ele["name"]<<endl;
            os<<"\tLawyer age:"<<ele["age"]<<endl;
            os<<"\tLawyer address:"<<ele["address"]<<endl;
            os<<"\tLawyer specialization:"<<ele["specialization"]<<endl;
        }
        os<<"\n Punishments:-\n\n";
        for(auto ele:item["Punishment"])
        {
            os<<"\tPunishment type:"<<ele["Type"]<<endl;
            os<<"\tPunichment duration:"<<ele["Duration"]<<endl;
        }
        os<<"==========================================================================="<<endl<<endl;
    }
    return os;
}