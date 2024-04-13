#pragma once
#include <iostream>
using namespace std;
using namespace System;
class Chasis {
private:
	int x, y;

public:
	Chasis(int px, int py) { x = px; y = py; }
	~Chasis() {}

	void draw(ConsoleColor color) {
		Console::ForegroundColor = color;//establece elcolor
		Console::SetCursorPosition(x, y);
		cout << char(220) << char(220) << char(220) << char(220);
		Console::SetCursorPosition(x, y+1);
		cout << char(223) << char(223) << char(223) << char(223);
	}
	void clear() {
		Console::SetCursorPosition(x, y);
		cout << "    ";
		Console::SetCursorPosition(x, y+1);
		cout << "    ";
	}
	void move(int dx) { x += dx; }
};
