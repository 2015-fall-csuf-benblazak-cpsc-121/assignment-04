#include "list.h"
#include <iostream>
using std::cout;
using std::endl;


List::List(){
	head = nullptr;
	node = nullptr;
	curr1 = nullptr;
	curr2 = nullptr;
}

void List::addNode(int idata, int option){
	node = new Node;	//create a node using dynamic memory allocation
	node->data = idata;

	//check if the node just created is a first node
	if (head == nullptr){
		head = node;
		curr1 = node;
		curr2 = node;
		node->next = nullptr;
	}
	else{
		//This means if we already have first node then we'll do something else

		//This will add the newly created node to the end of the list
		if (option == 1){
			curr1 = head;

			while (curr1->next != nullptr){

				curr1 = curr1->next;
			}//end while

			curr1->next = node;
			node->next = nullptr;


		}//end option 1

		//This will add the newly created node to the beginning of the list
		if (option == 2){

			curr1 = head;
			head = node;
			node->next = curr1;
		}//end option 2

		//This will add the newly created node to somewhere in the list
		if (option == 3){
			
			curr1 = curr2 = head;

			while (curr2->data != idata){
				curr1 = curr2;
				curr2 = curr2->next;

				//if curr2 reaches the end of the list or data couldn't be found (typo?)
				if (curr2->next == nullptr || curr2->data != idata){
					cout << "Cannot find the requested data" << endl;
				}
				
				//if data was found
				if (curr2->data == idata){
					curr1->next = node;
					node->next = curr2;
				}
			}//end while loop
		}//end option 3
		
	}//end else

}

void List::deleteNode(int idata, int option){
	//Delete head node
	if (option == 1){
		curr1 = head;
		head = head->next;

		delete curr1;
		curr1 = nullptr;
	}//end option 1

	//Delete last node
	if (option == 2){
		curr1 = curr2 = head;

		while (curr2->next != nullptr){
			curr1 = curr2;
			curr2 = curr2->next;

			if (curr2->next == nullptr){
				delete curr2;
				curr2 = nullptr;

				curr1->next = nullptr;
			}
		}//end while
	}//end option 2


	//Delete a node somewhere in the list
	if (option == 3){
		curr1 = curr2 = head;

		while (curr2->next != nullptr || curr2->data != idata){
			curr1 = curr2;
			curr2 = curr2->next;

			if (curr2->data == idata){
				curr1->next = curr2->next;
				delete curr2;
				curr2 = nullptr;
			}
			else{
				cout << "Cant find data" << endl;
			}
		}//end while
	}//end option 3
}

void List::printList(){
	curr1 = head;
	while (curr1 != nullptr){
		cout << curr1->data << "\t";
		curr1 = curr1->next;
	}

	cout << endl;
}

void List::calcLength(){

	curr1 = head;
	int len = 0;
	while (curr1->next != nullptr){
		len++;
	}
	cout << len << endl;

	
}
