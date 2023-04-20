#include <iostream>
#include <clocale>
#include "Tarea.h"
#include "ListaDeTareas.h"
#include "funciones.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  int opcion;
  ListaDeTareas listaTareas;
  do
  {
    cout << "1- CARGAR TAREA" << endl;
    cout << "2- FINALIZAR TAREA" << endl;
    cout << "3- VER LISTA DE TAREAS" << endl;
    cout << "4- VER LISTA DE TAREAS (CON DEADLINE)" << endl;
    cout << "0- SALIR" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      cout << "CARGAR TAREA" << endl;
       listaTareas.agregar(cargarTarea());
      break;
    case 2:
      cout << "FINALIZAR TAREA (No resuelto)" << endl;
      break;
    case 3:
      listaTareas.mostrar();
      break;
      case 4:
      cout << "TODO: Listado que muestre por cada tarea la cantidad de días disponibles para su vencimiento (Fecha límite)" << endl;
      break;
    case 99:
      listaTareas = hardcodearTareas();
    case 0:
      cout << "SALIR" << endl;
      break;
    default:
      cout << "Opcion incorrecta" << endl;
      break;
    }
  } while (opcion != 0);
  return 0;
}
