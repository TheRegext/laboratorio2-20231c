#pragma once
#include <string>
#include "Fecha.h"

class Pelicula
{
private:
  std::string _titulo;
  int _puntuacion;
  Fecha _fechaPublicacion;
public:
  Pelicula();
  Pelicula(std::string titulo, Fecha fechaPublicacion, int puntuacion);

  std::string getTitulo();
  Fecha& getFechaPublicacion(); // devuelve el valor del objeto
  int getPuntuacion();
  
  void setTitulo(std::string titulo);
  void setFechaPublicacion(Fecha fechaPublicacion);
  void setPuntuacion(int puntuacion);

};

