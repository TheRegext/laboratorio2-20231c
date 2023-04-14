#include <iostream>
#include "RankingPeliculas.h"
using namespace std;

RankingPeliculas::RankingPeliculas()
{
  _cantidad = 0;
}

void RankingPeliculas::agregar(Pelicula peli)
{
  if (_cantidad < 5) {
    _peliculas[_cantidad] = peli;
    _cantidad++;
  }
}

void RankingPeliculas::mostrar() {
  cout << "-----------------------" << endl;
  cout << "       RANKING       " << endl;
  cout << "-----------------------" << endl;

  ordenar();

  for (int i = 0; i < _cantidad; i++) {
    cout << _peliculas[i].getTitulo() << "\t" 
      << _peliculas[i].getFechaPublicacion().toString() << "\t" 
      << _peliculas[i].getPuntuacion() << endl;
  }
  cout << "-----------------------" << endl << endl;
 }

void RankingPeliculas::ordenar() {
  int mayor = 0;
  Pelicula aux; // lo necesitamos unicamente en este metodo

  for (int i = 0; i < _cantidad-1; i++) {
    mayor = i;

    for (int j = i + 1; j < _cantidad; j++) {
      //if(_peliculas[j].getFechaPublicacion().toString("YYYY/MM/DD") > _peliculas[mayor].getFechaPublicacion().toString("YYYY/MM/DD")) {
      //if (_peliculas[j].getTitulo().size() > _peliculas[mayor].getTitulo().size()) {

      if (_peliculas[j].getPuntuacion() > _peliculas[mayor].getPuntuacion()) {
        mayor = j;
      }
    }

    if (i != mayor) {
      aux = _peliculas[i]; // se hace una copia del objeto 
      _peliculas[i] = _peliculas[mayor];
      _peliculas[mayor] = aux;
    }
    // mayor
  }




}
