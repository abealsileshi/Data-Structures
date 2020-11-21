#include <iostream>
#include <string>
#include <fstream>

using namespace std;


bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    if(numEntries == arraySize){ 
    int newCapacity = arraySize*2;
    //cout<<"Resizing from "<< arraySize <<" to "<< newCapacity <<endl;
    string *newArray = new string[newCapacity];
    
   for(int i =0; i < arraySize; i++)
	{
		newArray[i] = str_arr[i];
    }
    arraySize = newCapacity;
    delete [] str_arr;
    str_arr = newArray;//make our arrayPtr point to the new bigger array
    }
     
    str_arr[numEntries] = s;
    numEntries++;
    

    return true;
}

int main(int argc, char * argv[]){
   ifstream data;
   data.open(argv[1]);

   int capacity = 10;
   string *arrayPtr;
   arrayPtr = new string[capacity];
   int numofEntries;

   string temp;

   if(data.is_open()){
       while(getline(data, temp)){
           string toBeInsert = temp;
           append(arrayPtr, toBeInsert, numofEntries, capacity);
           arrayPtr[capacity] = toBeInsert;
           cout << "NumofEntries :" << numofEntries << endl;
           numofEntries++;
       }
       data.close();
   }
   for(int i = 0; i < numofEntries; i++)
	{
        
		cout << "Word: " << arrayPtr[i] << endl;
	}
	return 0;
}