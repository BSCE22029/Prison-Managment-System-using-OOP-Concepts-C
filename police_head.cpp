#include "police_head.h"

// default constructor
PoliceHead::PoliceHead()
{}

// destructor
PoliceHead::~PoliceHead()
{
    delete instancePtr;
}

// initially initialize the pointer with null value
PoliceHead* PoliceHead::instancePtr=NULL;

// get instance of the instance
PoliceHead* PoliceHead::getInstance()
{
    // If there is no instance of class
    // then we can create an instance.
    if (instancePtr == NULL)
    {
        // We can access private members
        // within the class.
        instancePtr = new PoliceHead();
        // returning the instance pointer
        return instancePtr;
    }
    else
    {
        // if instancePtr != NULL that means
        // the class already have an instance.
        // So, we are returning that instance
        // and not creating new one.
        return instancePtr;
    }
}

// add a police station
void PoliceHead::addStation(string code,string location)
{
    fstream station("policeStation.json",ios::in);
    json st;
    station>>st; // read the file
    station.close();
    st.push_back({
        {"ID", json::array()},
        {"code", code},
        {"location", location}
    });
    station.open("policeStation.json",ios::out);
    station<<st.dump(4); // write the data in file 
    station.close();
}