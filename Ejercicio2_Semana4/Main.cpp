#include "Competencia.h"
#include <conio.h>
#include <time.h>

int main() {
	int participantes = 5;
	int WIDTH = 120;//ancho pantalla
	//configurar pantalla
	Console::SetWindowSize(WIDTH, participantes * 5);
	Console::CursorVisible = false;

	//creando un objeto
	Competencia* oCompetencia = new Competencia(WIDTH - 10, participantes);
	char tecla;
	oCompetencia->show();
	while (1)
	{
		if (kbhit()) {//esperar ingreso de tecladopor el usuario
			tecla = toupper(getch());
			if (tecla == 'G')
				break;
		}
	}

	//Inicializar la carrera
	while (oCompetencia->hayGanador() == false)
	{
		oCompetencia->correr();
		_sleep(150);
	}
	Console::SetCursorPosition(10, 20);
	cout << "Fin de la carrera" << endl;
	getch();
}