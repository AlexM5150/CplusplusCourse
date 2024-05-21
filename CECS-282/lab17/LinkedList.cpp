#include "LinkedList.h"
#include <iostream>
#include <string>
#include "Student.h"

 

using namespace std;

list::list()

{
    head=NULL;
    tail=NULL;
}

 

list::~list()
{
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

void list::add(Student value)

{
  node *newadd = new node;
  newadd->data = value;
  if(head == NULL){
    head = newadd;
    tail = newadd;
    newadd = NULL;
  }
  else{
    tail->next = newadd;
    tail = newadd;
  }
}

 

void list::addHead(Student value)
{
    node *newest=new node;
    newest->data=value;
    newest->next=head;
    head=newest;

}

Student list::deleteTail(){
  node* temp = head;
  while(temp->next->next != NULL)
      temp = temp->next;
  Student d = temp->next->data;
  temp->next = NULL;
  return d;
}

 

void list::display()

{
  node *cur=new node;
  cur=head;
  while(cur!=NULL)
  {
    cur->data.output();
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
      str = str + ::to_string(temp->data.getId()) + ::to_string(temp->data.getGpa()) + "\t";
      temp=temp->next;
    }
    return str;
}

 