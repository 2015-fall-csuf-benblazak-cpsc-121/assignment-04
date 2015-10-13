#ifndef LIST1_H
#define LIST1_H
#include "list.h"
class List1
{
	private:
		struct Node
		{
			Node* next;
			int value	
		};
	public:
		List::List() {}
		int List::length() {}
		void List::insert(int index, const int value) {}
		int List::remove(int index){}
		int List::index(int index){}


};

#endif  // LIST1_H