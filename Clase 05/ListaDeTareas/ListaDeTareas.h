#pragma once
#include "Tarea.h"

class ListaDeTareas
{
private:
  Tarea _listaTareas[10];
  int _cantidad;

  void ordenar();
public:
  ListaDeTareas();
  void agregar(Tarea tarea);
  void mostrar();

};

