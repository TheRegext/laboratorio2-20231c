#include <iostream>
#include "funciones.h"

using namespace std;

Pelicula cargarPelicula() {
  string titulo;
  int dia, mes, anio;

  cout << "Ingrese el titulo de la pelicula: ";
  cin.ignore();
  getline(cin, titulo);

  cout << "Ingrese dia de publicacion: ";
  cin >> dia;

  cout << "Ingrese mes de publicacion: ";
  cin >> mes;

  cout << "Ingrese anio de publicacion: ";
  cin >> anio;

  Pelicula aux;
  Fecha fecha(dia, mes, anio);
  aux.setTitulo(titulo);
  aux.setFechaPublicacion(fecha);
  return aux;
  //return Pelicula(titulo, Fecha(dia, mes, anio), 0);
}