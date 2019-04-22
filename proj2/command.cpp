#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "inventory.h"
using namespace std;

// Function Prototypes

void InterpretCommands(istream&, Inventory&);

void InterpretUpdate(istream&, Inventory&);

void InterpretList(istream&, Inventory&);

void InterpretBatch(istream&, Inventory&);

void InterpretQuit(istream&);

/**
 * Driver Function
 */
int main()
{
	Inventory inv;
	inv = Inventory();
    InterpretCommands(cin, inv);
    return 0;
}

/**
 * TODO: Write your function description here.
 */
void InterpretCommands(istream& cmds, Inventory& inv)
{
    string line, lineInWord;

    while (getline(cmds, line)) // TODO: Get a line.
    {
        istringstream lineIn(line);

        if (!(lineIn >> lineInWord)) // TODO: Get the line's first word.
        {
            cerr << "Please input a command" << endl; // TODO: Do something if there weren't any words.
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate(lineIn, inv);
        }
        else if (lineInWord == "list")
        {
            InterpretList(lineIn, inv);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch(lineIn, inv);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}

void InterpretUpdate(istream& input, Inventory& inv) {
	string line;
	string word;
	int num;
	getline(input, line);
	istringstream lineIn(line);
	if (!(lineIn >> word >> num)) {
		cerr << "Please specify and word and number to update." << endl;
	} else {
		if (lineIn >> word) {
			cerr << "Enter word and number only." << endl;
		} else {
			inv.Update(word, num);
		}
	}
}

void InterpretList(istream& input, Inventory& inv) {
	string line;
	string word;
	getline(input, line);
	istringstream lineIn(line);
	if (lineIn >> word) {
		if (lineIn >> word) {
			cerr << "Only enter one argument." << endl;
		} else if (word.compare("names") == 0) {
			inv.ListByName();
		} else if (word.compare("quantities") == 0) {
			inv.ListByQuantity();
		} else {
			cerr << "Must list 'names' or 'quantities'."  << endl;
		}
	} else {
		cerr << "Please specify what to list."  << endl;
	}
		
}
void InterpretBatch(istream& input, Inventory& inv) {
	string line;
	string filename;
	getline(input, line);
	istringstream lineIn(line);
	lineIn >> filename;
	ifstream ifile(filename);
	if (ifile.is_open()) {
		while (getline(ifile, line)) {
			istringstream fileLine(line);
			InterpretCommands(fileLine, inv);
		}
		ifile.close();
	} else {
		cerr << "Please enter a valid file name."  << endl;
	}
}

void InterpretQuit(istream&) {
	exit(EXIT_SUCCESS);
}