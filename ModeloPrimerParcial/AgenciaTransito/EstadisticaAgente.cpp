#include <string>
using namespace std;
#include "EstadisticaAgente.h"

void EstadisticaAgente::Inicializar(int IDAgente, std::string Apellidos, std::string Nombres){
  
  _IDAgente = IDAgente;
  _apellidos = Apellidos;
  _nombres = Nombres;
  _cantMultas = 0;
  _totalAcumulado = 0;
 
}

void EstadisticaAgente::Acumular(float totalAAcumular){
  _totalAcumulado += totalAAcumular;
}

void EstadisticaAgente::ContarMulta(){
  _cantMultas++;
}

string EstadisticaAgente::getApellidos(){
  return _apellidos;
}
string EstadisticaAgente::getNombres(){
  return _nombres;
}

string EstadisticaAgente::toString(){
  string cadena = std::to_string(_IDAgente) + " " + _apellidos + " " + _nombres + " " + std::to_string(_cantMultas) + " " + std::to_string(_totalAcumulado);
  return cadena;
}
