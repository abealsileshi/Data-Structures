/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
// you may include more libraries as needed
#include <string>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	int input; //case number
	bool quit = false; //flag to end while loop
	JobQueue obj;

	
	while(!quit){
		menu();
		cin >> input;
		switch(input){
			case 1:{
				string s1, name; //s1 is number of jobs, name is the name of the job
				int size = 0; //
				int jobnum = 1;
				cout << "Enter the number of jobs to be created:" << endl;
				cin >> s1;
		
				while(size < stoi(s1)){
					cout << "job" << jobnum << ":" << endl;
					cin >> name;
					obj.enqueue(name); //error here
					size++;
					jobnum++;
				}
			}
				break;
			case 2:{
				string s;
				cout << "Enter the number of jobs to be dispatched:" << endl;
				cin >> s;
				int j= 0; //counter (how many times to dequeue)
				while(j < stoi(s)){
					if(obj.isEmpty()){
						cout << "No more jobs to be dispatched from queue" << endl;
						break;
					}
					cout << "Dispatched: " << obj.peek() << endl;
					obj.dequeue();
					j++;
				}
			}
				break;
			case 3:{
				int count = obj.queueSize();
				cout << "Number of jobs in the queue:" << count << endl;
				quit = true;
				break;
			}
		}

	}
}