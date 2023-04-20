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

ListaDeTareas hardcodearTareas(){

   ListaDeTareas lista;
   lista.agregar(Tarea("Arañar cortinas", Fecha(23, 4, 2023), 2));
   lista.agregar(Tarea("Maullar", Fecha(3, 5, 2023), 1));
   lista.agregar(Tarea("Dormir todo el día", Fecha(13, 5, 2023), 1));
   lista.agregar(Tarea("Dejar pelo por todos lados", Fecha(10, 6, 2023), 1));
   lista.agregar(Tarea("Cazar bichos", Fecha(1, 7, 2023), 3));
   lista.agregar(Tarea("Comer croquetas", Fecha(21, 4, 2023), 3));
   lista.agregar(Tarea("Comer atún", Fecha(27, 4, 2023), 1));
   lista.agregar(Tarea("Morder", Fecha(13, 5, 2023), 1, 1));
   lista.agregar(Tarea("Ir a los techos", Fecha(13, 8, 2023), 2));

   return lista;

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
