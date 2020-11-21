#pragma once
#include <iostream>


struct Operand
{
    float number;
    Operand* next;
};

class StackCalculator
{
private:
  Operand* stackHead; // pointer to the top of the stack

public:
  StackCalculator();
  ~StackCalculator();
  bool isEmpty();
  void push(float num);
  void pop();
  Operand* peek();
  Operand* getStackHead() { return stackHead; }
  bool evaluate(std::string* s, int size);
};
