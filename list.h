/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Matthew Low <mcorelow@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */
#ifndef LIST1_H
#define LIST1_H
#include "list.h"

class List1: public List{
	private:
		struct Node {
			Node * next;
			int value;
		}
		Node *mHead;
		int mLength;
	public:
		List1();
		~List1();
		int length() const;
		void insert (int index, const int value);
		int remove (int index);
		int peek (int index) const;
};

#endif  // LIST1_H

