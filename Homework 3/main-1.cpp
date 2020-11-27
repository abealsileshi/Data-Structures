#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{


    CUBuildingNetwork CUBuildingNet;
    int opt = 0; string s; string s1; string s2;

    while(opt != 5) {

        displayMenu();

        getline(cin, s);
        opt = stoi(s);

        switch(opt) {
            case 1: {
                CUBuildingNet.loadDefaultSetup();
                CUBuildingNet.printNetwork();
                break;
            }

            case 2: {
                CUBuildingNet.printNetwork();
                break;
            }

            case 3: {
                cout << "Enter name of the recipient to receive the message: "<< endl;
                getline(cin, s1);

                //cout << "Enter the message to send: " << endl;
                //getline(cin, s2);

                cout << endl;

                CUBuildingNet.transmitRoomInfo(s1);

                break;
            }

            case 4: {
                cout << "Enter a new building name: " << endl;
                getline(cin, s1);
            
                string roomNum;
                cout << "Enter total room number: " << endl;
                getline(cin, roomNum);

                cout << "Enter the previous country name (or First): " << endl;
                getline(cin, s2);
                cout << endl;
                while(!(s2 == "First" || CUBuildingNet.searchForBuilding(s2))) {
                    cout << "INVALID(previous building name)...Please enter a VALID previous building name!" << endl;
                    getline(cin, s2);
                }

                if(s2 == "First") {
                    CUBuildingNet.addBuildingInfo(NULL, s1,stoi(roomNum));
                }
                else {
                    CUBuildingNet.addBuildingInfo(CUBuildingNet.searchForBuilding(s2), s1, stoi(roomNum));
                }

                CUBuildingNet.printNetwork();
                break;
            }

            case 5: {
                cout << "Quitting..." << endl;
                break;
            }

        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}




/************************************************
           Definitions for main.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Room Info " << endl;
    cout << " 4. Add Building " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
