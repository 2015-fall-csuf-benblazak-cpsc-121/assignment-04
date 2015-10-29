#include "List.h"
#include "List1.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {

	/*List1 * l = new List1;
	l->insert(0, 10);
	l->insert(1, 20);
	cout << l->peek(1) << endl;
	cout << l->length() << endl;

	l->remove(0);
	cout << l->peek(0) << endl;

	std::cin.get();*/



	cout << "--------------------" << endl;		//INSERT NEXT
	cout << "Now constructing list and inserting 5 elements, values 1 to 5..." << endl;

	List1 * l = new List1;
	l->insert(0, 1);
	l->insert(1, 2);
	l->insert(2, 3);
	l->insert(3, 4);
	l->insert(4, 5);

	cout << "--------------------" << endl;		//PEEK NEXT

	cout << "Now testing the peek function." << endl;

	cout << "Length of the list is " << l->length() << " elements." << endl;

	for (int a = 0; a < l->length(); a++) {
		cout << "Index " << a << ": " << l->peek(a) << endl;
	}
	cout << "Index 5 gives index 0's value: " << l->peek(5) << endl;			//back to index 0, since list is 5 elements long

	cout << "--------------------" << endl;		//REMOVE NEXT

	cout << "Now testing the remove function." << endl;
	cout << "Removing element 3 (index 2)..." << endl;
	l->remove(2);
	cout << "Length of the list is " << l->length() << " elements." << endl;

	for (int a = 0; a < l->length(); a++) {
		cout << "Index " << a << ": " << l->peek(a) << endl;
	}

	cout << endl;

	cout << "Now removing first element (index 0)" << endl;
	l->remove(0);
	cout << "Length of the list is " << l->length() << " elements." << endl;

	for (int a = 0; a < l->length(); a++) {
		cout << "Index " << a << ": " << l->peek(a) << endl;
	}


	cout << "--------------------" << endl;		//DESTROY NEXT

	cout << "Now destroying the list..." << endl;
	delete l;
	cout << "List destroyed." << endl;

	std::cin.get();

	return 0;

}
