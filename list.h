/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Duy Nguyen <andy21996@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include "stdafx.h"
#include "list1.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	List1 * l1 = new List1;

	// Test insert function
	for (int i = 1; i <= 10; i++)
	{
		l1->insert(i, i * 10);
	}

	l1->print();

	// Test peek function
	for (int i = 1; i <= 10; i++)
		cout << "Value of Node #" << i << " is: " << l1->peek(i) << endl; 

	// Test remove function for invalid Node
	if (l1->remove(15) == 0)
		cout << "15 is out of index range \n";

	// Test remove function for last Node
	if (l1->remove(10) > 0)
	{
		cout << "The list after the Node #10 was removed: \n";
		l1->print();
	}

	// Test remove function for middle Node
	if (l1->remove(3) > 0)
	{
		cout << "The list after the Node #3 was removed: \n";
		l1->print();
	}

	// Test remove function for first Node
	if (l1->remove(1))
	{
		cout << "The list after the Node #1 was removed: \n";
		l1->print();
	}
	return 0;
}
-------------------------------------------------------------------
List1.h
#ifndef LIST1_H
#define LIST1_H

#include "list.h"

class Node
{
public:
	Node();
	Node(const Node& nextNode, int myValue);
	~Node();
	Node * getNext() const;
	int getValue() const;
	void setNext(Node * nextNode);
	void setValue(int newValue);

private:
	Node * next;
	int value;
};

class List1 : public List
{
public:
	List1();
	~List1();
	int length() const;
	void insert(int index, const int value);
	int remove(int index);
	int peek(int index) const;
	Node * getmHead() const;
	void print() const;

private:
	Node * mHead;
	int mLength;
};

#endif
-------------------------------------------------------------------
List1.cpp
#include "stdafx.h"
#include <iostream>
#include "list1.h"
using std::cout;
using std::endl;

Node::Node()
{
	next = NULL;
	value = 0;
}
Node::Node(const Node& nextNode, int myValue)
{
	*next = nextNode;
	value = myValue;
}
Node::~Node() {}
Node *Node::getNext() const
{
	return next;
}
int Node::getValue() const
{
	return value;
}
void Node::setNext(Node * nextNode)
{
	next = nextNode;
}
void Node::setValue(int newValue)
{
	value = newValue;
}

List1::List1()
{
	mHead = NULL;
	mLength = 0;
}
List1::~List1() {}
int List1::length() const
{
	return mLength;
}
void List1::insert(int index, const int value)
{
	if (index <= 0 || index > mLength + 1)
		cout << "Error \n";
	else
	{
		Node * newNode = new Node;
		newNode->setValue(value);
		if (index == 1)
		{
			newNode->setNext(mHead);
			mHead = newNode;
			mLength++;
			newNode = NULL;
		}
		else // index >= 2
		{
			if (mLength == 0)
			{
				mHead = newNode;
				mLength++;
			}
			else if (mLength == 1)
			{
				mHead->setNext(newNode);
				mLength++;
			}
			else // mLength >= 2
			{
				Node * traverse = mHead;
				Node * current = mHead->getNext();
				for (int i = 2; i < index; i++)
				{
					traverse = traverse->getNext();
					current = current->getNext();
				}
				newNode->setNext(current);
				traverse->setNext(newNode);
				mLength++;
				newNode = NULL;
				current = NULL;
			}
		}
	}

}
int List1::remove(int index)
{
	if (index <= 0 || index > mLength)
		return 0;
	else if (index == 1)
	{
		Node * delNode = mHead;
		int delValue = delNode->getValue();
		mHead = delNode->getNext();
		mLength--;
		delete delNode;
		delNode = NULL;
		return delValue;
	}
	else // index > 1
	{
		Node * current = mHead;
		for (int i = 1; i <= index - 2; i++)
			current = current->getNext();
		Node * delNode = current->getNext();
		int delValue = delNode->getValue();
		current->setNext(delNode->getNext());
		mLength--;
		delete delNode;
		delNode = NULL;
		return delValue;
	}
}
int List1::peek(int index) const
{
	if (mLength == 0)
		return 0;
	else
	{
		Node * current = mHead;
		for (int i = 1; i < index; i++)
			current = current->getNext();
		return current->getValue();
		current = NULL;
	}
}
Node *List1::getmHead() const
{
	return mHead;
}
void List1::print() const
{
	Node * current = mHead;
	for (int i = 1; i <= mLength; i++)
	{
		cout << current->getValue() << " ";
		current = current->getNext();
	}
	cout << endl;
}
----------------------------------------------------
list.h
#ifndef LIST_H
#define LIST_H

class List 
{
public:

	virtual ~List() = default;
	/**
	* Destruct a list, first destructing all elements of the list.
	*/

	virtual int length() const = 0;
	/**
	* Returns the number of elements in the list.
	*/

	virtual void insert(int index, const int value) = 0;
	/**
	* Insert the value in the list so that its `Node` has index `index`
	* (normalized as described above).
	*/

	virtual int remove(int index) = 0;
	/**
	* Remove the `Node` at `index` (normalized as described above) from
	* the list, and return the value it contained (or `0` if the list is
	* empty).
	*/

	virtual int peek(int index) const = 0;
	/**
	* Return the value inside the `Node` at `index` (normalized as
	* described above) (or return `0` if the list is empty), without
	* modifying the list.
	*/
};

#endif  // LIST_H
