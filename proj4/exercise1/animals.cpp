#include <string>
#include "animals.h"

using namespace std;

Mouse::Mouse(string s, Position p) : Animal(s, p) {}

bool Mouse::Chase()
{
	myPos.IncrementPosition(0, 1);
	return 0;
}

Cat::Cat(string s, Position p) : Animal(s, p) {}

bool Cat::Chase()
{
	Position oldCat = myPos;
	if (myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(-1, 0);
	} else {
		myPos.IncrementPosition(0, 1.25);
	}
	return myTarget->Pos().IsBetween(oldCat, myPos);
}

Person::Person(string s, Position p) : Animal(s, p) {}

bool Person::Chase()
{
	if (!myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(0, -2);
	}
	return 0;
}

// protected:
//     string myName; // animal's name
//     Position myPos; // animal's position
//     Animal* myTarget; // ptr to animal being chased; 0 if none
