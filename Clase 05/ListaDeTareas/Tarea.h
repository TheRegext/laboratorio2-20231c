#pragma once
#include "Tarea.h"
#include "Fecha.h"
#include <string>

class Tarea
{
private:
  int _ID;
  std::string _descripcion;
  Fecha _fechaLimite;
  int _nivel;
  int _estado;

  void ordenar();

public:
  Tarea();
  Tarea(std::string descripcion, Fecha fechaLimite, int nivel, int estado = 0);

  int getID();
  std::string getDescripcion();
  Fecha getFechaLimite();
  std::string getNivelDificultad();
  std::string getDescripcionEstado();

  void setID(int ID);
  void setDescripcion(std::string descripcion);
  void setFechaLimite(Fecha fechaLimite);
  void setNivelDificultad(int nivelDificultad);
  void setEstado(int estado);

};

