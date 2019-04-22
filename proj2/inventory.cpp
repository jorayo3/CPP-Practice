#include "inventory.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

Inventory::Inventory() {
}

void Inventory::Update(string item, int amount) {
	for (unsigned i = 0; i < entries.size(); i++) {
		if (entries.at(i).item == item) {
			entries.at(i).amount = amount;
			return;
		}
	}
	entries.push_back (Entry(item, amount));
}

void Inventory::ListByName() {
	sort (entries.begin(), entries.end());
	for (unsigned i = 0; i < entries.size(); i++) {
		cout << entries.at(i).item << ' ' << entries.at(i).amount << endl;
	}
}

void Inventory::ListByQuantity() {
	sort (entries.begin(), entries.end(), greater<Entry>());
	for (unsigned i = 0; i < entries.size(); i++) {
		cout << entries.at(i).item << ' ' << entries.at(i).amount << endl;
	}
}

Inventory::Entry::Entry(string item, int amount) {
	this->item = item;
	this->amount = amount;
}	