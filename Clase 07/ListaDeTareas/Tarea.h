#pragma once
#include "Tarea.h"
#include "Fecha.h"
#include <string>

class Tarea
{
private:
  int _ID;
  char _descripcion[30];
  Fecha _fechaLimite;
  int _nivel;
  int _estado;

public:
  Tarea();
  Tarea(int ID, std::string descripcion, Fecha fechaLimite, int nivel, int estado = 0);


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

