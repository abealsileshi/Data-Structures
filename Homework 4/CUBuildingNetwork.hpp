/****************************************************************/
/*                  CUBuildingNetwork Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

//#pragma once
#include <iostream>
using namespace std;
// CUBuilding: node struct that will be stored in the CUBuildingNetwork

struct CUBuilding
{
    string name;         // name of the building
    string message;      // message this building has received
    int numberMessages;       // no. of messages passed through this building
    CUBuilding *next;            // pointer to the next building
    int totalRoom;
};

// class for storing and manipulating linked-list of buildings
class CUBuildingNetwork {
    private:
        // pointer to head of linked-list of buildings
        CUBuilding* head;
    public:
        // See writeup for method descriptions
        
        /* Completed Functions */
        CUBuildingNetwork();
        bool isEmpty();
        void addBuildingInfo(CUBuilding* previous, string buildingName, int totalRoom);
        void loadDefaultSetup();
        CUBuilding* searchForBuilding(string buildingName);
        void printNetwork();

        /* For you to complete */
        void deleteCUBuilding(string buildingName);
        void deleteEntireNetwork();
        void readjustNetwork(int start, int end);
        bool detectLoop();
        CUBuilding* createLoop(std::string buildingName);        
};
