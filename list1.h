/* ----------------------------------------------------------------------------
* Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A singly linked list type for `int`s, implementing the `List` interface.
*
* (See documentation in "list.h")
*/

#ifndef LIST1_H
#define LIST1_H
// ----------------------------------------------------------------------------

#include "list.h"

class List1 : public List {
private:

	// --------------------------------------------------------------------
	// types
	// --------------------------------------------------------------------

	struct Node {
		Node * next;
		int value;
	};

	Node * mHead;
	/**
	* A pointer to the first element of the list.
	*/

	int mLength;
	/**
	* The length of the list (to make normalizing indices efficient).
	*/

public:
	List1();

	~List1();

	int length() const;

	void insert(int index, const int value);
	
	int remove(int index);
	
	int peek(int index) const;
	
};

// ----------------------------------------------------------------------------
#endif  // LIST1_H
