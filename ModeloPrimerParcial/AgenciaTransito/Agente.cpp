#include "Agente.h"
#include <cstring>

Agente::Agente(){
  
}

Agente::Agente(int idAgente, std::string apellidos, std::string nombres, int anioIngreso, int categoria, float sueldo) {
  _idAgente = idAgente;
  strcpy(_apellidos, apellidos.c_str());
  strcpy(_nombres, nombres.c_str());
  _anioIngreso = anioIngreso;
  _categoria = categoria;
  _sueldo = sueldo;
}

// Getters
int Agente::getIdAgente() {
  return _idAgente;
}

std::string Agente::getApellidos() {
  std::string apellidosAux = _apellidos;
  return apellidosAux;
}

std::string Agente::getNombres() {
  std::string nombresAux = _nombres;
  return nombresAux;
}

int Agente::getAnioIngreso() {
  return _anioIngreso;
}

int Agente::getCategoria() {
  return _categoria;
}

float Agente::getSueldo() {
  return _sueldo;
}

// Setters
void Agente::setIdAgente(int idAgente) {
  _idAgente = idAgente;
}

void Agente::setApellidos(std::string apellidos) {
  strcpy(_apellidos, apellidos.c_str());
}

void Agente::setNombres(std::string nombres) {
  strcpy(_nombres, nombres.c_str());
}

void Agente::setAnioIngreso(int anioIngreso) {
  _anioIngreso = anioIngreso;
}

void Agente::setCategoria(int categoria) {
  _categoria = categoria;
}

void Agente::setSueldo(float sueldo) {
  _sueldo = sueldo;
}
