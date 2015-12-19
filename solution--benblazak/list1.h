/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Brandon Min <brandon.min@csu.fullerton.edu
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * A singly linked list type for `int`s, implementing the `List` interface.
 *
 * (See documentation in "list.h")
 */

#ifndef LIST1_H
#define LIST1_H

#include "List1.h"

class List1 : public List {
	private:
		struct Node {
			Node * next;
			int value;
			
		};
		
			Node * mHead;									
		
			int mLength;									
		
			public:
				List1();										
				
					int length() const;								
				
					void insert(int index, const int value);		
				
					int remove(int index);							
				
					int peek(int index) const;						
				
					~List1();										
				
};

#endif  
