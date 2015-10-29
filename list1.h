/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Jaemin Jin <jaemin_95@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * TBA
 */

#ifndef LIST1_H
#define LIST1_H

class List1: public List{
    private:
        struct Node {
            Node * next;
            int value;
        };
    
    Node * mHead;
    
    int mLength;
    
    public:
        List1();
        ~List1();
    
    int length() const {return 0;}
    void insert(int index, const int value) {}
    int remove(int index) {return 0;}
    int peek(int index) const {return 0;}
    
};

#endif
