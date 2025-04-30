#include"standard_header.h" // this include all standard header files
#include"user_defined.h" // this include all userdefined header files


int main() 
{
    int login;
    do 
    {
        displayLoginManu(); // display the menu to select the user type
        cin >> login;
        // Exception handling
        try 
        {
            if (login < 0 || login > 7) 
            {
                throw 0;
            }
        }
        catch (int n) 
        {
            cout << "Invalid Input!" << endl;
            continue; // Continue to the next iteration of the loop
        }
        // Handle different user types
        switch (login) 
        {
            case 1: // Admin
            {
                cout << "Enter your password/id:";
                string password;
                cin >> password;
                if (password == "admin") 
                {
                    cout << "Hello Admin" << endl;
                    adminmenu();
                }
                break;
            }
            case 2: // Judge
            {
                string password;
                cout << "Enter your password:"; // enter the password of the user
                cin >> password;
                if (password == "judge") 
                {
                    Judge& singletonJudge = Judge::getInstance(); // Get the singleton instance of Judge
                    cout << "Hello judge" << endl;
                    // display the menu for the judge
                    judgemenu();
                }
                break;
            }
            case 3: // User
            {
                string password;
                cout << "Enter your password:"; // enter the password of the user
                cin >> password;
                if (password == "anony") 
                {
                    cout << "Hello anony" << endl;
                    // display the menu for the user
                    usermenu();
                }
                break;
            }
            case 4: // Police officers
            {
                string password;
                char rank;
                cout << "Enter your ID:"; // enter the password of the user
                cin >> password;
                if (password == "head") 
                {
                    cout<<"\t\t\tHello Marryam Nawaz\n";
                    displayPoliceManu('h');
                    cin >> login; // number of task to run
                    policeTask(login, password); // pass password to track its station
                }
                else 
                {
                    rank = checkLogin(password); // take the login
                    if (rank == 'n') 
                    {
                        cout << "Invalid Id" << endl;
                    }
                    else if (rank == 'f') 
                    {
                        // if file not found
                    }
                    else if (rank == 'p') 
                    {
                        cout << "Your rank is unknown" << endl;
                    }
                    else 
                    {
                        char choice;
                        do
                        {
                            // make the manu drven
                            displayPoliceManu(rank);
                            cin >> login; // number of task to run
                            policeTask(login, password); // pass password to track its station
                            cout<<"Do you want to enter the input again if yes press y:";
                            cin>>choice;
                        } while (choice=='Y' || choice=='y');
                    }
                }
                break;
            }
            case 5: // Visitor
            {
                cout << "Hello visitor" << endl;
                string visitorName, visitorAddress, visitorRelationship;
                int visitorAge, visitorID;
                cout << "Enter visitor's name: ";
                cin.ignore(); // Ignore newline characters from previous input
                getline(cin, visitorName);
                cout << "Enter visitor's age: ";
                cin >> visitorAge;
                cin.ignore(); // Ignore any remaining newline characters in the input buffer
                cout << "Enter visitor's address: ";
                cin.ignore(); // Ignore newline characters from previous input
                getline(cin, visitorAddress);
                cout << "Enter visitor's ID: ";
                cin >> visitorID;
                cin.ignore();
                cout << "Enter visitor's relationship with the prisoner: ";
                cin.ignore(); // Ignore newline characters from previous input
                getline(cin, visitorRelationship);
                Visitor visitor(visitorName, visitorAge, visitorAddress, visitorID, visitorRelationship);
                //punishment.setVisitor(visitor);
                json visitorData;
                visitorData["name"] = visitor.getname();
                visitorData["age"] = visitor.getage();
                visitorData["address"] = visitor.getaddress();
                visitorData["visitorID"] = visitor.getvisitorID();
                visitorData["relationship"] = visitor.getrelationship();
                json allVisitorsData;
                ifstream inputFile("visitors.json");
                if (inputFile.is_open()) 
                {
                    inputFile >> allVisitorsData;
                    inputFile.close();
                }
                allVisitorsData.push_back(visitorData);
                ofstream outputFile("visitors.json");
                if (outputFile.is_open()) 
                {
                    outputFile << setw(4) << allVisitorsData << endl;
                    outputFile.close();
                    cout << "Visitor data stored successfully." << endl;
                }
                else 
                {
                    cout << "Error opening visitors.json for writing." << endl;
                }
                break;
            }
            case 6: // Visitor menu
            {
                visitormenu();
                break;
            }
            case 7: // to exit the program
            {
                return 0;
                break;
            }
            default:
            {
                cout << login;
                cout << "Invalid Input!" << endl;
                break;
            }
        }
    } while (true); // Repeat until the user decides to exit
    return 0;
}
