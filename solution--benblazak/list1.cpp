#include "List1.h"

List1::List1() : mHead(nullptr), mLength(0) {}			

int List1::length() const {								
	return mLength;
	
}

void List1::insert(int index, const int value) {		
	mLength++;
	
		Node * n = new Node;
	(*n).value = value;
	
		index %= mLength;
	if (index < 0) {
		index += mLength;
		
	}
	
		if (index == 0) {
		(*n).next = mHead;		
		mHead = n;			
		
	}
	else {
		Node * counterNode = mHead;
		for (int a = 1; a < index; a++) {
			counterNode = (*counterNode).next;
			
		}
		(*counterNode).next = n;					
		(*n).next = (*counterNode).next;				
		
	}
	
		
		
		
}

int List1::remove(int index) {							
	index %= mLength;
	if (index < 0) {
		index += mLength;
		
	}
	
		int storedValue;
	Node * counterNode;
	
		if (index == 0) {					
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

int List1::peek(int index) const {						
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

List1::~List1() {										
		
		while (mLength != 0) {
		remove(0);
		
	}
	
};
