#include <iostream>
#include "JobQueue.hpp"


using namespace std;

JobQueue::JobQueue(){
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
}

bool JobQueue:: isEmpty(){
    if(counter == 0){
        return true;
    }
    else{
        return false;
    }
}

bool JobQueue:: isFull(){
    if(counter == SIZE){ 
        return true;
    }
    else{
        return false;
    }
}

void JobQueue:: enqueue(string job){
    if(isFull()){
        cout << "Queue full, cannot add new job" << endl;
    }

    else{
        queue[queueEnd] = job;
        queueEnd = (queueEnd +1)% SIZE;
        counter++;
    }
}

void JobQueue:: dequeue(){
    if(isEmpty()){
        cout << "Queue empty, cannot dequeue a job" << endl;
    }
    else{
        queueFront = (queueFront + 1)% SIZE;
        counter--;
    }
}

int JobQueue:: queueSize(){
    return counter;
} 

string JobQueue:: peek(){
    if(counter == 0){
        cout << "Queue empty, cannot peek" << endl;
        return ""; //return an empty string
    }
    else{
        return queue[queueFront];
    }
}