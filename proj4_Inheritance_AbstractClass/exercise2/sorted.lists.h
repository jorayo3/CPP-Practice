#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

template <class NODETYPE>
class SortedList;
template <class NODETYPE>
class SortedListIterator;

template <class NODETYPE>
class ListNode
{
    friend class SortedList<NODETYPE>;
    friend class SortedListIterator<NODETYPE>;

public:
    ListNode(const NODETYPE&);
    NODETYPE Info();

private:
    NODETYPE myInfo;
    ListNode* myNext;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& value)
{
    myInfo = value;
    myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info()
{
    return myInfo;
}

template <class NODETYPE>
class SortedList
{
    friend class SortedListIterator<NODETYPE>;

public:
    SortedList();
    ~SortedList();
    SortedList(const SortedList<NODETYPE>&);
    void Insert(const NODETYPE&);
    bool IsEmpty();

    SortedList<NODETYPE>& operator= (const SortedList<NODETYPE>& newList) {
        cerr << "*** in operator= constructor" << endl;
        if (this == &newList) {
            cerr << "Assigned SortedList type to self. Made no changes." << endl;
            return *this;
        }

        ListNode<NODETYPE>* cleaner = this->myFirst;
        ListNode<NODETYPE>* temp;
        while(cleaner != 0) {
            temp = cleaner;
            cleaner = cleaner->myNext;
            delete temp;
        }
        // SortedList<NODETYPE> list;

        ListNode<NODETYPE>* item = newList.myFirst;

        this->myFirst = new ListNode<NODETYPE>(item->Info());
        
        ListNode<NODETYPE>* iter = this->myFirst;
        
        while (item->myNext != 0) {
            item = item->myNext;
            iter->myNext = new ListNode<NODETYPE>(item->Info());
            iter = iter->myNext;
        }
        
        // cout << list.myFirst->Info() << endl;
        // cout << list.myFirst->myNext->Info() << endl;

        return *this;
    }
ListNode<NODETYPE>* myFirst;
private:
    
};

template <class NODETYPE>
SortedList<NODETYPE>::SortedList()
{
    // constructor
    myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList()
{
    // destructor
    if (!IsEmpty())
    {
        cerr << "*** in destructor, destroying: ";
        ListNode<NODETYPE>* current = myFirst;
        ListNode<NODETYPE>* temp;
        while (current != 0)
        {
            cerr << " " << current->myInfo;
            temp = current;
            current = current->myNext;
            delete temp;
        }
        cerr << endl;
    }
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList<NODETYPE>& list)
{
    // copy constructor
    cerr << "*** in copy constructor" << endl;
    ListNode<NODETYPE>* listCurrent = list.myFirst;
    ListNode<NODETYPE>* newCurrent = 0;
    while (listCurrent != 0)
    {
        ListNode<NODETYPE>* temp = new ListNode<NODETYPE>(listCurrent->Info());
        if (newCurrent == 0)
        {
            myFirst = temp;
            newCurrent = myFirst;
        }
        else
        {
            newCurrent->myNext = temp;
            newCurrent = temp;
        }
        listCurrent = listCurrent->myNext;
    }
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE& value)
{
    // Insert
    ListNode<NODETYPE>* toInsert = new ListNode<NODETYPE>(value);
    if (IsEmpty())
    {
        myFirst = toInsert;
    }
    else if (value < myFirst->Info())
    {
        toInsert->myNext = myFirst;
        myFirst = toInsert;
    }
    else
    {
        ListNode<NODETYPE>* temp = myFirst;
        for (temp = myFirst; temp->myNext != 0 && temp->myNext->Info() < value; temp = temp->myNext)
        {
        }
        toInsert->myNext = temp->myNext;
        temp->myNext = toInsert;
    }
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty()
{
    // IsEmpty
    return myFirst == 0;
}

template <class NODETYPE>
class SortedListIterator
{
public:
    SortedListIterator(const SortedList<NODETYPE>&);
    bool MoreRemain();
    NODETYPE Next();
private:
    ListNode<NODETYPE>* current;
};

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(const SortedList<NODETYPE>& newList) {
    current = newList.myFirst;
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() {
    return (current != 0);
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() {
    if (this->MoreRemain()) {
        NODETYPE item = current->Info();
        current = current->myNext;
        return item;
    }
    return 0;
}

#endif
