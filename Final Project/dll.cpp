#include "dll.hpp"
#include <iostream>

using namespace std;

LL::LL() {
    /* finished. do not touch. */
    head = NULL;
}

bool LL::isEmpty()
{
    return (head == NULL);
}

void LL::insert(int num){
    node *nn = new node;
    if(head == NULL){//if there's nothing in the LL 
        nn->key=num; //set node vale
        nn->next = NULL; //point the node
        nn->prev = NULL;
        head = nn; //update the head    
        tail = nn;
        //cout << "adding: " << num << " (HEAD)" << endl;
    }

    else {
        nn->key = num; //instantiate the node
        nn->prev = tail; //make the node's previous the old tail
        tail->next = nn; //make old tail's next equal the new node
        tail = nn; //update where the tail points 
        nn->next = NULL; //since this node is last,
        //cout << "adding: " << num << " (prev: " << nn->prev->key << ")" << endl;
    }
}

node* LL::search(int num)
{
    node* current = head; //our current pointer traverses through the nodes
    while(current != nullptr){ //while we're not at the end of the node
        if(current->key == num){ //if the current points to the num
            return current; //return the current pointer
        }
        current = current->next; //otherwise, move on to the next element of the node
    }
    return nullptr; //if we don't find the node return NULL
}

void LL::printNetwork() {
    cout<<"== CURRENT PATH =="<<endl;
    
    node *temp = head;

   if(temp == NULL){ 
        cout<<"nothing in path"<<endl;
        cout<<"==="<<endl;
        return;
    }
    
    while(!(temp->next == NULL)){
        cout << temp->key;
        temp = temp->next;
        cout << "->";
    }
     if(temp->next == NULL){
        cout << temp->key << " -> NULL";
    }
    
    cout << endl;
    cout<<"==="<<endl;
  }
