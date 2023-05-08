/*
@filename: myLinkedList.hpp
@author: C0MPU73R
*/
#include<string>

struct Node {
public:
	std::string data;
	Node* prev = nullptr;
	Node* next = nullptr;
};
class myLinkedList {
public:
	myLinkedList() { //construction
	}
	virtual ~myLinkedList() { // destruction, proper clean-up of heap objs.
	}
	void Insert(std::string data) {
		Node* node = nullptr; // for initial creation
		if (this->head == nullptr) { // explicitly check head first
			node = new Node; // it is, so create a new node, this one will be head.
			node->data = data;
			this->head = node; // now have a head
			++this->size;
		}
		else { // else: head is indeed not null, hence check the rest of the possible LL.
			this->modifier = this->head->next; // We know that head exists, try and direct it's next to a possible next node.
			for (int i = 0; i < this->size; ++i) {
				if (this->modifier == nullptr) { // if mod is indeed null, add a new node and wire it in
					node = new Node;
					node->data = data;
					node->prev = this->modifier->prev; // direct new node's prev to the prev node in the list.  This must exist becuase we know we have at least, a head of the LL
					// and node's next is set by default to null.
				}
				modifier = modifier->next; // move on and point to possible next node.
			}
			++this->size; // inc size of node list everytime that a node is inserted.
		}
		this->modifier = nullptr; //done with the op, set mod back to null
	}
	void Delete(std::string data) {
		this->modifier = this->head;
		while (modifier != nullptr) {
			if (modifier->data == data) {
				modifier->prev = modifier->prev->prev;
				modifier->next = modifier->next->next;
				delete modifier;
				modifier = nullptr;
			}
			else {
				modifier = modifier->next;
			}
		}
	}
	void printMyLinkedList() { // print the LL
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* modifier = nullptr;
	int size = 0;
	
};