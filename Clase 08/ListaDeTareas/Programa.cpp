#include <iostream>
#include "Programa.h"
using namespace std;

void Programa::ejecutar(){
	int opcion;
	do{
		cout << "----- MI PROGRAMA ----- " << endl;
		cout << "1- TAREAS " << endl;
		cout << "-----------------------" << endl;
		cout << "0- Salir" << endl << endl;
		
		cout << "Opcion:";
		cin >> opcion;
		
		switch(opcion){
		case 1:
			_tareaMenu.Mostrar();
			break;
		case 0:
			cout << "Gracias por utilizar nuestra aplicacion... :)" << endl;
		}
	}while (opcion != 0);

}
