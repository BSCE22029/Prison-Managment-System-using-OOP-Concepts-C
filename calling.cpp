#include"standard_header.h"
#include"user_defined.h"
// #include<iostream>
#include"criminal.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;
//#include<iostream>
// global array of json type
json police_id=json::array();
// hard code
PoliceOfficer officer1("ali jutt", 35, "kot lakhpat", "itup001", "constable");
PoliceOfficer officer2("kaliya don", 40, "Model town", "itup002", "inspector");
vector<PoliceOfficer> officers;

void displayRecords(string filename) 
{
    ifstream file(filename);
    if (file.is_open()) 
    {
        json records;
        file >> records;
        cout << "Records from " << filename << ":" <<endl;
        cout << setw(4) << records << endl;
        file.close();
    } else 
    {
        cout << "Unable to open " << filename << " for reading." << endl;
    }
}

// display the basic manu to select user type
void displayLoginManu()
{     
    cout<<"\t\t\t+++++++------Criminal Justice Management System------+++++++\n";
    cout<<"\t\t\tEnter 1 to login as a admin\n";
    cout<<"\t\t\tEnter 2 to login as a judge\n";
    cout<<"\t\t\tEnter 3 to login as a user\n";
    cout<<"\t\t\tEnter 4 to login as a police officer\n";
    cout<<"\t\t\tEnter 5 to login as a visitor\n";
    cout<<"\t\t\tEnter 6 to add the visitor \n";
    cout<<"\t\t\tEnter 7 to exit\n";
    cout<<"\t\t\t\t\t\t:";
}

// for police officers to verify their type and id
char checkLogin(string password)
{
    {
        fstream login("policeLogin.json",ios::in); // reads the id's of officers from file 
        // exception handling for opening of file
        try
        {
            if(!login.is_open())
            {
                throw 0;
            }
        }
        catch(int n)
        {
            cout<<"\t\t\tSorry fatal error file not found!\n";
            return 'f';
        }
        login>>police_id; // reads the data from file
        login.close();
        char op;
        for(const auto item:police_id) // to check the rank of police officers
        {
            if(item["Badge Number"]==password) // check the badge number of a police officer to verify it
            {
                // check the rank to hand over the task acording to rank
                if(item["Rank"]=="constable")
                {
                    cout<<"Hello Mr.Constable\n";
                    return op='c';
                }
                else if(item["Rank"]=="ACP")
                {
                    cout<<"Hello Mr.ACP\n";
                    return op='a';
                }
                else if(item["Rank"]=="IG")
                {
                    cout<<"Hello Mr.IG\n";
                    return op='I';
                }
                else if(item["Rank"]=="inspector")
                {
                    cout<<"Hello Mr.Inspector\n";
                    return op='i';
                }
                else if(item["Rank"]=="DSP")
                {
                    cout<<"Hello Mr.DSP\n";
                    return op='d';
                }
                else if(item["Rank"]=="SHO")
                {
                    cout<<"Hello Mr.SHO\n";
                    return op='s';
                }
                return 'p';
            }
        }
        return 'n';
    }
}

// display the all task of police station 
void displayPoliceManu(char rank)
{
    if(rank=='c' || rank=='a' || rank=='i' || rank=='s'||rank=='I')
    {
        cout<<"\t\t\tEnter 1 to file new case\n";
        cout<<"\t\t\tEnter 2 to update case status\n";
        cout<<"\t\t\tEnter 3 to display cases\n";    
        cout<<"\t\t\tEnter 4 to search a case\n";
        cout<<"\t\t\tEnter 5 to enter the record of civilian\n";
        cout<<"\t\t\tEnter 6 to display civilian record\n";
        cout<<"\t\t\tEnter 12 to add lawyer to an exsisting case\n";
        cout<<"\t\t\tEnter 13 to add prisoner to police station\n";
    }
    if(rank=='I')
    {
        cout<<"\t\t\tEnter 7 to add new police officer\n";
        cout<<"\t\t\tEnter 9 to display the crimnal record"<<endl; 
        cout<<"\t\t\tEnter 10 to add the police officer info"<<endl;
    }
    if(rank=='a' || rank=='I')
    {
        cout<<"\t\t\tEnter 11 to assign caase to a officer"<<endl;
    }
    else if(rank=='h')
    {
        cout<<"\t\t\tEnter 8 to add new police station\n";
    }
    cout<<"\t\t\t\t\t\t:";
}

