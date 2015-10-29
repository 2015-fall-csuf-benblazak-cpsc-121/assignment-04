#include "List1.h"

List1::List1() : mHead(nullptr), mLength(0) {}			//constructor for List1

int List1::length() const {								//implementation of length()
	return mLength;
}

void List1::insert(int index, const int value) {		//implementation of insert()
	mLength++;

	Node * n = new Node;
	(*n).value = value;

	index %= mLength;
	if (index < 0) {
		index += mLength;
	}

	if (index == 0) {
		(*n).next = mHead;		//to make the 'next' pointer null
		mHead = n;			//to make this node the beginning
	}
	else {
		Node * counterNode = mHead;
		for (int a = 1; a < index; a++) {
			counterNode = (*counterNode).next;
		}
		(*counterNode).next = n;					//element before n (tempNode) now points to n,
		(*n).next = (*counterNode).next;				//and n now points to where tempNode used to point, to fit it in between
	}



}

int List1::remove(int index) {							//implementation for remove()
	index %= mLength;
	if (index < 0) {
		index += mLength;
	}

	int storedValue;
	Node * counterNode;

	if (index == 0) {					//if the first element is to be removed
		counterNode = mHead;
		mHead = (*counterNode).next;
	}
	else {
		Node * previousNode = mHead;
		for (int a = 0; a < index - 1; a++) {
			previousNode = (*previousNode).next;
		}
		counterNode = (*previousNode).next;
		(*previousNode).next = (*counterNode).next;
	}
	
	mLength--;
	storedValue = (*counterNode).value;
	delete counterNode;
	return storedValue;
}

int List1::peek(int index) const {						//implementation for peek()
	index %= mLength;
	if (index < 0) {
		index += mLength;
	}

	if (mLength == 0) {
		return 0;
	}
	else {
		Node * counterNode = mHead;
		for (int a = 0; a < index; a++) {
			counterNode = (*counterNode).next;
		}
		return (*counterNode).value;
	}
}

List1::~List1() {										//destructor for List1
	/*while (mHead != nullptr) {*/			//this doesn't work for some reason but the next line does
	while (mLength != 0) {
		remove(0);
	}
};										
