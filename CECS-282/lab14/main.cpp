// Lydia Yang
//Alex Melford
//Andy Wong
// Karina Hernandez
// Demo Time : 5:42
#include <iostream>
#include "Can.h"
using namespace std;


ostream& operator<<(ostream& out, Can a)
{
  out << a.get_content() << ":" <<a.get_ounces();
  return out;
}


Can operator+(Can a, Can b)
{ 
  int newounce = a.get_ounces() + b.get_ounces();
  string c = "";
  if (a.get_content() != b.get_content()){
    c = "mixed";
  }
  else {
    c = a.get_content();
  }
  Can newCan(c, newounce);
  return newCan;
}

Can operator-(Can a, Can b)
{
  int newounce = a.get_ounces() - b.get_ounces();
  string c = "";
  if (a.get_content() != b.get_content()){
    c = "mixed";
  }
  else {
    c = a.get_content();
  }
  Can newCan(c, newounce);
  return newCan;
}

int main() {
  Can c1("water",12);

  Can c2("water",20);

  Can c3 = c2 + c1;  // c3 now has 32 ounces of water

  Can c4 = c2 - c1;  // c4 now has 8 ounces of water

  Can c5("milk", 32);

  Can c6("milk", 64);

  Can c7;    // this will produce a can of air with 0 ounces using default constructor

  c7 = c1 + c5;  // c7 will have 44 ounces of "mixed" because the contents of c1 and c5 were not the same

  c1 = c5 + c6; // c1 will now have 96 ounces of milk

  cout << c1;  // output -> milk:96

  cout << endl;

  cout << endl;

  cout << c1 <<'/'<< c2<<'/' << c3 <<'/'<< c4 <<'/'<< c5<<'/' << c6<<'/' << c7;  // prints all output on the same line
}