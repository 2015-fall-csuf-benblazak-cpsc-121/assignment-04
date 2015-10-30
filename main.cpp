  /* ----------------------------------------------------------------------------
   * Copyright &copy; 2015 Randy Tanizawa <rtanizawa@csu.fullerton.edu>
   * Released under the [MIT License] (http://opensource.org/licenses/MIT)
   * ------------------------------------------------------------------------- */

  /**
   * A program to create linked lists
   */

#include "List.h"
#include "List1.h"

#include <iostream>

using namespace std;

int main()
{
    List * L1 = new List1;

    L1->insert(0,1);
    L1->insert(1,2);
    L1->insert(2,3);
    L1->insert(3,4);
    L1->insert(4,5);
    L1->insert(5,6);

    L1->peek(0);
    L1->peek(2);
    L1->peek(6);

    cout << L1->length() << endl;

    L1->print();

    return 0;
}
