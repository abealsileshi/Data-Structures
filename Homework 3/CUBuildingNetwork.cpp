/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    CUBuilding *node = new CUBuilding;

    if(head == NULL){//if there's nothing in the LL 
        node->name=buildingName; //set building name
        node->totalRoom = numOfroom; //set num of rooms
        node->next = NULL; //point the node
        head = node; //update the head    
        cout<<"adding: "<<buildingName<<" (HEAD)"<<endl;
    }

    else if(head->next== NULL){ //case 1 we're at the beginning of the LL
        node->totalRoom = numOfroom;
        node->name = buildingName;
        head->next = node;
        node->next = NULL;
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
    }
    else if(previous == NULL){ //case 3 we want to insert in the very beginning of a LL
        node->totalRoom = numOfroom;
        node->name = buildingName;
        node->next = head;
        head = node;
        cout << "adding: " << buildingName << "(HEAD)"<<endl;
    }

    else { //inserting in between nodes
        node->totalRoom = numOfroom;
        node->name = buildingName;
        node->next = previous->next; //our node points to the same place as the previous
        previous->next= node; //the previous now points to our node
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
    }
}

/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    //Add the following six buildings along with their total room numbers, 
    //in order, with addBuildingInfo​: "FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT". 
    //Room numbers are 2, 10, 6, 5, 4, 9 respectively.
    
    addBuildingInfo(NULL, "FLMG",2);
    addBuildingInfo(searchForBuilding("FLMG"), "DLC",10);
    addBuildingInfo(searchForBuilding("DLC"), "ECOT",6);
    addBuildingInfo(searchForBuilding("ECOT"), "CASE",5);
    addBuildingInfo(searchForBuilding("CASE"), "AERO",4);
    addBuildingInfo(searchForBuilding("AERO"), "RGNT",9);
    
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    CUBuilding* current = head; //our current pointer traverses through the buildings
    while(current != nullptr){ //while we're not at the end of the node
        if(current->name == buildingName){ //if the current points to the buildingName
            return current; //return the current pointer
        }
        current = current->next; //otherwise, move on to the next element of the node
    }
    return nullptr; //if we don't find the buildingName return NULL
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    // cout<<"Empty list"<<endl;
    // cout<<"Building not found"<<endl;
    string buildingName = receiver;
    CUBuilding *temp = head;
    string s1, s2;
    s1 = "available room at ";
    s2 = " is ";
    
    if (temp == NULL){
        cout << "Empty List " << endl;
    }

    if(searchForBuilding(buildingName) == nullptr){
        cout << "Building not found" << endl;
    }

    while(temp != searchForBuilding(buildingName) && searchForBuilding(buildingName) != nullptr){
        //set the node’s ​message to ​“available room at” +<buildingName>+ “ is ” + <totalNumOfRoom> 
        temp->numberMessages+= 1; 
        cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << s1 << temp->name << s2 << temp->totalRoom;
        
        temp = temp->next;
        cout << endl;
    }
    if(temp != NULL && searchForBuilding(buildingName) != NULL){
        temp = searchForBuilding(buildingName);
        temp->numberMessages+= 1;
        cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << s1 << temp->name << s2 << temp->totalRoom;
        cout << endl;
    
    }
    
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    cout<<"== CURRENT PATH =="<<endl;
    
    CUBuilding *temp = head;

   if(temp == NULL){ 
        cout<<"nothing in path"<<endl;
        cout<<"==="<<endl;
        return;
    }
    if(temp->next == NULL){
        cout << temp->name << "(" << temp->totalRoom << ")" << " -> NULL";
    }
    cout << "Made it here 2" << endl;
    while(!(temp->next == NULL)){
        cout << temp->name << "(" << temp->totalRoom << ")";
        temp = temp->next;
        cout << "->";
    }
    
    cout << endl;
    cout<<"==="<<endl;
  }
