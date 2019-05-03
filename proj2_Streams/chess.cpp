using namespace std;
#include <vector>
#include <iostream>
#include "chess.h"

int main()
{
	Chess chess;
	chess.SetCell(0, 0, 0, 'k');
	chess.SetCell(0, 0, 1, 'p');
	chess.SetCell(1, 0, 0, '?');
	chess.Print(0);
	cout << endl;
	chess.Print(1);
    return 0;
}

Chess::Chess() {
	vector<char> length(width, '.');
	for (int i = 0; i < width; i++) {
		board.push_back(length);
	}
}
	
void Chess::SetCell(int player, int row, int col, char c) {
	if (player == 0) {
		board[row][col] = c;
	} else {
		board[width - 1 - row][width - 1 - col] = c;
	}
}

void Chess::Print(int player) {
	if (player == 0) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	} else {
		for (int i = width - 1; i >= 0; i--) {
			for (int j = width - 1; j >= 0; j--) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

}