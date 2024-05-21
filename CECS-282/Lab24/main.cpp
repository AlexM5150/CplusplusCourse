//Alex Melford
// Ari Montes
// Sopheak Chim
// Demo Time - 4:51
// Week 15 - Lab 2-iterators (susan)


#include <iostream>
#include "Point.h"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main() {
  Point A(4,5);
  Point B(1,2);
  Point C(1,1); 
  Point D(1,0);
  Point E(3,3); 
  vector<Point> pointVector = {A,B,C};
  cout<< "Vector of points initial output: "<<endl;
  vector<Point>::iterator iter;
  for(iter = pointVector.begin();iter != pointVector.end();iter++) {
    (*iter).outs(); 
  }
  pointVector.push_back(D);
  cout<<"\n\n"  << "Add new point D: "<< endl;
  for(iter = pointVector.begin();iter != pointVector.end();iter++) {
    (*iter).outs(); 
  }
  pointVector.insert(pointVector.begin(),E); 
  cout<<"\n\n"  << "Add new point E: " << endl;
  for(iter = pointVector.begin();iter != pointVector.end();iter++) {
    (*iter).outs(); 
  }
  cout<<"\n\n" << "Erasing 1st element: " <<endl;
  pointVector.erase(pointVector.begin());
  for(iter = pointVector.begin();iter != pointVector.end();iter++) {
    (*iter).outs(); 
  }
} 