#include <iostream>
using namespace std;
#include "Bidon.h"

int main() {
  // creando una instancia de un Bidon
  // creado un objeto de tipo Bidon
  Bidon b1, b2; 
  b1.setSabor("Banana");
  b1.setCapacidad(40);

  b2.setSabor("Anana");
  b2.setCapacidad(44);

  cout << "Sabor: " << b1.getSabor() << endl;
  cout << "Capacidad: " << b1.getCapacidad() << endl;
  /*
  cout << "Sabor: " << b2.getSabor() << endl;
  cout << "Capacidad: " << b2.getCapacidad() << endl;
  */
  b1.extraer(20);

  cout << "Capacidad: " << b1.getCapacidad() << endl;
  
  b1.extraer(30);

  cout << "Capacidad: " << b1.getCapacidad() << endl;

  b1.extraer(30);

  cout << "Capacidad: " << b1.getCapacidad() << endl;

  b1.extraer(30);

  cout << "Capacidad: " << b1.getCapacidad() << endl;

  b1.extraer(-30);

  cout << "Capacidad: " << b1.getCapacidad() << endl;



 
  return 0;
}