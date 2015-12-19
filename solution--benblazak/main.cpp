/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Brandon Min <brandon.min@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include "List1.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
			
			cout << "--------------------" << endl;		
	cout << "Now constructing list and inserting 5 elements, values 1 to 5..." << endl;
	
		List1 * l = new List1;
	l->insert(0, 1);
	l->insert(1, 2);
	l->insert(2, 3);
	l->insert(3, 4);
	l->insert(4, 5);
	
		cout << "--------------------" << endl;		
	
		cout << "Now testing the peek function." << endl;
	
		cout << "Length of the list is " << l->length() << " elements." << endl;
	
		for (int a = 0; a < l->length(); a++) {
		cout << "Index " << a << ": " << l->peek(a) << endl;
		
	}
	cout << "Index 5 gives index 0's value: " << l->peek(5) << endl;			
	
		cout << "--------------------" << endl;		
	
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
	
		
		cout << "--------------------" << endl;		
	
		cout << "Now destroying the list..." << endl;
	delete l;
	cout << "List destroyed." << endl;
	
		std::cin.get();
	
		return 0;
	
		
}
