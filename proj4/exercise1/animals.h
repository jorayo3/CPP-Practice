#ifndef ANIMALS_H
#define ANIMALS_H

#include <vector>
#include <string>

#include "park.h"

using namespace std;

class Mouse: public Animal
{
public:
    Mouse(string s, Position p);
	virtual bool Chase();
};

class Cat: public Animal
{
public:
    Cat(string s, Position p);
	virtual bool Chase();
};

class Person: public Animal
{
public:
    Person(string s, Position p);
	virtual bool Chase();
};

#endif
