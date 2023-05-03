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
}
class myLinkedList {
public:
	myLinkedList() {
	
	}
	virtual ~myLinkedList() {
	
	}
	void Insert(std::string data) {
		if (this->head == nullptr)
		{
			Node* node = new Node();
			node->data = data;
			// this is the first node, hence it's prev and next pointers are still null. This is a doubley-linked list.
			++this->size;
			this->head = node; //redirect head to point towards this this new node. This node is now the head. It's
			// tail is still pointing to null because we only have one node here.
		}
		else
		{
			//Head is not pointing to null hence it has to be pointing to its head node. account for this.
			Node* node = new Node();
			node->data = data;
			node->prev = this->head;
		}
	}
	void Delete(std::string data) {
		modifier = head;
		while (modifier != nullptr) {
			if (modifier->data == data) {

			}
			else
			{
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