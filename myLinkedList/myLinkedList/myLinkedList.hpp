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
		this->modifier = this->head; // set mod to head for checks.
		if (modifier == nullptr) { // check if head was still null, to which this would mean an empty LL.
			node = new Node; // it is, so create a new node, this one will be head.
			node->data = data;
			this->head = node; // now have a head
			this->modifier = nullptr; // put mod back to null for later use.
		}
		else {
			for (int i = 0; i < this->size; ++i) {
				if (modifier != nullptr) {
					node = new Node;
					node->data = data;
					if (node->prev != nullptr) {
						node->prev = node->prev->prev;
					}
				}
				// else: you hit the nullptr, aka the end of the list
			}
			++this->size;
		}
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