void policeTask(int op,string id)
{
    
    switch (op)
    {
        // case 1 to file task
        case 1:
        {
            // reads the server of police station 
            // in this poice id's are set with their police station
            fstream station("policeStation.json",ios::in);
            // exception handling
            try
            {
                if(!station.is_open()) // if file not found
                {
                    throw 0;
                }
            }
            catch(int n)
            {
                cout<<"\t\t\tFile not found!\n";
                return;
            }
            station>>police_id; // use global json array
            station.close();
            // location to store the location of a station
            string code,location;// to store the police station code of a specific officer
            for(auto item:police_id) // to store the single object of json array
            {
                for(auto i:item["ID"]) // to store the single obect against the key of json object
                {
                    if(i==id) // match the id of polic officers  
                    {
                        code=item["code"]; // store the station code
                        location=item["location"]; // store the location of station
                        break;
                    }
                }
            }
            cout<<"\t\t\tpolice station code:"<<code<<endl;
            cout<<"\t\t\tpolice station location:"<<location<<endl;
            // date of filing case
            string name,type,detail,suspect="",date,number,statemnet,VId;
            int age;
            cout<<"\t\t\tEnter date in the format dd/mm/yyyy:";
            cin>>date;
            cout<<"\t\t\tEnter the name of victim:";
            cin.ignore();
            getline(cin,name);
            cout<<"\t\t\tEnter the age of victim:";
            cin>>age;
            cout<<"\t\t\tEnter the statemnt of victim:";
            cin.ignore();
            getline(cin,statemnet);
            cout<<"\t\t\tEnter the type of case:";
            cin>>type;
            cout<<"\t\t\tEnter the detail of case:";
            cin.ignore();
            getline(cin,detail);
            cout<<"\t\t\tDo you have any suspects\n";
            cout<<"\t\t\tif yes press 'y' else press any key:";
            char ch;
            cin>>ch;
            // exception handling
            try
            {
                if(ch!='y' && ch!='y')
                {
                    throw 0;
                }
            }
            catch(int n)
            {
                // if there is no suspect
            }
            if (ch=='Y' || ch=='y')
            {
                cout<<"\t\t\tEnter the name of suspects:";
                cin.ignore();
                getline(cin,suspect);
            }        
            //json file;
            fstream filed;
            filed.open("cases.json",ios::in);
            // exception handling
            try
            {
                if(!filed.is_open())
                {
                    throw 0;
                }
            }
            catch(int n)
            {
                cout<<"\t\t\tFatal error unable to file case!\n";
                return;
            }
            filed>>police_id;
            filed.close();
            for(auto item:police_id)
            {
                number=item["CaseNumber"]; // read the case number from file
                // to read the id of a victim from array
                for(auto data:item["Victims"])
                {
                    VId=data["id"];
                }
            }
            string case_num,vId;// to increament the number
            case_num=incrementCode(number); // function to increament the number
            vId=incrementCode(VId);
            cout<<"\t\t\tcase number is:"<<case_num<<endl;
            cout<<"\t\t\tVictim id is"<<vId<<endl;
            Policestation p(code,location); // make a police station object
            Case c(case_num,detail,"open",type,date); // make a case object 
            Criminal cr(suspect,0,"-","-",false);
            Victim<string> v(name,age,"N/A",vId,statemnet);
            Lawyer l("N/A",0,"N/A","N/A","N/A");
            Punishment pu("N/A","N/A");
            c.addSuspects(&cr); // aggregation
            c.addVictim(&v); // aggregation
            c.addLawyer(l); // here composition take place
            c.addPunishments(&pu); // aggregation store the punichments im the respective case
            p.addCase(&c);
            fstream sta(code+".json",ios::in);
            json st;// read data from station
            sta>>st;
            sta.close();
            json jaja;
            jaja["CaseNumber"]=case_num; // add cases to a specific police station
            st["Cases"].push_back(jaja); 
            sta.open(code+".json",ios::out);
            sta<<st.dump(4); // add case to specific station
            sta.close();
            fstream f("cases.json",ios::out);
            if(!f.is_open())
            {
                cout<<"file not created\n";
            }
            json j;
            j=c.toJson();
            police_id.push_back(j);
            f<<police_id.dump(4); // add case to case files
            f.close();
            Case ca=Case::fromJson(j); // convert json to case type
            cout<<"Case number:"<<ca.getcase_number()<<endl;
            break;
        }
        case 2:
        {
            // to update the cae status
            fstream caseNumber("cases.json",ios::in);
            json num;
            caseNumber>>num; // read the case number
            caseNumber.close();
            Case nu; // to store the details of case
            string n; // for case number
            cout<<"Enter number of case to update:";
            cin>>n;
            for(auto data:num)
            {
                nu=Case::fromJson(data); // convert data from json to case type
                if(n==nu.getcase_number()) // match the case number
                {
                    string newStatus;
                    cout<<"Enter the new status of case:";
                    cin>>newStatus;
                    nu.updateStatus(newStatus);
                    break;
                }
            }
            // now update the status of specific case
            for(int i=0;i<num.size();i++)
            {
                if(num[i]["CaseNumber"]==n)
                {
                    num[i]["Status"]=nu.getstatus();
                }
            }
            caseNumber.open("cases.json",ios::out);
            caseNumber<<num.dump(4); // write the data to file
            caseNumber.close();
            break;
        }
        case 3:
        {
            // to display case details
            Case c;
            cout<<c;
            break;
        }
        case 4:
        {
            // to search a specific case
            cout<<"Enter the number of case to search:";
            string se;
            cin>>se;
            fstream search("cases.json",ios::in);
            json sea;
            search>>sea;
            search.close();
            for(auto item:sea)
            {
                if(item["CaseNumber"]==se) // here match the case number
                {
                    // display the all data of a case
                    cout<<"\tCase filling date:"<<item["Date"]<<endl;
                    cout<<"\tType of case:"<<item["Category"]<<endl;
                    cout<<"\tCase detail:"<<item["Detail"]<<endl;
                    cout<<"\tCase status:"<<item["Status"]<<endl;
                    cout<<"\n Victim detail:-\n\n";
                    for(auto ele:item["Victims"])
                    {
                        cout<<"\tVictim Id"<<ele["id"]<<endl;
                        cout<<"\tVictim name:"<<ele["name"]<<endl;
                        cout<<"\tVictim age:"<<ele["age"]<<endl;
                        cout<<"\tVictim address:"<<ele["address"]<<endl;
                        cout<<"\tVictim Statement:"<<ele["statement"]<<endl;
                    }
                    cout<<"\n Suspect detail:-\n\n";
                    for(auto ele:item["Suspects"])
                    {
                        cout<<"\tSuspect name:"<<ele["name"]<<endl;
                        cout<<"\tSuspect age:"<<ele["age"]<<endl;
                        cout<<"\tSuspect address:"<<ele["address"]<<endl;
                        cout<<"\tSuspect Criminal Record:"<<ele["CriminalRecord"]<<endl;
                        cout<<"\tSuspect wanted status:";
                        if(ele["WantedStatus"])
                        {
                            cout<<"Yes"<<endl;
                        }
                        else
                        {
                            cout<<"No"<<endl;
                        }
                    }
                    cout<<"\n Laywers detail:-\n\n";
                    for(auto ele:item["Lawyers"])
                    {
                        cout<<"\tLawyer id:"<<ele["id"]<<endl;
                        cout<<"\tLawyer name:"<<ele["name"]<<endl;
                        cout<<"\tLawyer age:"<<ele["age"]<<endl;
                        cout<<"\tLawyer address:"<<ele["address"]<<endl;
                        cout<<"\tLawyer specialization:"<<ele["specialization"]<<endl;
                    }
                    cout<<"\n Punishments:-\n\n";
                    for(auto ele:item["Punishment"])
                    {
                        cout<<"\tPunishment type:"<<ele["Type"]<<endl;
                        cout<<"\tPunichment duration:"<<ele["Duration"]<<endl;
                    }
                    cout<<"==========================================================================="<<endl<<endl;
                }
            }
            break;
        }
        case 5:
        {
            Policestation p; // to add the data of civilian 
            Civilian c;
            cin>>c; // call the istream operator
            p.addCivilian(c);
            cout<<"after the operator "<<c.getname()<<endl;
            break;
        }
        case 6:
        {
            Policestation p;
            p.display();
            break;
        }
        case 8:
        {
            cout<<"Police head";
            PoliceHead* p;
            p->getInstance();
            string code,location;
            cout<<"Enter the code of police station:";
            cin.ignore();
            getline(cin,code);
            cout<<"Enter the location of police station:";
            //cin.ignore();
            getline(cin,location);
            p->addStation(code,location);
            break;
        }
        case 9:
        {
            cout<<"judge menu  mn krwaya huva ha"<<endl;
        }
        case 10:
        {
            officers.push_back(officer1);
            officers.push_back(officer2);
            string filename = "police_officers.json";
            officer1.storePoliceOfficerDataToJson(officers, filename);
            cout << "Police officer data saved to JSON file: " << filename << endl;
            break;  
        }
        case 11:
        {
            // to assign the case to a specific person
            Case c;
            string num,id;
            cout<<"Enter the number of case:";
            cin>>num;
            cout<<"Enter the Id of officer:";
            cin>>id;
            c.assignCase(num,id);
            break;
        }
        case 12:
        {
            string num; // to take the input of a case number
            cout<<"Enter the number of case:";
            cin>>num;
            fstream read("cases.json",ios::in);
            json re;
            read>>re;
            read.close();
            int i=0;
            json j;
            for(auto data:re)
            {
                if(data["CaseNumber"]==num)
                {
                    for(auto ele:data["Lawyers"])
                    {
                        Case c;
                        Lawyer l;
                        cin>>l;
                        c.addLawyer(l);
                        j=l.toJson();
                        if(ele["name"]=="N/A") // by default every case has a lawyer with this name
                        {
                            re[i]["Lawyers"]=j;
                        }
                        else
                        {
                            // if there is any more lawyer you want to add
                            re[i]["Lawyers"].push_back(j);
                        }
                    }
                }
                i++;
            }
            read.open("cases.json",ios::out);
            read<<re.dump(4);
            read.close();
            break;
        }
        case 13:
        {
            Prisoner pr;
            cin>>pr; // here ooperator overload
            Policestation p;
            p.addPrisoner(pr); // here composition occur
            break;
        }
        default:
        {
            cout<<"Invalid Input!\n";
            break;
        }
    }  // end of switch
}

