#include "lists.h"
#include <iostream>
using namespace std;

ListNode* fromInput(istream& is)
{
    int k;
    ListNode* head = 0;

    while (is >> k)
    {
        head = new ListNode(k, head);
    }

    return head;
}

int main()
{
    ListNode* list = fromInput(cin);
    list->print();
    if (list)
    {
        delete list;
    }
    list = 0;

    return 0;
}
