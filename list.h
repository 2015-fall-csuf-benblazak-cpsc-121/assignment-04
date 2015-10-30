/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Veni Herrera <venedicto@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * An interface for lists containing `int`s.
 */

#ifndef LIST_H
#define LIST_H
// ----------------------------------------------------------------------------

class List {
    public:

        virtual ~List() = default;
      
        virtual int length() const = 0;
     
        virtual void insert(int index, const int value) = 0;

        virtual int remove(int index) = 0;

        virtual int peek(int index) const = 0;
        

// ----------------------------------------------------------------------------
#endif  // LIST_H

