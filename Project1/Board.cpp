#include "Board.h"
#include <iostream>

bool Board::isValid(int x, int y) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i != y && board[x][i]){
			return false;
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i != x && board[i][y]) {
			return false;
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i != x && (i-x == j-y || i-x == y-j) && board[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Board::addQueen(int i, int j) {
	if (!board[i][j] && isValid(i, j)) {
		board[i][j] = true;
		return true;
	}

	return false;
}

bool Board::removeQueen(int i, int j) {
	if (board[i][j]) {
		board[i][j] = false;
		return true;
	}

	return false;
}

void Board::print() {
	for (int j = 0; j < BOARD_SIZE; j++) {
		std::cout << "----";
	}
	std::cout << "\n";

	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << "|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << (board[i][j] ? " Q " : "   ") << "|";
		}
		std::cout << "\n";
		
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << "----";
		}
		std::cout << "\n";
	}
}

