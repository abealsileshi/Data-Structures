#include<iostream>

//Student: Abeal Sileshi


using namespace std;
int main(int argc, char const *argv[])
{

  int foo[5] = {1, 2, 3, 4, 5};
  //int length = 0;
  int *p;

  p = foo;
  //TODO Print the addresses of array elements
  
  cout << "Addresses of elements:" << endl;
  for (int i = 0; i < 5; i++){ 
    cout << &foo[i] << endl;
    //length++;
  }
  cout << endl;

  cout << "Elements:" << endl;
  //TODO Print all the elements using pointers
  for (int j = 0; j < 5; j++){
    cout << "*(p + " << j << ") : ";
    cout << *(p + j) << endl;
  }
  cout << endl;
  
  for (int k = 0; k < 5; k++){
    cout << "*(foo + " << k << ") : ";
    cout << *(foo + k) << endl;
  }
  cout << endl;

  return 0;
}
