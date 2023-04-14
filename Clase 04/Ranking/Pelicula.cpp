#include "Pelicula.h"

Pelicula::Pelicula()
{
  _titulo = "";
  _fechaPublicacion = Fecha();
  _puntuacion = 0;
}

Pelicula::Pelicula(std::string titulo, Fecha fechaPublicacion, int puntuacion)
{
  _titulo = titulo;
  _fechaPublicacion = fechaPublicacion;
  _puntuacion = puntuacion;
}

std::string Pelicula::getTitulo()
{
  return _titulo;
}

Fecha& Pelicula::getFechaPublicacion()
{
  return _fechaPublicacion;
}

int Pelicula::getPuntuacion()
{
  return _puntuacion;
}

void Pelicula::setTitulo(std::string titulo)
{
  _titulo = titulo;
}

void Pelicula::setFechaPublicacion(Fecha fechaPublicacion)
{
  _fechaPublicacion = fechaPublicacion;
}

void Pelicula::setPuntuacion(int puntuacion)
{
  _puntuacion = puntuacion;
}


