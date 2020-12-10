#ifndef DLL_HPP
#define DLL_HPP

#include <string>

using namespace std;

//node struct that will be stored in the LL
struct node
{
    int key;             
    node * prev;        // pointer to the previous node
    node *next;       // pointer to the next node 
};

// class for storing and manipulating linked-list
class LL{
    private:
        node* head;  // pointer to head of linked list
        node* tail; // pointer to the tail of a linked list

    public:
        LL();
        bool isEmpty();
        void insert(int num);
        node* search(int num);
        void printNetwork();
};

#endif