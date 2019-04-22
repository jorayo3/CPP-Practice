#include "lists.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Delete the node and all nodes accessible through it.
 * Precondition: this != 0.
 */
ListNode::~ListNode()
{
    // this version is buggy
    cout << "Deleting node with value " << myValue << endl;
    // for (ListNode* p = this; p; p = p->myNext)
    // {
    //     cout << "Deleting node with value " << p->myValue << endl;
    //     delete p;
    // }
    if (this->myNext) {
        delete this->myNext;
    }
}

/**
 * Print the list.
 */
void ListNode::print() const
{
    for (const ListNode* list = this; list; list = list->rest())
    {
        cout << list->first() << " ";
    }
    cout << endl;
}
