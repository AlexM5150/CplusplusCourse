#ifndef MYDATE_H
#define MYDATE_H

#include <string>
using namespace std;

class myDate
{
    private:
      int M;
      int D;
      int Y;
    public:
      myDate();
      myDate(int, int, int);
      void display();
      void increaseDate(int);
      void decreaseDate(int);
      int daysBetween(myDate);
      int getMonth();
      int getDay();
      int getYear();
      int dayOfYear();
      string dayName();
      string printDate();



};
#endif