#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

using namespace std;

class HashTable
{
    const static int tableSize = 40009;  // No. of buckets

   
    int *table;  // Pointer to an array containing buckets
    int arr[tableSize]; 
    int numOfcollision = 0;
public:
    HashTable();  // Constructor

    // inserts a key into hash table
    bool insert(int key);
    bool search(int key);
    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
};

#endif