string incrementCode(const string& code) 
{
    // Find the position of the first non-numeric character
    size_t numericPartEnd = code.find_first_not_of("0123456789", 1); // Start searching from index 1
    // Extract numeric part from the string
    string numericPart = code.substr(1, numericPartEnd - 1);
    // Convert the numeric part to an integer
    int num;
    istringstream(numericPart) >> num;
    // Increment the integer
    num++;
    // Convert the incremented integer back to a string with leading zeros
    ostringstream oss;
    oss<<code.substr(0, 1)<<setw(numericPart.size())<<setfill('0') << num; // Reconstruct the code
    return oss.str();

}

void judgemenu()
 {  

    int x;
    while(true)
    {

    
    cout<<"Enter 1 to display criminal record"<<endl;
    cout<<"Enter 2 to display police record"<<endl;
    cout<<"Enter 3 for hearing"<<endl;
    cout<<"Enter 4 to display the records"<<endl;
    cout<<"Enter 5 to add the punishment "<<endl;
    cout<<"Enter 6 to see the punishments record"<<endl;
    cout<<"Enter 7 to add the forensic equipment and display equipment"<<endl;
    cout<<"Enter 0 to return"<<endl;
    cout<<"Enter your choice: ";
    cin>>x;
    switch (x)
    {
        case 1:
        {
        
            Criminal criminal("ali", 30, "123", "Theft", true);
            // Convert criminal data to JSON
            json criminalData = json::array();
            criminalData.push_back(criminal.toJson());  
            // Write criminal data to JSON file
            criminal.writeToJsonFile("criminal_data.json", criminalData);
            // Read criminal data from JSON file and display it
            criminal.readFromJsonFile("criminal_data.json");
            break;
        } 
        case 2:
        {
            officer1.readPoliceOfficerDataFromJson("police_officers.json");
            break;
        }  
        case 3:
        {
            cout<<"Assalam o alikum "<<endl;
            cout<<"chalain case ki samat shuru krty hain"<<endl;
            cout<<"Enter the case type:";
            string case_type;
            cin>>case_type;
            string lawyer_p;
            cout<<"is lawyer present ,if yes press y if not then press n"<<endl;
            cin>>lawyer_p;
            if(case_type=="murder case"||lawyer_p=="Y"||lawyer_p=="y")
            {
                cout<<"adalat ne faasla kia ha apko saza di jati ha kuky qatal kay bdlay qatal"<<endl;
            }
            else if(case_type=="murder case"||lawyer_p=="N"||lawyer_p=="n")
            {
                cout<<"adalat ne faasla kia ha apko saza di jati ha kuky qatal kay bdlay qatal"<<endl;
            }
            else if(case_type=="theft case"||lawyer_p=="N"||lawyer_p=="n")
            {
                cout<<"adalat ne faasla kia ha apko umer qaid di jti ha"<<endl;
                cout<<"aur sath sath apky waqeel ko bhi umer qaad di jti ha gair majoodgim pe"<<endl;
            }
            else if(case_type=="theft case"||lawyer_p=="y"||lawyer_p=="Y")
            {
                cout<<"adalat ne faasla kia ha apko umer qaid di jti ha"<<endl;
                cout<<"aur sath sath apky waqeel ko bhi umer qaad di jti ha gair majoodgim pe"<<endl;
            }

            break;
        }
        case 4:{
        ifstream file("records.json");
    if (!file.is_open()) {
        cout << "Failed to open records.json" << endl;
        return ; // Exit with an error code
    }

    cout << "Contents of records.json:" << endl;
    cout << file.rdbuf() << endl;

    json records;
    try {
        file >> records;
    } catch(const json::parse_error& e) {
        cout << "JSON parsing error: " << e.what() << endl;
        return ; // Exit with an error code
    } catch(const json::other_error& e) {
        cout << "JSON other error: " << e.what() << endl;
        return ; // Exit with an error code
    } catch(const exception& e) {
        cout << "Error occurred: " << e.what() << endl;
        return ; // Exit with an error code
    }

    // Parse JSON and display records
    if (records.contains("prisoner")) {
        json prisonerJson = records["prisoner"];
        Prisoner prisoner(prisonerJson["name"], prisonerJson["age"], prisonerJson["address"], prisonerJson["prisonerID"], prisonerJson["sentence"], prisonerJson["releaseDate"]);
        cout << "Prisoner Information:" << endl;
        cout << "Name: " << prisonerJson["name"] << endl;
        cout << "Age: " << prisonerJson["age"] << endl;
        cout << "Address: " << prisonerJson["address"] << endl;
        cout << "Prisoner ID: " << prisonerJson["prisonerID"] << endl;
        cout << "Sentence: " << prisonerJson["sentence"] << endl;
        cout << "Release Date: " << prisonerJson["releaseDate"] << endl;
        cout << endl;
    }
    if (records.contains("forensicLab")) {
        json labJson = records["forensicLab"];
        ForensicLaboratory lab(labJson["location"]);
        cout << "Forensic Laboratory Information:" << endl;
        cout << "Location: " << labJson["location"] << endl;
        cout << "Equipment:" << endl;
        for (auto item : labJson["equipment"]) {
            cout << "- " << item << endl;
        }
        cout << endl;
    }
            break;    
        }
        case 5:
        {
            int prisonerID;
            string type, duration;
           // cout << "Enter prisoner's name: "; 
            //cin>>name;
           // cout<<endl;
          //  cin.ignore();
          //  getline(cin, name);
            cout << "Enter prisoner's ID: ";
            
            cin >> prisonerID;
            // Ignore any remaining newline characters in the input buffer
            cin.ignore();
            // Get user input for type and duration
            cout << "Enter punishment type: ";
            getline(cin, type);
            cout << "Enter punishment duration: ";  
            getline(cin, duration);
            Punishment punishment(type, duration);        // Create a Punishment object
            cout << "Punishment type: " << punishment.getType() <<endl;   
            cout << "Punishment duration: " << punishment.getDuration() <<endl;
            json newPunishment = {
           // {"prisonerName", name},
            {"prisonerID", prisonerID},
            {"type", punishment.getType()},
            {"duration", punishment.getDuration()}
            };
            json punishmentData=json::array();        //
            punishmentData.push_back(newPunishment);
            // Write updated data back to punishments.json and also append
           fstream outputFile("punishments.json", ios::out | ios::app);        // open file for writing and append

            if (outputFile.is_open())             //check if file is open or not 
            {
                cout<<"testing"<<endl; // yeh mn check kr rha tha if staemnt chlti bhi ha ya ni
                outputFile << setw(4) << punishmentData <<endl;        // for better indentation
                outputFile.close();         
            } 
            else 
            {
                cout << "Error opening punishments.json for writing." << endl;
                return ; // Return error code
            }
            cout << "Punishment data stored successfully." <<endl;
            break;
        }
        case 6:
        {
                cout<<"yh krna ha bss"<<endl;
                
        }
        case 7:
        {
            ForensicLaboratory lab("model town");
            lab.addEquipment("gun");
            lab.addEquipment("bulllets");

            // Store data in JSON format
          lab.storeDataToJson("lab_data.json");

            // Read data from JSON file and display
             lab.readDataFromJson("lab_data.json");
             break;

        }
        case 0:
        {
            return;
        }
        // goto i;
        default:
        //   goto i;
        //    break;
        cout<<"please enter valid input"<<endl;
    }
}
}

