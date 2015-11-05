#include "list.h"

int main(){

	List myList;

	myList.addNode(1,1);
	myList.addNode(2,1);
	myList.addNode(3,1);
	myList.addNode(4,1);
	myList.addNode(1,1);
	myList.addNode(1,1);
	myList.addNode(1,1);
	myList.addNode(1,1);

	myList.printList();
	return 0;
}
