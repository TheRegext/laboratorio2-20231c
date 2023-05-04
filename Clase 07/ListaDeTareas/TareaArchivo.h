#pragma once
#include "Tarea.h"

class TareaArchivo
{
   public:
      int getCantidadRegistros();
      bool guardar(Tarea reg);
      bool guardar(Tarea reg, int posicionAReemplazar);
      //bool leer(Tarea &reg, int nroRegistro);
      Tarea leer(int nroRegistro);
      int buscar(int ID);
};
