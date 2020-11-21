// SLL.hpp - interface file (header file)
#ifndef SLL_H
#define SLL_H
#include <string>
struct Node{
    string key;
    Node *next;
};

class SLL{
    private:
        Node* headOne;
        Node* headTwo;

    public:
        SLL(); // constructor declaration
        SLL(string demo);
        ~SLL(); // destructor declaration
        Node* getHeadOne(){return headOne;}
        Node* getHeadTwo(){return headTwo;}
        void setHeadOne(Node* h1){headOne = h1;}
        void setHeadTwo(Node* h2){ headTwo =h2;}

        Node* search(string sKey);
        // Precondition: sKey parameter is a string type

        // Postcondition:  if found, returns a pointer to the node containing sKey value.
        // If not found, returns a null pointer.

        void displayList();
        // Precondition: the head node is defined.

        // Post condition: display the key values of the entire list, starting with
        // first node and ending with last node.

        void insert(Node* afterMe, string newValue);
        // Precondition: afterMe is a valid pointer to a node in the linked list.
        // newValue is a valid string.

        // Postcondition: a new node is created and newValue is stored as its key.
        // The new node is added after node containing afterMe.



        void deleteNode(string sKey);
        // Precondition: head pointer is set.

        // Post condition: node pointed to by deleteNode is removed from linked list.

        int split(string searchKey);

};

#endif
