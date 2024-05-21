#include "LinkedList.h"

#include <iostream>

#include<string>

 

using namespace std;

list::list()

{

    head=NULL;

    tail=NULL;

}

 

list::~list(){

   

        node *n = this->head, *current = NULL; //initialization part

   

        while(n)   //start cleanup of nodes of the list

        {

            current = n;

            n=n->next;

            delete(current);

        }

       

        head = tail = NULL;

}

 

int list::size(){

    node *cur=new node;

    cur=head;

    int size = 0;

    while(cur!=NULL)

    {

        size++;

        cur=cur->next;

    }

    return size;

}

//at the end of the list

void list::add(int value)

{
    node *newest=new node;

    newest->data=value;

    newest->next=NULL;

    node* temp = head;

    if(head == NULL){
      head = newest;
      tail = newest;
    }
    else{
        addHead(value);
    }
}

 

void list::addHead(int value)

{

    node *newest=new node;

    newest->data=value;

    newest->next=head;

    head=newest;

}

 

int list::deleteTail(){
  node* temp = head;
  while(temp->next->next != NULL)
      temp = temp->next;
  int d = temp->next->data;
  temp->next = NULL;
 return d;

}

 

void list::display()

{

    node *cur=new node;

    cur=head;

    while(cur!=NULL)

    {

        cout<<cur->data<<"\t";

        cur=cur->next;

    }

}

 

string list::to_string()

{

    string str = "";

    node *temp=new node;

    temp=head;

    while(temp!=NULL)

    {

        //in java I can str + int

        str = str + ::to_string(temp->data) + "\t";

        temp=temp->next;

    }

    return str;

}

 