#include "Can.h"
#include <iostream>
#include <string>
using namespace std;

Can::Can()
{
  contents = "empty";
  ounces = 0;
}
Can::Can(string iContents, int iOunces)
{
  contents = iContents;
  ounces = iOunces;
}
//copy constructor
Can::Can(const Can &c){
  cout << "entering Copy Constructor\n";
  contents = c.contents;
  ounces = c.ounces;
}

Can Can::operator=(Can c){
  cout << "entering Copy Assignment operator\n";
  this->contents = c.contents;
  this->ounces = c.ounces;
  return *this;
}

Can::~Can() {
	cout << "entering Destructor\n";
  //this->display();
  //cout << endl;

}

void Can::display()
{
    cout << ounces << " ounce can of " << contents << endl;
 }

int Can::get_ounces() const{
  return ounces;
}

string Can::get_content() const{
  return contents;
}

// Can Can::operator-(Can b) const
// {

//   Can newCan;
//   int newounce = ounces - b.get_ounces();
//   if(contents == b.get_content()) {
//       newCan.contents = b.get_content();
//   }
//   else{
//     newCan.contents = "mixed";
//   }
//   newCan.ounces = newounce;
//   return newCan;
// }

// Can Can::operator+(Can b) const
// {
//   int newounce = ounces + b.get_ounces();
//   string c = "";
//   if (contents != b.get_content()){
//     c = "mixed";
//   }
//   else {
//     c = contents;
//   }
//   Can newCan(c, newounce);
//   return newCan;
// }


