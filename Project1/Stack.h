#pragma once

struct Node {
	int x;
	int y;
	Node* next;
};

class Stack {
	Node* head = nullptr;
public:
	void add(int x, int y);
	void pop(int &x, int &y);
	void print();
};