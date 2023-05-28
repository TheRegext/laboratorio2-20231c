#include "Multa.h"
#include <string>
#include <cstring>
using namespace std;

Multa::Multa(){
  
}

Multa::Multa(string patente, int idMulta, Fecha fechaMulta, float monto, int idAgente,
             int tipoInfraccion, int idLocalidad, bool pagada, bool eliminado)
{
  strcpy(_patente, patente.c_str());
  _idMulta = idMulta;
  _fechaMulta = fechaMulta;
  _monto = monto;
  _idAgente = idAgente;
  _tipoInfraccion = tipoInfraccion;
  _idLocalidad = idLocalidad;
  _pagada = pagada;
  _eliminado = eliminado;
}

string Multa::getPatente() {
  string patenteAux = _patente;
  return patenteAux;
}

int Multa::getIDMulta() {
  return _idMulta;
}

Fecha Multa::getFechaMulta() {
  return _fechaMulta;
}

float Multa::getMonto() {
  return _monto;
}

int Multa::getIDAgente() {
  return _idAgente;
}

int Multa::getTipoInfraccion() {
  return _tipoInfraccion;
}

int Multa::getIDLocalidad() {
  return _idLocalidad;
}

bool Multa::getPagada() {
  return _pagada;
}

bool Multa::getEliminado() {
  return _eliminado;
}

void Multa::setPatente(std::string patente) {
  strcpy(_patente, patente.c_str());
}

void Multa::setIDMulta(int idMulta) {
  _idMulta = idMulta;
}

void Multa::setFechaMulta(Fecha fechaMulta) {
  _fechaMulta = fechaMulta;
}

void Multa::setMonto(float monto) {
  _monto = monto;
}

void Multa::setIDAgente(int idAgente) {
  _idAgente = idAgente;
}

void Multa::setTipoInfraccion(int tipoInfraccion) {
  _tipoInfraccion = tipoInfraccion;
}

void Multa::setIDLocalidad(int idLocalidad) {
  _idLocalidad = idLocalidad;
}

void Multa::setPagada(bool pagada) {
  _pagada = pagada;
}

void Multa::setEliminado(bool eliminado) {
  _eliminado = eliminado;
}
