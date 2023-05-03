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
	myLinkedList() {}
	myLinkedList(std::string data, Node* rhs) {
		Node* node = new Node();
		node->data = rhs->data;
	}
	virtual ~myLinkedList() {}
	void Insert(Node* node) {

	}
	void Delete(Node* node) {

	}
	void printMyLinkedList() { // print the LL

	}
private:
	
};