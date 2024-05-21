#ifndef CAN_H
#define CAN_H

#include<string>
using namespace std;

class Can{
  private:
    int volume;
    string contents;
  public:
    Can();
    Can(int, string);
    void display();

    void setCan(int, string);

    int getWeight();


};

#endif
