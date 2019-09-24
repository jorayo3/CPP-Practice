//Note: file contains compressed program: cat+mouse.cpp & positions.cpp & positions.h
// cat+mouse.cpp begin
#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;
void GetPositions(Position& cat, Position& mouse)
{
	float catR;
	float catAng;
	float mouseAng;
	
	cout << "Please enter cat radius.\n";
	cin >> catR;

	cout << "Please enter cat angle (degrees)." << endl;
	cin >> catAng;

	cout << "Please enter mouse angle (degrees)." << endl;
	cin >> mouseAng;

	catAng = catAng*M_PI/180;
	mouseAng = mouseAng*M_PI/180;

	cat = Position(catR,catAng);
	mouse = Position(1,mouseAng);
}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(Position& cat, Position& mouse)
{
	Position newCatPosition = cat;
	Position oldCatPosition = cat;

	int counter = 0;
	int const maxTime = 30;
	bool caught = false;

	if (mouse.IsBetween(cat,cat)) {
		cout << "\nMouse caught immediately\n";
		caught = true;
	}

	while (counter < maxTime && caught == false) {

		if (oldCatPosition.Sees(mouse)) {
			newCatPosition.IncrementPosition(-1.0, 0.0);
		} else {
			newCatPosition.IncrementPosition(0.0, 1.25);
		}

		counter++;
		
		if (mouse.IsBetween(oldCatPosition, newCatPosition) 
			&& newCatPosition.IsAtStatue()) {
			caught = true;
			cout << "\nMouse caught at time: " << counter << endl;
		} else {
			mouse.IncrementPosition(0.0, 1);
		}
		cout << endl << counter;
		cout << "\nMouse\n";
		mouse.Print();
		cout << "\nCat\n";
		newCatPosition.Print();
		oldCatPosition = newCatPosition;
	}

	if (!caught) {
		cout << "Cat wandered off.\n";
	}
}

//

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);
    return 0;
}