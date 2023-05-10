/*
@filename: myLinkedList.hpp
@author: C0MPU73R
*/
#ifndef MYLINKEDLIST_HPP
#define MYLINKEDLIST_HPP
#include<string>
class myLinkedList {
public:
	myLinkedList();
	virtual ~myLinkedList();
	void Insert(std::string data);
	void Delete(std::string data);
	void printMyLinkedList(); const
private:
	struct Node {
		std::string data;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	Node* head = nullptr;
	Node* tail = nullptr; //The end of the LL. Always changing depending on insertions or deletions.
	Node* modifier = nullptr; // modifier is a temporary node that acts as an insertion or deletion operator, analyzing other nodes as well as LLs.
	int size = 0;
};
#endif // !MYLINKEDLIST_HPP
