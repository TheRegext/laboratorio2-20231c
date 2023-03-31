#include "Bidon.h"
// creal la definicion de los metodos
Bidon::Bidon() {
  _sabor = "Sin Sabor";
  _capacidad = 1.0f;
}

void Bidon::setSabor(string sabor)
{
  _sabor = sabor;
}

string Bidon::getSabor()
{
  return _sabor;
}

void Bidon::setCapacidad(float capacidad)
{
  _capacidad = capacidad;
}

float Bidon::getCapacidad()
{
  return _capacidad;
}

void Bidon::extraer(float cantidad) {
  if (cantidad > 0) {
    _capacidad -= cantidad;

    if (_capacidad < 0) {
      _capacidad = 0;
    }
  }
}