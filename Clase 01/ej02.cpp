#include <iostream>
using namespace std;

int main(){

  float vec_fijo[100];

  int cant;
  cout << "Ingresar la cantidad de elementos del vector: ";
  cin >> cant;

  float *vec_dinamico = nullptr;
  vec_dinamico = new float[cant];

  if (vec != nullptr){
    // Hacemos algo con el vector para demostrar que tenemos disponible
    // todos los elementos.
    delete []vec_dinamico;
  }
  else{
    cout << "No hay memoria suficiente para la operación";
  }

  return 0;
}
