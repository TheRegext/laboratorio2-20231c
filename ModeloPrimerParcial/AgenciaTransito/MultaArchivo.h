#pragma once

#include "Multa.h"
#include <string>

class MultaArchivo
{
public:
  int getCantidadRegistros();
  bool guardar(Multa reg);
  bool guardar(Multa reg, int posicionAReemplazar);
  bool guardar(Multa *vec, int cantidadRegistrosAEscribir);
  
  Multa leer(int nroRegistro);
  void leer(Multa *vec, int cantidadRegistrosALeer);
  int buscar(int ID);
  void vaciar();
  
  MultaArchivo();
  MultaArchivo(std::string ruta);
private:
  std::string _ruta;
};
