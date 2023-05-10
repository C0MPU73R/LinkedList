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
		else if ( this->head != nullptr &&  && pos < size && pos != this->size - 1) { // this is an insertion to somewhere in the LL that is not the beginning or the end.
			// else; if head is indeed not null, aka it is pointinng to something AND this is NOT the last node in the LL, go ahead and insert
			//the new node here, keeping in mind that we will have to attach it's prev to the previous element and its next to the next element,
			//if it exists that is. We then need to look at the nodes before and after this new node to adjust their own pointers so we do not
			// 'short-circuit' this new node. Aka, we actually have a one-to-one list that is doubley linked, where there are no other strange loops 
			//to other nodes in the LL.
			
			if (pos == 0) {
				node = new Node; // create the node
				node->data = data; //copy over the data
				node->next = this->head; // point this 'new head's next to the old one.
				this->head->prev = node; //It was null by default, but now points to the "to be" new head.
				this->head = node; // point head to this new node, making it the actual head. 
				//prev is already accounted for and is null.
			}
			else {
				this->modifier = this->head; //Start at head and work our way to the proper spot. Right now, use the first position as position 0.
				for (int i = 0; i < size; ++i) { // traverse the entire LL of size "size";
					if (i == pos) { // if you hit the desired position, do something here:
						node = new Node;
						node->data = data;
						//Created node, prepare for insertion.
					}
				}
			}
		}
		else { // add it directly to the end of the list without doing an uneccessary traversal.
			node = new Node;
			node->data = data;
			modifier = node;
			modifier->prev = tail; //connect the node to the end of the list using tail. Tail must always be updating in other branches to reflect this.
			tail = modifier;
			modifier = nullptr;
		}
	}
	//TODO: Needs review.
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
		//Start at head. Print the data of each node until the next node is null.
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr; //The end of the LL. Always changing depending on insertions or deletions.
	Node* modifier = nullptr; // modifier is a temporary node that acts as an insertion or deletion operator, analyzing other nodes as well as LLs.
	int size = 0;
	
};