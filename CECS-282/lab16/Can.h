#ifndef CAN_H
#define CAN_H
#include <string>
#include <iostream>
using namespace std;


class Can {
  public:
    Can();
    Can(string iContents, int iOunces);
    Can(const Can&);
    void display();
    Can operator=(Can c);
    //Can operator-(Can b) const;
    //Can operator+(Can b) const;
    int get_ounces() const;
    string get_content() const;
		~Can();
    
  private:
    string contents;
    int ounces;
};
#endif