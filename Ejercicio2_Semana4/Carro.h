#pragma once
#include <iostream>
#include "Llanta.h"
#include "Chasis.h"
#include <vector>

class Carro {
private:
	int x, y, dx;
	ConsoleColor color;

	/*Es un puntero a un objeto Chasis qeu representa el chasis del carro*/
	Chasis* oChasis;
	
	/*"vLlantas" es un vector de punteros a objeto Llanta que representa
	las llantas del carro*/
	vector <Llanta*> vLlantas;

public:
	Carro(int px, int py)
	{
		x = px;
		y = py;
		dx = 1 + rand() % 10; //velocidad
		color = ConsoleColor(1 + rand() % 15);
		oChasis = new Chasis(x, y + 1);//x= 2  y=2
		vLlantas.push_back(new Llanta(x, y));//2,2
		vLlantas.push_back(new Llanta(x, y + 3));//2,5
		vLlantas.push_back(new Llanta(x + 2, y));//4,2
		vLlantas.push_back(new Llanta(x + 2, y + 3));//4,5
	}
		void draw()
		{
			for (int i = 0; i < vLlantas.size(); i++)
			{
				vLlantas[i]->draw(color);
			}
			oChasis->draw(color);
		}
		
		void clear()
		{
			for (int i = 0; i < 4; i++)
			{
				vLlantas[i]->clear();
			}
			oChasis->clear();

		}

		void move()
		{
			for (int i = 0; i < 4; i++)
			{
				vLlantas[i]->move(dx);
			}
			oChasis->move(dx);
			x += dx;
		}
		//devuelva coordenadas del auto
		int getX() { return x; }
};
