/*
** Name: Abeal Sileshi
** Assighment 1
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int addToArrayAsc(float sortedArray[], int numElements, float newValue){
    float temp;
    sortedArray[numElements] = newValue;
    for (int j = numElements; j > 0 ; j--) //Starting from the right most position of the array, until we reach the index 0, decrement
    {
        if (sortedArray[j-1] > sortedArray[j]) //compare the left position to the right, if the left is greater
        { 
            temp = sortedArray[j]; //temp equals the right position
            sortedArray[j] = sortedArray[j-1]; //the right position now equals the left
            sortedArray[j-1] = temp; //the left position now equals the right
        }
    }
    return numElements + 1; //return the count of elements inserted so far
}


int main(int argc, char* argv[]){
    float array[100]; //per the assignment instructions, our initial array size is 100

    ifstream in_file;
    string filename = argv[1]; 
    in_file.open(filename);

    if(in_file.fail()){
        cout << "Failed to open the file." << endl;
    }

    string line;
    float value;
    int size = 0; //size determines the size of the array so far
    while (in_file.good()){ 
      getline(in_file, line); //storing the contents of each line in the file in a string named "line"
      value = stof(line); 
      size = addToArrayAsc(array, size, value); //pass the current array and the size to the function
      for(int k = 0; k < size; k++){  //print the contents of the array
          if(k == 0){
              cout << array[k];
          }
          else if(k >0){
              cout << "," << array[k];
          }
              
      }
      cout << endl;
 }
      in_file.close();

    return 0;
}