#pragma once

#include "Agente.h"
#include <string>

class AgenteArchivo
{
public:
  int getCantidadRegistros();
  bool guardar(Agente reg);
  bool guardar(Agente reg, int posicionAReemplazar);
  bool guardar(Agente *vec, int cantidadRegistrosAEscribir);
  
  Agente leer(int nroRegistro);
  void leer(Agente *vec, int cantidadRegistrosALeer);
  int buscar(int ID);
  void vaciar();
  
  AgenteArchivo();
  AgenteArchivo(std::string ruta);
private:
  std::string _ruta;
};
