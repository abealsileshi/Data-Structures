#include <iostream>
#include "hashquad.hpp"

using namespace std;


HashTable::HashTable()
{ 
    table = arr; //table pointer points to our new array
    for(int i = 0; i < tableSize; i++){ //initialize all values to negative 1 at first to signify that it is open
        table[i] = -1; 
    }
}

unsigned int HashTable :: hashFunction(int key){
    return (key % tableSize); //the hashfunction
}

bool HashTable::search(int key)
{
 
    int index = hashFunction(key); //calculating the index from the hashFunction
    if(table[index] == key){  //if at the index we find our key, return
        return true; 
    }
    else{
        int copy;
        int t = index; //t is the index calculated above
        int j = 1;
        while(table[t] != key){ 
            t = (index + j * j) % tableSize;
            if(t > tableSize){
                cout << "Greater 1  " << t << endl;
                t = t % tableSize;
                cout << "new t: " << t  << endl;
                j = 0;
            }
            copy = t;
            numOfcollision++;
            j++;
        }
        numOfcollision = numOfcollision - 1; //subtracting one because we really added one more in the while
        if (table[copy] == key) //copy is really the index we calculated in t
                { 
                    return true;
                } 
        return false;
    }
}

bool HashTable:: insert(int key){
    int index = hashFunction(key);
    if(table[index] == -1) //-1 signifies that the slot is empty
    { 
       table[index] = key; //insert the key
       return true;
    }
    else{
        // If there is a collision 
        // iterate through all possible quadratic values 
        // Computing the new hash value 
        int j = 1; //quadratic probing number
        int t = index;
        while(j < tableSize){ //while our index is not empty
            numOfcollision++; //add number of collisions
            t = (index + (j * j)); //calculating new index per quadratic probing rules
            if (table[t] == -1) //-1 signifies the space is empty
            {
                table[t] = key;  //insert key
                return true;
            } 
            if(t >= tableSize){ //if the new index is above the tableSize, then lets modulus it 
                //cout << "Greater" << endl;
                t = t % tableSize;
                j = 0;
            }
            
            j++;
            //cout << numOfcollision << endl;
        }
        cout << "Unable to insert.." << endl; 
        return false;
    }
}

void  HashTable:: printTable(){
    for(int i = 0; i < tableSize; i++){
        cout << table[i] << endl;
    }
}

int HashTable:: getNumOfCollision(){
    int temp = numOfcollision;
    numOfcollision = 0;
    return temp; //return the number of collisions
}

// bool HashTable::search(int key)
// {
//     int index = hashFunction(key);
//     if(table[index] == key){ 
//         return true; 
//     }
//     else{
//         numOfcollision++;
//         //cout << "HEREHEREHEREHERE" << endl;
//         for (int j = 1; j < tableSize; j++) //need to make the search circular, i.e. we get to index 40008, then we go to index 0 
//         { 
//             // Computing the new hash value 
//             int t = (index + j * j);
            
//             if (table[t] == key)  
//                 { 
//                     return true;
//                 } 
//                 numOfcollision++;
//         }
//         return false;
//     }
// }
