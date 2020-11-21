#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "SLL.hpp"

int main()
{
  SLL s1("demo");
  cout<< "before"<<endl;
  s1.displayList();
  cout<< "after"<<endl;
  s1.split("fluffy");
  s1.displayList();

cout << "===BUILT IN TEST OVER===" << endl;
cout << endl;

  SLL test;
  cout<< "before"<<endl;
  test.insert(NULL, "NYC");
  test.insert(test.search("NYC"),"LA");
  test.insert(test.search("LA"),"DEN");
  test.insert(test.search("DEN"),"ATL");
  test.insert(test.search("ATL"),"DC");
  test.displayList();
  cout << "after" << endl;
  test.split("DEN");
  test.displayList();

   
  //addBuildingInfo(searchForBuilding("AERO"), "RGNT",9);
  return 0;
}
