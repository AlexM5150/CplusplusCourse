#include <iostream>
#include <string>
#include "can.h"

using namespace std;

Can::Can(){
  name = "empty";
  weight = 0;
}

Can::Can(string c, int v){
  name = c;
  weight = v;
}

void Can::display()
{
  cout<< weight << " ounce can of " << name << endl;
}

int Can::getWeight(){
  return weight ; 
}

string Can :: getName(){
  return name ;
}

void Can::setName(string n){
  name = n;
}

void Can::setWeight(int w){
  weight = w;
}