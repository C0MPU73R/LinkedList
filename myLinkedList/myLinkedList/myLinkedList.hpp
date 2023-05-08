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
		modifier = tail;
		while (modifier != nullptr) {
			delete modifier;
			modifier = modifier->prev
		}
		head = nullptr;
		tail = nullptr;
		modifier = nullptr;
	}
	void Insert(std::string data, int pos = this->size - 1) {
		Node* node = nullptr; // for initial creation
		if (this->head == nullptr) { // explicitly check head first
			node = new Node; // it is, so create a new node, this one will be head.
			node->data = data;
			this->head = node; // now have a head
			this -> tail = node; // now have a tail, as this is a single node in a single LL.
			++this->size;
		}
		else if ( this->head != nullptr && pos != this->size - 1) { // this is an insertion to somewhere in the LL that is not the beginning or the end.
			
		}
		else { // add it directly to the end of the list without doing an uneccessary traversal.
			node = new Node;
			node->data = data;
			modifier = node;
			modifier->prev = tail; //connect the node to the end of the list using tail
			tail = modifier;
			modifier = nullptr;
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
	Node* tail = nullptr; //The end of the LL. Always changing depending on insertions or deletions.
	Node* modifier = nullptr; // modifier is a temporary node that acts as an insertion or deletion operator, analyzing other nodes as well as LLs.
	int size = 0;
	
};