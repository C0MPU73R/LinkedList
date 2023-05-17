/*
@filename: myLinkedList.h
@author: C0MPU73R
*/
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include<string>
class myLinkedList {
public:
	myLinkedList();
	virtual ~myLinkedList();
	void Insert(std::string data, int pos);
	void Delete(std::string data);
	void Print(); const
private:
	struct Node {
		std::string data;
		Node* prev = nullptr;
		Node* next = nullptr;
		int position; // TODO+: Possibly have a postion attrib where the user can use the API to just get the exact node they want by position.
	};

	Node* head = nullptr;
	Node* tail = nullptr; //The end of the LL. Always changing depending on insertions or deletions.
	Node* modifier = nullptr; // modifier is a temporary node that acts as an insertion or deletion operator, analyzing other nodes as well as LLs.
	Node* temp = nullptr; //The purpose of temp is to aide modifier as needed.S
	int size = 0;
};
#endif // !MYLINKEDLIST_H
