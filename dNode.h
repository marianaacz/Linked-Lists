#ifndef DLIST_H
#define DLIST_H


class DList
{
  struct DNode { //Node definition
	int data;
	DNode* next; //using Node def. Next pointer to the node (exception)
	DNode* prev;
	DNode(int dataInt = 0, DNode *nextInt = nullptr, DNode *prevInt = nullptr) {
		data = dataInt;
		next = nextInt;
		prev = prevInt;
    };
  };
private:
  DNode *head;
  DNode *tail;

public:
  DList();
  void insert(int data);
  ~DList();
  void print();
 
  };


#endif
