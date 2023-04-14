#pragma once
#include "Pelicula.h"

class RankingPeliculas
{
private:
  Pelicula _peliculas[5];
  int _cantidad;

  void ordenar();
public:
  RankingPeliculas();
  void agregar(Pelicula peli);
  void mostrar();

};

