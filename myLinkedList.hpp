/*
@filename: myLinkedList.hpp
@author: C0MPU73R
*/
#include<string>

struct Node {
public:
	std::string data;
private:
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
		if (this->size == 0)
		{
			Node* node = new Node();
			node->data = data;
			// this is the first node, hence it's prev and next pointers are still null. This is a doubley-linked list.
		}
		else
		{
			//traverse down the LL datastructure, findthe end, then create and attach the new desired node.
		}
	}
	void Delete(std::string data) {

	}
	void printMyLinkedList() { // print the LL

	}
private:
	Node* mod = nullptr;
	int size = 0;
	
};