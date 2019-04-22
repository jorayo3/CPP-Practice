#ifndef CHESS
#define CHESS

#include <vector>

class Chess
{
public: 
	Chess();

	void SetCell(int player, int row, int col, char c);

	void Print(int player);

private:
	const int width = 19;
	vector< vector<char> > board;
};

#endif