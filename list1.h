#ifndef LIST1_H
#define LIST1_H

#include "List.h"

class List1 : public List {
private:
	struct Node {
		Node * next;
		int value;
	};

	Node * mHead;									//Pointer to the beginning node

	int mLength;									//Length of the list

public:
	List1();										//constructor

	int length() const;								//find the length of the list

	void insert(int index, const int value);		//insert a node in at an index with a particular value

	int remove(int index);							//remove a node at a particular index

	int peek(int index) const;						//return the value at that index

	~List1();										//destructor
};

#endif  // LIST1_H
