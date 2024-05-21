#ifndef LinkedList_h

#define LinkedList_h

 

#include <stdio.h>

#include<string>

using namespace std;

struct node

{

    int data;

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

    void add(int);

    void addHead(int value);

    int deleteTail();

    void display();

    string to_string();

  

};

 

#endif /* LinkedList_h */