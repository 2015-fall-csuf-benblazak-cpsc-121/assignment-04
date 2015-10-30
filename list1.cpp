  /* ----------------------------------------------------------------------------
   * Copyright &copy; 2015 Randy Tanizawa <rtanizawa@csu.fullerton.edu>
   * Released under the [MIT License] (http://opensource.org/licenses/MIT)
   * ------------------------------------------------------------------------- */

  /**
   * Member function definitions of class List1
   */

#include "List.h"
#include "List1.h"

#include <iostream>
using std::cout;
using std::endl;

int List1::mLength = 0;

List1::List1()
{
    head = nullptr;
    tail = nullptr;
}

int List1::length() const
{
    return mLength;
}

void List1::print() const
{
    Node *nptr = head;
    for( int i = 0; i < mLength; i++)
    {
        cout << nptr->value << " ";
        nptr = nptr->next;
    }

}
void List1::insert(int index, const int value)
{
    Node *nn = new Node( value );
    Node *nptr;

    if( index <= 0 ) index = 0;
    else if ( index > mLength ) index = mLength + 1;
    //else index = index;

    if( head == nullptr )
    {
        head = nn;
        tail = nn;
    }
    else if( index == 0 )
    {
        nn->next = head;
        nn->prev = nullptr;

        head->prev = nn;
        head = nn;
    }
    else if( index == mLength )
    {
        nn->prev = tail;
        nn->next = nullptr;

        tail->next = nn;
        tail = nn;
    }
    else if( index < (mLength / 2))
    {
        Node *pnod;
        nptr = head;
        for( int i = 0; i < (mLength + 1); i++)
        {
            pnod = nptr;
            nptr = nptr->next;
        }
        nptr = nn;
        nn->next = pnod->next;
        nn->prev = pnod;
        pnod->next->prev = nn;
    }
    else
    {
        Node *pnod;
        nptr = tail;
        for( int i = mLength; i > index; i--)
        {
            pnod = nptr;
            nptr = nptr->prev;
        }
        nptr = nn;
        nn->prev = pnod->prev;
        pnod->prev->next = nn;
        pnod->prev = nn;
        nn->next = pnod;
    }

    mLength++;
}

int List1::remove(int index)
{
    Node *nptr;

    if( index <= 0 ) index = 0;
    else if ( index > mLength ) index = mLength + 1;
    else index = index;

    if( head == nullptr )
        std::cout << "Empty List" << std::endl;
    else if( index == 0 )
    {
        nptr = head->next;
        head->next->prev = nullptr;
    }
    else if( index == (mLength + 1) )
    {
        nptr = tail->prev;
        tail->prev->next = nullptr;
    }
    else if( index <= (mLength / 2))
    {
        Node *pnod;
        nptr = head;
        for( int i = 0; i < index; i++)
        {
            pnod = nptr;
            nptr = nptr->next;
        }

        nptr->next = pnod->next;
        nptr->next->prev = pnod;
        nptr->prev = pnod;
    }
    else
    {
        Node *pnod;
        nptr = tail;
        int ln = mLength;
        for( int i = ln; ln > index; i--)
        {
            pnod = nptr;
            nptr = nptr->prev;
        }

        pnod->prev = nptr->prev;
        nptr->prev->next = pnod;
    }

    delete nptr;
    mLength--;
}

int List1::peek(int index) const
{
    Node *nptr;

    if( index <= 0 ) index = 0;
    else if ( index > mLength) index = mLength;
    //else index = index;

    if( head == nullptr )
        std::cout << "List is empty." << std::endl;
    else if( index == 0 )
    {
        cout << head->value << endl;
        return head->value;
    }
    else if( index == mLength)
    {
        cout << tail->value << endl;
    }
    else if( index <= (mLength / 2))
    {
        nptr = head;

        for(int i = 0; i < index; i++)
            nptr = nptr->next;

        cout << nptr->value << endl;
        return nptr->value;
    }
    else
    {
        nptr = tail;
        for(int i = mLength; i > index; i--)
            nptr = nptr->prev;

        cout << nptr->value << endl;
        return nptr->value;
    }
    

}

List1::~List1()
{
    //dtor
}
