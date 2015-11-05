#ifndef LIST_H
#define LIST_H

//pure virtual class
class Linkedlist{
	virtual void addNode(int) = 0;
	virtual void deleteNode(int) = 0;
	virtual void printList(int) = 0;
	virtual void calcLength(int) = 0;

	
};

class List{

public:

	List();

	void addNode(int,int);
	void deleteNode(int,int);
	void printList();
	void calcLength();

	~List(){};

private:

	struct Node{
		int data;
		Node * next;
	};

	typedef struct Node * nodeptr;

	nodeptr node;		//use to create new node
	nodeptr head;		//always point to the first node of the list
	nodeptr curr1;		//point to the node before the interest node
	nodeptr curr2;		//point to the interest node
	int option = 1;
};

#endif
