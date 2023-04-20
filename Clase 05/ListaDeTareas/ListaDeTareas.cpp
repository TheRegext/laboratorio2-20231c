#include "ListaDeTareas.h"
#include <iostream>
using namespace std;
#include <iomanip>

ListaDeTareas::ListaDeTareas()
{
  _cantidad = 0;
}

void ListaDeTareas::agregar(Tarea tarea)
{
  if (_cantidad < 10) {
    tarea.setID(_cantidad+1);
    _listaTareas[_cantidad] = tarea;
    _cantidad++;
  }
}

void ListaDeTareas::mostrar() {
  cout << "------------------------------------------------------------" << endl;
  cout << "                    LISTA DE TAREAS" << endl;
  cout << "------------------------------------------------------------" << endl;

  ordenar();

  for (int i = 0; i < _cantidad; i++) {
    cout << setw(30) << setiosflags(ios::left) << _listaTareas[i].getDescripcion();
    cout << setw(10) << setiosflags(ios::left) <<  _listaTareas[i].getNivelDificultad();
    cout << setw(15) << setiosflags(ios::left) << _listaTareas[i].getFechaLimite().toString();
    cout << setw(15) << setiosflags(ios::left) << _listaTareas[i].getDescripcionEstado() << endl;
  }
  cout << "------------------------------------------------------------" << endl;
 }

void ListaDeTareas::ordenar() {
  int mayor = 0;
  Tarea aux; // lo necesitamos unicamente en este metodo

  for (int i = 0; i < _cantidad-1; i++) {
    mayor = i;

    for (int j = i + 1; j < _cantidad; j++) {
      if (_listaTareas[j].getFechaLimite().toString("YYYY/MM/DD") < _listaTareas[mayor].getFechaLimite().toString("YYYY/MM/DD")) {
        mayor = j;
      }
    }

    if (i != mayor) {
      aux = _listaTareas[i]; // se hace una copia del objeto
      _listaTareas[i] = _listaTareas[mayor];
      _listaTareas[mayor] = aux;
    }
    // mayor
  }




}
