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
	myLinkedList() {
	}
	virtual ~myLinkedList() {
	}
	void Insert(std::string data) {
		Node* node = nullptr;
		this->modifier = this->head;
		if (modifier == nullptr) {
			node = new Node;
			node->data = data;
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