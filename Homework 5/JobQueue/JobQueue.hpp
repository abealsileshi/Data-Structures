/****************************************************************/
/*                    JobQueue Class                    */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/
#pragma once

#include <string>

const int SIZE = 20;

class JobQueue
{
private:
  int queueFront; //the index in queue[] that will be dequeued next
  int queueEnd; //the index in queue[] that keeps track of the next available empty space
  int counter; // number of elements in the queue currently
  std::string queue[SIZE];

public:
  JobQueue();
  bool isEmpty();
  bool isFull();
  void enqueue(std::string job);
  void dequeue();
  std::string peek();
  int queueSize(); 
  int getQueueFront() { return queueFront; }
  int getQueueEnd() { return queueEnd; }
  std::string* getQueue() { return queue; }

};
