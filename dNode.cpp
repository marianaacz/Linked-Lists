#include <iostream>
#include "dNode.h"
using namespace std;

DList::DList()
{
  head = nullptr;
  tail = nullptr;
}

void DList::insert(int data){
  if (head == nullptr){
    head = new DNode(data, head);
    tail = head;
  }
  else if (head == tail){
    if (head->data > data){
      head = new DNode(data, head);
      head->next = tail;
      tail->prev = head;
    }
    else {
      tail = new DNode(data, tail);
      tail->prev = head;
      tail->next = nullptr;
      head->next = tail;
    }
  }
    else if (head->data > data){
      head = new DNode(data, head);
      head->next->prev = head;
      head->prev = nullptr;
    }
    else {
      if (data > tail->data){
        DNode *temp = new DNode(data, nullptr);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
      }
      else {
        DNode *temp = new DNode(data, nullptr);
        DNode *p = head;
        while (p->data <= data){
          p = p->next;
        }
        DNode *q = p ->prev; 
        q->next = temp;
        temp->prev = q;
        temp->next = p;
        p->prev = temp;
      }
    }

};

//destructor
DList::~DList() {
  while (head!=nullptr ){
    DNode *temp = head;
    head = head->next;
    delete temp;
  }
}
// Function Name:    print
// Purpose:       prints data 
// Parameters:       none
// Returns:       the data 
// Pre-conditions:    none
// Post-conditions:none
void DList::print() {
  DNode *p = head;
  while (p){
    cout << p->data << endl;
    p= p->next;
  }
}

