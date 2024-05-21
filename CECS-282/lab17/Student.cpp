#include "Student.h"

Student::Student(){
  name = " ";
  gpa = 4.0;
  ID = 1234;
}

Student::Student(string name){
  setName(name);
}

void Student::setName(string n){
  name = n;
}

void Student::setGpa(double g){
  gpa = g;
}

double Student::getGpa()const{
  return gpa;
}



int Student::getId()const{
  return ID;
}

void Student::output()const{
  cout << name << ": " << gpa << endl;
}

