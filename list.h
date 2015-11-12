/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#ifndef LIST_H
#define LIST_H
// ----------------------------------------------------------------------------

class List {
    public:

        virtual ~List() = default;
        /**
         * Destruct a list, first destructing all elements of the list.
         */

        virtual int length() const = 0;
        /**
         * Returns the number of elements in the list.
         */

        virtual void insert(int index, const int value) = 0;
        /**
         * Insert the value in the list so that its `Node` has index `index`
         * (normalized as described above).
         */

        virtual int remove(int index) = 0;
        /**
         * Remove the `Node` at `index` (normalized as described above) from
         * the list, and return the value it contained (or `0` if the list is
         * empty).
         */

        virtual int peek(int index) const = 0;
        /**
         * Return the value inside the `Node` at `index` (normalized as
         * described above) (or return `0` if the list is empty), without
         * modifying the list.
         */
};

// ----------------------------------------------------------------------------
#endif  // LIST_H

