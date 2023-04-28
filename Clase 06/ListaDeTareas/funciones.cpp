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

void mostrarTarea(Tarea tarea){

   cout << "ID          : " << tarea.getID() << endl;
   cout << "Descripcion : " << tarea.getDescripcion() << endl;
   cout << "Fecha       : " << tarea.getFechaLimite().toString() << endl;
   cout << "Dificultad  : " << tarea.getNivelDificultad() << endl;
   cout << "Estado      : " << tarea.getDescripcionEstado() << endl;

}

Tarea cargarTarea() {
  string descripcion;
  int dia, mes, anio;
  int dificultad;


  cout << "Ingrese la descripción de la tarea: ";
  cin.ignore();
  getline(cin, descripcion);

  cout << "Ingrese día límite: ";
  cin >> dia;

  cout << "Ingrese mes límite: ";
  cin >> mes;

  cout << "Ingrese año límite: ";
  cin >> anio;

  cout << "Ingrese dificultad de la tarea (1 - Bajo, 2 - Media, 3 - Alta): ";
  dificultad = getInteger(1, 3);

  Tarea aux;
  aux.setFechaLimite(Fecha(dia, mes, anio));
  aux.setNivelDificultad(dificultad);
  aux.setDescripcion(descripcion);

  return aux;
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
