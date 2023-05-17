/*
@filename: myLinkedList.cpp
@author: C0MPU73R
*/
#include "myLinkedList.h"
myLinkedList::myLinkedList() { //construction
}
myLinkedList::~myLinkedList() { // destruction, proper clean-up of heap objs.
	if (this->head != nullptr) { //Make sure that a LL is indeed created.
		this->modifier = this->head;
		if (this->head->next == nullptr) { // Head is the only node due it's next being null, go ahead and delete head, the only LL element.
			delete head;
		}
		else { // else, head's next was not null, meaning there was more to the list than just 1 node.
			this->modifier = this->head->next;
			do { // use the temp pointer to start at where modifier is, and deallocate all of the nodes in the LL. temp is a helper to modifier.
				temp = modifier;
				modifier = modifier->next;
				delete temp;
			} while (modifier != nullptr);
		}
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->modifier = nullptr;
	this->temp = nullptr;
}
void myLinkedList::Insert(std::string data, int pos = this->size - 1) {
	Node* node = nullptr; // for initial creation. The LL has not been created at all yet.
	if (this->head == nullptr) { // explicitly check head first
		node = new Node; // it is, so create a new node, this one will be head.
		node->data = data; // node is done being created. Go ahead and attach head to it (point head to it)
		this->head = node; // now have a head
		this->tail = node; // now have a tail, as this is a single node in the single LL. The head and tail are the same at this point.
		++this->size; // Increase  the size of the LL as we now have an element in the data structure.
		//This is the very first head, hence the position is set by default to zero.
	}
	else if (this->head != nullptr && &&pos < size && pos != this->size - 1) { // this is an insertion to somewhere in the LL that is not the beginning or the end.
		// else; if head is indeed not null, aka it is pointinng to something AND this is NOT the last node in the LL, go ahead and insert
		//the new node here, keeping in mind that we will have to attach it's prev to the previous element and its next to the next element,
		//if it exists that is. We then need to look at the nodes before and after this new node to adjust their own pointers so we do not
		// 'short-circuit' this new node. Aka, we actually have a one-to-one list that is doubley linked, where there are no other strange loops 
		//to other nodes in the LL.

		if (pos == 0) { // Condition if we want to insert this new node as the new head of the LL
			node = new Node; // create the node
			node->data = data; //copy over the data
			node->next = this->head; // point this 'new head's next to the old one. The 'old head' is already pointing to the start of the LL
			this->head->prev = node; //It was null by default, but now points to the "to be" new head.
			this->head = node; // point head to this new node, making it the actual head. 
			//prev is already accounted for and is null.
		}
		else {
			for (int i = 0; i < size; ++i) { // traverse the entire LL of size "size";
				if (i == pos) { // if you hit the desired position, do something here:
					int j = i; // TODO: We need some sort of 'position' attribute to accomplish this. Perhaps creating one in the Node struct,
					//where is can be accessed via indexing '[]'.

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
		modifier->position = modifier->prev->position++;
		tail = modifier;
		modifier = nullptr;
	}
}
//TODO: Needs review.
//Deletes a specific node in the LL and rewires the adjacent nodes of the deleted one together. Deallocates used mem for deleted node.
void myLinkedList::Delete(std::string data) {
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
void myLinkedList::Print() { // print the LL
	//Start at head. Print the data of each node until the next node is null.
}