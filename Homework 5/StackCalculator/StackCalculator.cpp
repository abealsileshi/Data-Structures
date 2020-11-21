#include <iostream>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  stackHead = NULL;
}

StackCalculator::~StackCalculator()
{
  Operand * current;
  while(stackHead != NULL){
    current = stackHead;
    stackHead = stackHead->next;
    delete current;
  }
}

bool StackCalculator::isEmpty()
{
  if(stackHead != NULL){
    return false;
  }
  else{
    return true;
  }
}

void StackCalculator::push(float number)
{
  Operand * temp = new Operand;
  temp->number = number;
  if(isEmpty()){
    stackHead = temp;
    stackHead->next = NULL;
  }
  else{
    temp->next = stackHead;
    stackHead = temp;
  }
}

void StackCalculator::pop()
{
  Operand * temp;
  if(!isEmpty()){
    temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
  }
  else {
    cout << "Stack empty, cannot pop an item." << endl;
  }

}

Operand* StackCalculator::peek()
{
  Operand * temp;
  if(!isEmpty()){
    temp = stackHead;
    return stackHead;
  }
  else{
    cout << "Stack empty, cannot peek." << endl;
    return nullptr;
  }
    
}

bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
   //+*75+37
   //45
   //+21
   //3
   int i = size -1; //index for the array, going backwards
   while(i >= 0){
     if(isNumber(s[i])){
       push(stof(s[i]));
       //cout << "s[i]: " << s[i] << endl;
     }
     else if(s[i] == "+" || s[i] == "*"){ //if addition or multiplication operator, pop two items to add them
       float a, b; //these variables will store the contents of what we're popping
      if(isEmpty()){ // before we peek we must makes sure there is a number
         cout << "Err: not enough operands" << endl;
         return false;
       }
      a = peek()->number;
      //cout << "a: " << peek()->number << endl;
       pop();
       if(isEmpty()){
         cout << "err: not enough operands" << endl;
         return false;
       }
       b = peek()->number;
       //cout << "b: " << peek()->number << endl;
       pop();
       if(s[i] == "+"){
         push(a+b);
       }
       else if(s[i] == "*"){
         push(a*b);
       }
      
     }
     else{
      cout << "err: invalid operation" << endl;
      return false;
    }
     i--;
   }
   
		return true;
}