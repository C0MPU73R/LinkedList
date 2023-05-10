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
			node->data = data; // node is done being created. Go ahead and attach head to it (point head to it)
			this->head = node; // now have a head
			this -> tail = node; // now have a tail, as this is a single node in the single LL. The head and tail are the same at this point.
			++this->size; // Increase  the size of the LL as we now have an element in the data structure.
		}
		else if ( this->head != nullptr && pos != this->size - 1) { // this is an insertion to somewhere in the LL that is not the beginning or the end.
			// else; if head is indeed not null, aka it is pointinng to something AND this is NOT the last node in the LL, go ahead and insert
			//the new node here, keeping in mind that we will have to attach it's prev to the previous element and its next to the next element,
			//if it exists that is. We then need to look at the nodes before and after this new node to adjust their own pointers so we do not
			// 'short-circuit' this new node. Aka, we actually have a one-to-one list that is doubley linked, where there are no other strange loops 
			//to other nodes in the LL.
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