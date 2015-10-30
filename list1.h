  /* ----------------------------------------------------------------------------
   * Copyright &copy; 2015 Randy Tanizawa <rtanizawa@csu.fullerton.edu>
   * Released under the [MIT License] (http://opensource.org/licenses/MIT)
   * ------------------------------------------------------------------------- */

  /**
   * Class to create a list of integers that is able to add, delete, and search
   * the Nodes within
   */

#ifndef LIST1_H
#define LIST1_H

#include "List.h"


class List1 : public List
{
    protected:
        static int mLength;
        struct Node
        {
            int value;
            Node *next;
            Node *prev;
            Node(int value) : value(value) {};
        };
        Node *head;
        Node *tail;
    public:
        List1();
        virtual ~List1();
        int length() const;
        void insert(int index, const int value);
        int remove(int index);
        int peek(int index) const;
        void print() const;

};


#endif 
