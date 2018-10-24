#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include "dNode.h"
using namespace std;

struct Node { //Node definition
	int data;
	Node* next; //using Node def. Next pointer to the node (exception)
	Node(int dataInt = 0, Node *nextInt = nullptr) {
		data = dataInt;
		next = nextInt;
	};
};

int main() {
	string filename;
	ifstream file;
	int dataFile;
	vector<int> v;

	cout << "Mariana Acosta Zermeno" << endl;
	cout << "CS2420 Section 1" << endl;
	cout << "Program 2: Linked Lists" << endl;

	cout << "Enter the file name you would like to use:" << endl;
	cin >> filename;

	if (filename != filename) {
		cout << "Try again. Incorrect file name";
		return -1;
	}

	else {
		int i = 0;
		file.open(filename);
    
		//SINGLE
		cout << "\nSingle Linked List contents:" << endl;
		Node* head = nullptr;

		while(file >> dataFile) {
      //	cout << dataFile << endl;
			head = new Node(dataFile, head);
		}
   
    DList dlist;
		//while head is not null connect the new node with the previous one
		while (head != nullptr) {
			cout << head->data << endl;
        dlist.insert(head->data);
			  head = head->next;
   
		}

		cout << "\nDouble Linked List contents:" << endl;
		//DOUBLE

	dlist.print();
		
		cout << endl;

  }
}
