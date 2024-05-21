#ifndef UPDATE_H
#define UPDATE_H

#include <string>
using namespace std;

class upDate
{
    private:
      int* datePtr;
      static int dateCount;
    public:
      upDate();
      upDate(int, int, int);
      upDate(const upDate&);
      upDate(int j);
      void operator=(upDate);
      upDate operator-(int);
      upDate operator+(int);
      int operator-(upDate);
      friend upDate operator-(int, const upDate&);
      friend upDate operator+(int, const upDate&);
      upDate operator-=(int);
      upDate operator+=(int);
      upDate operator++();
      upDate operator--();
      upDate operator++(int);
      upDate operator--(int);
      friend ostream & operator  <<(ostream&, upDate);
      void setDate(int , int, int);
      int daysBetween(upDate);
      int getMonth() const;
      int getDay() const;
      int getYear() const;
      int julian() const;
      static int GetDateCount();
      string getMonthName();
      bool operator==(const upDate&);
      bool operator<(const upDate&);
      bool operator>(const upDate&);
      ~upDate();




};
#endif