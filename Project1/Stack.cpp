#include "Stack.h"
#include "Board.h"
#include <iostream>

void Stack::add(int x, int y) {
	Node* node = new Node;

	node->x = x;
	node->y = y;

	node->next = head;
	head = node;
}

void Stack::pop(int& x, int& y) {
	x = head->x;
	y = head->y;

	Node* temp = head;
	head = head->next;

	delete temp;
}

void Stack::print() {
	Node* ptr = head;
	while (ptr) {
		for (int i = 0; i < BOARD_SIZE; i++) {
			std::cout << "\t";
		}

		std::cout << "| (" << ptr->x << ", " << ptr->y << ") |\n";
		ptr = ptr->next;
	}
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << "\t";
	}
}
