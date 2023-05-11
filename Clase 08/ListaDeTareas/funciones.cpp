#include "funciones.h"
#include <climits>
#include <iostream>
using namespace std;

int getInteger(int minimo = INT_MIN, int maximo = INT_MAX){
	int input;
	
	while(true){
		cin >> input;
		if (cin.fail() || input < minimo || input > maximo){
			cin.clear();
			cin.ignore();
		}
		else{
			cin.ignore();
			return input;
		}
	}
}



int diferenciaDias(Fecha fechaInicial, Fecha fechaFinal)
{
    int contador = 0;

    bool primerFechaMayor = fechaInicial.toString("YYYY/MM/DD") > fechaFinal.toString("YYYY/MM/DD");

    if (primerFechaMayor)
    {
        Fecha aux = fechaInicial;
        fechaInicial = fechaFinal;
        fechaFinal = aux;
    }

    while(fechaInicial.toString() != fechaFinal.toString())
    {
        fechaInicial.agregarDias(1);
        contador++;
    }

    if (primerFechaMayor)
    {
		return contador * -1;
    }
    else
    {
        return contador;
    }
}
