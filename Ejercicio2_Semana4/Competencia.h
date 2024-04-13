#pragma once
#include "Carro.h"

class Competencia {
private:
	int cant;//cantidad de carros
	int meta;

	/*Un vector de punteros a objeto Carro que representa los carros que participan*/
	vector <Carro*> vCarros;

public:
	Competencia(int m, int participantes)
	{
		meta = m;
		cant = participantes;
		for (int i = 0; i < cant; i++)
		{
			agregarCarro(i);
		}

	}
	//mostrar en pantalla ols carrosde la carrera
	void show()
	{
		for (int i = 0; i < vCarros.size(); i++)
		{
			vCarros[i]->draw();
		}
	}

	void agregarCarro(int positionY)
	{
		vCarros.push_back(new Carro(0, positionY * 5));
	}

	void correr()
	{
		for (int i = 0; i < vCarros.size(); i++)
		{
			vCarros[i]->clear();
			vCarros[i]->move();
			vCarros[i]->draw();
		}
		//dibujar la linea de meta (177)
		for (int i = 0; i < cant * 5; i++)
		{
			Console::ForegroundColor = ConsoleColor::White;
			Console::SetCursorPosition(meta, i);
			cout << char(177);
		}

	}

	bool hayGanador()
	{
		for (int i = 0; i < vCarros.size(); i++)
		{
			if (vCarros[i]->getX() + 5 >= meta)
				return true;
		}
		return false;
	}

};