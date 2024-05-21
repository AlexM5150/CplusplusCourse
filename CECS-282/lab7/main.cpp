/*
Alex Melford
Richard Nguyen
Emanuel Ruiz
Demo time: 5:05
*/
#include <iostream>
#include <string>
#include "can.h"
using namespace std;

void pour(Can &can1, Can &can2){
  string c1 = can1.getName();
  string c2 = can2.getName();
  can1.setName(c1 + ',' + c2);
  //Can can1(c1 + ',' + c2, can1.getWeight()+can2.getWeight());
  can1.setWeight(can1.getWeight()+can2.getWeight());
  can2.setName("empty");
  can2.setWeight(0);
}

Can mix(Can Can1, Can Can2)
{
  string c1 = Can1.getName();
  string c2 = Can2.getName();
  string c3 = c1 + ", " + c2;
  Can mix(c3, Can1.getWeight() + Can2.getWeight());
  return mix; 
}

void stretch(Can &can1, int expand) {
  int c1 = can1.getWeight();
  can1.setWeight(c1 + expand);
}


int main()
{
     Can c1("Peaches", 15);
     Can c2("Peas", 20);
     Can c3("soup", 24);
     Can c4 = mix(c1,c3); // c4 will have a mixture of c1 and c2. c1 and c3 remain unchanged
     pour(c2,c1); // pour c1 into c2. c1 will be empty
     stretch(c3,20); // stretch c3 by 20 ounces
     cout << "C1 - ";
     c1.display(); // empty:0
     cout << "C2 - ";
     c2.display(); // Peas,Peaches:35
     cout << "C3 - ";
     c3.display(); // soup:44
     cout << "C4 - ";
     c4.display(); // Peaches, soup:39

     return 0;
}