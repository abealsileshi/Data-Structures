#include <iostream>
#include <fstream>
#include <sstream>
#include "hashquad.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){
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
    float colS [100]; //collision for search
    float search [100]; //search times
    float colI [100]; //collisions for insertion

    HashTable table;
    int length = 100;
    int place = 0; //insert & search array counter

    while (length <= 10000){
        auto start = chrono::steady_clock::now();
        for(int i = length - 100; i < length; i++){
            table.insert(testData[i]);
            
        }
        auto end = steady_clock::now();
        auto time = duration_cast<nanoseconds>(end-start).count();
        colI[place] = table.getNumOfCollision(); //getting the number of collisions per 100 for inserts
        //cout << "Elapsed time in nanoseconds: "        <<     time    << " μs" << endl;
        float avg = time/100.0;

        insert[place] = avg;

        //search part
       

        auto start2 = chrono::steady_clock::now();
        for(int j = length - 100; j < length + 100; j++){
            int random = rand() % length + 1;
            table.search(testData[random]);
        }
        auto end2 = steady_clock::now();
            
        auto time2 = duration_cast<nanoseconds>(end2-start2).count();
        //cout << "Elapsed time in nanoseconds: "        <<     time2    << " μs" << endl;

        //int searchCol = table.getNumOfCollision();

        //cout << "total number of searchCol" << searchCol << endl;

        colS[place] = table.getNumOfCollision(); //getting the number of collisions per 100 for inserts
        int avg2 = time2/100.0;

        search[place] = avg2;
        
        place++;
        length = length + 100;
    }


    cout << "SEARCH TIMES " << "," << "search collisions" << endl;
    for(int i = 0; i < 100; i++){
        cout << search[i] << "," << colS[i] << endl;
    }

    cout << endl;

    cout << "NOW FOR INSERT TIMES" << "," << "insert collisions" << endl;
    for(int i = 0; i < 100; i++){
        cout << insert[i] << "," << colI[i] << endl;
    }
    
    //table.printTable();
      
    if(argv[2]){
        ofstream out_file;
        string output = argv[2];
        out_file.open(output);

        out_file << "Insertion Times Hash Quad" << "," << "Num of Insertion Collisions" << "," << "Search Times Hash Quad" << "," << "Num of Search Collisions" << endl;
        for(int i = 0; i <= place; i++){
            out_file << insert[i] << "," << colI[i] << "," << search[i] << "," << colS[i] << endl;
        }
        out_file.close();
    }
    return 0;
}