#include<iostream>
#include<string>
#include "Can.h"
using namespace std;

  Can::Can(){
     contents = " ";
     volume = 0;
}

  Can::Can(int v, string c){
    volume = v;
    contents = c;
  }

  void Can::setCan(int v, string c){
    volume = v;
    contents = c;
  }

  void Can::display()
{
  cout<< volume << " ounce can of " << contents << endl;
}

  int Can::getWeight(){
    return volume;
}

