/****************************************************************/
/*                  CUBuildingNetwork Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

//#pragma once
#include <iostream>
using namespace std;

// CUBuilding: node struct that will be stored in the BuildingNetwork
struct CUBuilding
{
    string name;         // name of the building
    string message;      // message this building has received
    int numberMessages;  // no. of messages passed through this building
    CUBuilding *next;       // pointer to the next building
    int totalRoom;
};

// class for storing and manipulating linked-list of countries
class CUBuildingNetwork {
    private:
        CUBuilding* head;  // pointer to head of linked list of cities

    public:
        // You will need to define the below unfinished methods in CUBuildingNetwork.cpp
        CUBuildingNetwork();
        bool isEmpty();
        void addBuildingInfo(CUBuilding* previous, string buildingName, int totalRoom);
        void loadDefaultSetup();
        CUBuilding* searchForBuilding(string buildingName);
        void transmitRoomInfo(string receiver);
        void printNetwork();
};
