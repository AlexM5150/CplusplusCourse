#ifndef LinkedList_h
#define LinkedList_h
#include <stdio.h>
#include <iostream>
#include<string>
#include "Student.h"

using namespace std;

struct node

{
  Student data;
  node *next;
};
class list
{
private:

    node *head, *tail;
public:
    list();
    ~list();
    int size();
    void add(Student);
    void addHead(Student value);
    Student deleteTail();
    void display();
    string to_string();
};

 

#endif /* LinkedList_h */