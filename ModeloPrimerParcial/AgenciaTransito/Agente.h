#ifndef AGENTE_H
#define AGENTE_H

#include <string>

class Agente {
private:
  int _idAgente;
  char _apellidos[50];
  char _nombres[50];
  int _anioIngreso;
  int _categoria;
  float _sueldo;
  
public:
  Agente();
  Agente(int idAgente, std::string apellidos, std::string nombres, int anioIngreso, int categoria, float sueldo);
  
  // Getters
  int getIdAgente();
  std::string getApellidos();
  std::string getNombres();
  int getAnioIngreso();
  int getCategoria();
  float getSueldo();
  
  // Setters
  void setIdAgente(int idAgente);
  void setApellidos(std::string apellidos);
  void setNombres(std::string nombres);
  void setAnioIngreso(int anioIngreso);
  void setCategoria(int categoria);
  void setSueldo(float sueldo);
};

#endif
