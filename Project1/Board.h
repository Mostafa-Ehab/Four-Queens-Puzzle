#pragma once
#define BOARD_SIZE 8

class Board
{
	bool board[BOARD_SIZE][BOARD_SIZE] = { false };
	bool isValid(int i, int j);

public:
	bool addQueen(int i, int j);
	bool removeQueen(int i, int j);
	void print();
};

