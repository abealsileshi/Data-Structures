#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

#include "dll.hpp"
/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "dll.hpp" 
*/

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
	ifstream dataFile;
	string dataLine;

	int testData[10000]; // size 10000 for 10000 student IDs

	dataFile.open(argv[1]); //argv[1] is the .csv file with all of the student data

	if (!dataFile.is_open())
	{
		cerr << "Could not open " << argv[1] << " for reading!" << endl;
		return 2;
	}

    int counter = 0; 
    //first I will put the contents of the .csv into an array of 10000
	while (getline(dataFile, dataLine))
	{
		int stuID;
		string datum;
		stringstream dataStream(dataLine);
        while(counter < 10000){
            getline(dataStream, datum, ',');
		    stuID = stoi(datum);
            testData[counter] = stuID;
            counter++;
        }
	}
    float insert [100]; //insertion times
    float search [100]; //search times
  


    LL ll; //creating our linked-list
    int place = 0;
    int length = 100;

    while(length <= 10000){ //code only runs 99 times, try <=
        int index = length - 100; 
        int index2 = length - 100; 

        auto start = chrono::steady_clock::now();
        while(index < length){
            ll.insert(testData[index]);

            index++;
        }
        auto end = steady_clock::now();
        auto time = duration_cast<nanoseconds>(end-start).count();
        //cout << "Elapsed time in nanoseconds: "        <<     time    << " μs" << endl;
        
        float avg = time/100.0;
        //cout << "Average time " << avg << endl;
        insert[place] = avg;
       
       //search part
        auto start2 = chrono::steady_clock::now();
        while(index2 < length){
            int random = rand() % length + 1;
           //cout << "random num:" << random << endl;
            
            ll.search(testData[random]);
            index2++;
        }
        auto end2 = steady_clock::now();
        auto time2 = duration_cast<nanoseconds>(end2-start2).count();
        int avg2 = time2/100.0;

        search[place] = avg2;

        length += 100;

        place++;
    }

    cout << "Insert Times " << endl;
    for(int i = 0; i <= place; i++){
        cout << insert[i] << endl;
    }

    cout << "Search Times " << endl;
    for(int i = 0; i <= place; i++){
        cout << search[i] << endl;
    }
    
    if(argv[2]){
        ofstream out_file;
        string output = argv[2];
        out_file.open(output);

        out_file << "Insertion Times for DLL" << "," << "Search Times for DLL" << endl;
        for(int i = 0; i <= place; i++){
            out_file << insert[i] << "," << search[i] << endl;
        }
        out_file.close();
    }

// 	bool quit = false;
// 	while (!quit)
// 	{
// 		int option;
// 		string inputLine;

// 		cout << "======Main Menu======" << endl;
// 		cout << "1. Insert" << endl;
// 		cout << "2. Search" << endl;
//     	cout << "3. Display" << endl;
// 		cout << "4. Quit" << endl;

// 		getline(cin, inputLine);

// 		if (inputLine.length() != 1 || inputLine[0] < '0'
// 			|| inputLine[1] > '4') {
// 			cerr << "Invalid option : " << inputLine << endl;
// 			continue;
// 		}

// 		option = stoi(inputLine);

// 		switch (option)
// 		{

// 			case 1:
// 			{
// 				std::string _title;
// 				cout << "Enter a movie title:" << endl;
// 				getline(cin, _title);
// 				movies.removeMovieRecord(_title);
// 				break;
// 			}
// 			case 2:
// 			{
// 				movies.showMovieCollection();
// 				movies.inorderTraversal();
// 				break;
// 			}
// 	    case 3:
// 			{
// 				cout<< "give the titleChar of the node:"<<endl;
// 				string nodename;
// 				getline(cin, nodename);
// 	      		TreeNode* rNode = movies.searchCharNode(nodename[0]);
// 				if (rNode)
// 					movies.leftRotation(rNode);
// 				else
// 					cout << "titleChar not found" << endl;

// 	      break;
// 			}
// 			case 4:
// 			{
// 				quit = true;
// 			}
// 	}
// }

// 	cout << "Goodbye!" << endl;

	return 0;
}
