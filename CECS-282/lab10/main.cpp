/*
Alex Melford
Dhruv Savla
Jose Fuentes
*/


#include <iostream>
using namespace std;

void swap (int *x, int & y)
{
  int temp = *x;
  *x = y;
   y = temp;
}

int main() {
 // cout << "Hello World!\n";
  int rand = 2;
  int *x = &rand;
  
  int y = 7;
  cout << "x: " << *x << " y:" << y << endl;
  swap(x,y);
  cout << "x: " << *x << " y:" << y << endl;
  
}