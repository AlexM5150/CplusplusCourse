#ifndef CAN_H
#define CAN_H
#include <iostream>
#include <string>
using namespace std;

class Can {
private:
  int weight;
  string name;
public:
  Can();
  Can(string c, int v);
  void display();
  int getWeight();
  string getName();
  void setName(string n);
  void setWeight(int w);
};
#endif