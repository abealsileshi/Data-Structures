#include <iostream>
#include <fstream>
#include <sstream>
#include "bubblesort.hpp"

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
    float sort [100]; //sort times

    BubbleSort Bubble;
    int length = 100; 
    int index = 0;
    int place = 0;
    while(length <= 10000){
        int array[length];
 
        for(int i = 0; i < length; i++){
            array[i] = testData[i];
        }
 
        auto start = chrono::steady_clock::now();
        Bubble.sort(array, length);
        auto end = steady_clock::now();
        auto time = duration_cast<nanoseconds>(end-start).count();
        cout << "Elapsed time in nanoseconds: "        <<     time    << " μs" << endl;

        float avg = time/100.0;

        sort[place] = avg;

        place++;
        length = length + 100;
    }

 

    if(argv[2]){
        ofstream out_file;
        string output = argv[2];
        out_file.open(output);

        out_file << "Sort Times for Bubble Sort" << endl;
        for(int i = 0; i <= place; i++){
            out_file << sort[i] << endl;
        }

        out_file.close();
    }

    return 0;
}

