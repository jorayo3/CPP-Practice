#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <list>
using namespace std;

class Inventory
{
public:
    Inventory();

    void Update(string item, int amount);

    void ListByName();

    void ListByQuantity();

private:
	class Entry {
    public:
    	Entry(string item, int amount);
    	string item;
		int amount;

		bool operator < (const Entry& entr) const 
		{
			return (item < entr.item);
		}

		bool operator > (const Entry& entr) const
		{
			return (amount < entr.amount);
		}
	};

	vector<Entry> entries; 
};

#endif