void usermenu()
{
    int option;
    re:
    cout<<"Enter 1 to display criminal record"<<endl;
    cout<<"Enter 2 to display police record"<<endl;
    cout<<"Enter 3 to display all record"<<endl;
    cout<<"Enter 4 to add  the forensic report"<<endl;
    cout<<"Enter 5 to add the punishment "<<endl;
    cout<<"Enter 6 to see the record"<<endl;
    cout<<"Enter 0 to return"<<endl;
    cout<<"Enter your choice: ";
    cin>>option;
    switch (option)
    {
        case 1:
        {
            cout<<"aliyan ka kam ha yh"<<endl;
            break;
        }
        case 2:
        {
            cout<<"aliyan ka kam ha yh"<<endl;
            break;
        }
        case 3:
        {
            cout<<"aliyan ka kam ha yh"<<endl;
            break;
        }
        case 4:
        {
                Prisoner prisoner("Moiz", 30, "Prison Street", "206", "10 years", "2025-06-15");
                ForensicLaboratory lab("Lab1");
                lab.addEquipment("Microscope");
                lab.addEquipment("Spectrometer");
                json prisonerJson = prisoner.toJSON();
                json labJson = lab.toJSON();
                json records;
                records["prisoner"] = prisonerJson;
                records["forensicLab"] = labJson;
                // Open the file in append mode
                ofstream file("records.json", ios::out | ios::app);
                    if (file.is_open()) 
                    {
                         // Write JSON to file
                        file << setw(4) << records << endl;
                       file.close();
                       cout << "Data appended to records.json successfully." << endl;
                    } 
                    else 
                        {
                            cout << "Error opening records.json for appending." << endl;
                        }
        }
        case 6:
        {
                displayRecords("records.json");
                break;
        }
        case 0:
        {
            goto re;
        }
        default:
            break;
    }
}
void visitormenu()
{
    // hard code for the visitor addition
     Visitor visitor("Kaliya don", 30, "hpc lab mn", 1001, "mamu ka putr");
    visitor.saveVisitorRecord(visitor, "visitor_records.json");
}
void adminmenu()
{
    cout<<"Enter 1 to add the visitor details"<<endl;
    cout<<"Enter 2 to add forensic labortory details"<<endl;
    cout<<"Enter 3 to add the case"<<endl;
    cout<<"Enter 4 to see police officer details"<<endl;
    cout<<"Enter 5 to see the punishment of priioners"<<endl;
    cout<<"Enter 6 to add the punishments"<<endl;
    cout<<"Enter 7 to see the record"<<endl;
    cout<<"Enter 8 to display criminal record"<<endl;
    cout<<"Enter 9 for add new police officer"<<endl;
    cout<<"Enter 10 for add new police station"<<endl;
    cout<<"Enter 11 to see the Lawyer details "<<endl;
    cout<<"Enter 12 to see the Evidene list"<<endl;
    cout<<"Enter 13 to add any evidence"<<endl;
    cout<<"Enter 14 to add the new Lawyer "<<endl;
    cout<<"Enter 15 to see the case details"<<endl;
    cout<<"Enter 16 to see the civilians details"<<endl;
    cout<<"Enter 0 to return"<<endl;
    cout<<"Enter your choice: ";
    int x;
    cin>>x;
    switch (x){

    
    case 1:
    {
          Visitor visitor("Kaliya don", 30, "hpc lab mn", 1001, "mamu ka putr");
    visitor.saveVisitorRecord(visitor, "visitor_records.json");
    break;
    }
    case 2:
    {
         Prisoner prisoner("Moiz", 30, "Prison Street", "206", "10 years", "2034-06-15");
                ForensicLaboratory lab("Lab1");
                lab.addEquipment("Microscope");
                lab.addEquipment("Spectrometer");
                json prisonerJson = prisoner.toJSON();
                json labJson = lab.toJSON();
                 json records;
                 records["prisoner"] = prisonerJson;
                records["forensicLab"] = labJson;
                // Open the file in append mode
                ofstream file("records.json", ios::out | ios::app);
                    if (file.is_open()) 
                    {
                         // Write JSON to file
                        file << setw(4) << records << endl;
                       file.close();
                       cout << "Data appended to records.json successfully." << endl;
                    } 
                    else 
                        {
                            cout << "Error opening records.json for appending." << endl;
                        }
                     break;
    }
    case 3:
    {
        cout<<"aliyann"<<endl;
        break;
    }
    case 4:
    {
            cout<<"Pending"<<endl;
            break;
    }
    case 5:
    {
           ifstream file("punishments.json");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return ;
    }

    json data;
    file >> data;

    // Function to find and display data by matching ID
     string id_to_match;
    cout<<"enter id :";
    cin>>id_to_match;
     bool found = false;
     
        for ( auto item : data) {
            if (item["prisonerID"] == id_to_match) {
               cout << "Data for ID '" << id_to_match << "': " << endl;
            cout << item << endl;
            found = true;
            break;
            }
        cout << "ID not found." << endl;
        }


    // Example usage: Display data for ID '123'
    // display_data_by_id("123");
        break;
    }
case 6:
{
    cout<<"done in judge menu"<<endl;
    break;
}
case 7:
{
    break;
}
    }
}