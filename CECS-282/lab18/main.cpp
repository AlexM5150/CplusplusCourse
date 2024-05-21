/*
Alex Melford
Emanuel Ruiz
Justin Galbraith
Demo time: 5:19
*/
#include <iostream>
#include "Line.h"
#include "Point.h"

int main() {
  Point p1(0,1);
  Point p2(2,1);
  cout << "Distance of two points: "<< p1.distance(p2) << endl;

if (p1 == p2){
  cout << "p1 is equal to p2" << endl;
}
else
     cout << "p1 is not equal to p2" << endl;
  
  Line l1(0,1,2,1);
  Line l2(3,1,4,2);
  cout << "Slope of line 1: " << l1.slope() << endl;
  cout << "Length of line 1: " << l1.length() << endl;
  cout << "Slope of line 2: " << l2.slope() << endl;
  cout << "Length of line 2: " << l2.length() << endl;

  
} 