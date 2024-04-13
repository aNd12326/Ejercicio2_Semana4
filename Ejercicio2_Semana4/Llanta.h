#pragma once
#include <iostream>
using namespace std;
using namespace System;
class Llanta {
private:
	int x, y;

public:
	Llanta(int px, int py) { x = px; y = py; }
	~Llanta(){}

	void draw(ConsoleColor color) {
		Console::ForegroundColor = color;//establece elcolor
		Console::SetCursorPosition(x, y);
		cout << char(219);
	}
	void clear() {
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void move(int dx) { x += dx; }

};