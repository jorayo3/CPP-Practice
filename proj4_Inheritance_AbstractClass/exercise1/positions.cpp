#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;

Position::Position() {
	myRadius = 1.0;
	myAngleInRadians = 0.0;
}

Position::Position(float r) {
	myRadius = r;
	myAngleInRadians = 0;
}

Position::Position(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::SetAbsolutePosition(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::IncrementPosition(float rChange, float angularDistChange) {
	if (rChange != 0 && angularDistChange != 0){
		return;
	}
	myRadius += rChange;

	if (this->IsAtStatue()) {
		myRadius = 1.0;
	}

	float angleChange = angularDistChange/myRadius;
	myAngleInRadians += angleChange;
}

void Position::Print() {
	cout << "Radius: " << this->myRadius << endl;
	cout << "Angle: " << this->myAngleInRadians << endl;
}

bool Position::Sees(Position mouse) {
	return (this->myRadius * cos(this->myAngleInRadians - mouse.myAngleInRadians) >= 1.0);
}

bool Position::IsAtStatue() {
	if (this->myRadius <= 1.0) {
		return true;
	}
	return false;
}

bool Position::IsBetween(Position pos1, Position pos2) {
	float mouseAng = myAngleInRadians;
	if (cos(mouseAng - pos1.myAngleInRadians) >= cos(pos2.myAngleInRadians - pos1.myAngleInRadians)
		&& cos(pos2.myAngleInRadians - mouseAng) >= cos(pos2.myAngleInRadians - pos1.myAngleInRadians)) {
		return true;
	}
	return false;
}

bool Position::operator==(Position coords) {
    float thresh = 0.01;
    if (this->myRadius == coords.myRadius 
        && abs(this->myAngleInRadians - coords.myAngleInRadians) < thresh) {
        return true;
    }
    return false;
}

// void tests() {
	
// 	Position test1;
// 	Position test2 (7.6);
//     Position test3 (3.20, 6.309);
//     cout << "Testing constructor, expected (1,0)\n";
//     test1.Print();
//     cout << "\nTesting overloaded constructor1, expected (rand,7.6)\n";
//     test2.Print();
//     cout << "\nTesting overloaded constructor2, expected (3.20,6.309)\n";
//     test3.Print();

//     cout << "\nTesting SetAbsolutePosition, expected (2.22, 4.67)\n";
//     test3.SetAbsolutePosition(2.22, 4.67);
//     test3.Print();

//     cout << "\nTesting IncrementPosition, expected (1,-4)\n";
//     test1.IncrementPosition(0, -4);
//     test1.Print();

//     cout << "\nexpected (3.3,-4)\n";
//     test1.IncrementPosition(2.3, 0);
//     test1.Print();
	
//     cout << "\nTesting Sees \n";
//     for (int i = 0; i < 5; i++) {
//     	float a,b,c,d;
//     	a = rand();
//     	b = rand();
//     	c = rand();
//     	Position testCat (a,b);
//     	Position testMouse (c);

//     	float expected = (a*cos(b - c) >= 1.0);
//     	cout << "expected " << expected << endl;
//     	cout << testCat.Sees(testMouse) << endl;
//     }
    
//     cout << "\nTesting IsBetween \n";
//     Position testCat (1.0,1.0);
//     cout << "expected 0\n";
//     cout << testCat.IsBetween(0.0,0.9);
//     cout << "\nexpected 1\n";
//     cout << testCat.IsBetween(0.9,1.1);
//     cout << "\nexpected 1\n";
//     cout << testCat.IsBetween(6.78,7.58);
    
//     cout << "\n\nTesting IsAtStatue\n";
//     cout << "expected 1\n";
//     cout << testCat.IsAtStatue();
//     testCat.IncrementPosition(4.3, 0);
//     cout << "\nexpected 0\n";
//     cout << testCat.IsAtStatue();
// }