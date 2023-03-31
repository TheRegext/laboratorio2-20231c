#pragma once
#include <string>
using namespace std;

// declaracion de la clase 
// declaramos las propiedades y metodos que tendra la clase
class Bidon
{
private:
  string _sabor; // el guion bajo se suele utilizar para identificar los miembros
  float _capacidad;


public: // esto sera la interfaz del objeto
  Bidon(); // contructor por defecto

  // getters y setters
  void setSabor(string sabor);
  string getSabor();

  void setCapacidad(float capacidad);
  float getCapacidad();

  void extraer(float cantidad);
//  void llenar();
  
};

