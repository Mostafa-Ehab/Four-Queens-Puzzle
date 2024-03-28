#include "Board.h"
#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
	Board board = Board();
	Stack stack = Stack();

	int row = 0;
	int col = -1;
	while (row < BOARD_SIZE) {
		while (row < BOARD_SIZE && col < BOARD_SIZE) {
			col++;

			if (board.addQueen(row, col)) {
				stack.add(row, col);

				cout << "Adding Q at (" << row << " ," << col << ")...\n";
				board.print();
				stack.print();
				//cin.get();
				cout << "\n--------------------------------------------------------\n";

				row++;
				col = -1;
			}

			if (col >= BOARD_SIZE) {
				stack.pop(row, col);
				board.removeQueen(row, col);

				cout << "Can't add Q in row " << row+1 << "\n";
				cout << "Removing Q at (" << row << " ," << col << ")...\n";

				board.print();
				stack.print();
				//cin.get();
				cout << "\n--------------------------------------------------------\n";
			}
		}
	}
}
