#ifndef Student_H
#define Student_H
#include <string>
#include <iostream>

 

using namespace std;

class Student{

private:

    string name;
    double gpa;
    int ID;

  

public:

    Student();
    Student(string name);
    void setName(string n);
    void setGpa(double g);
    double getGpa()const;
    
    int getId()const;
    void output()const;

};

#endif 