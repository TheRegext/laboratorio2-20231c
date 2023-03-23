#include <iostream>

using namespace std;

void valor(int v) {
  cout << "V ANTES: " << v << endl;
  v = 7;// por mas que cambie el valor de V, en valor de K no va a cambiar

  cout << "V DESPUES: " << v << endl;

  cout << "&V: " << &v << endl;
}

void direccion(int* d) {
  cout << " d: " << d << endl;
  cout << "&d: " << &d << endl;

  *d = 5; // modificando el espacio de memoria de la variable k
}

/* 
* la referencia es literalmente la misma variable, en otras palabras,
* en este caso r y k son lo mismo
*/
void referencia(const int& r) {
 
  cout << " r:" << r << endl;
  cout << "&r: " << &r << endl;
}


int main() {

  int k = 10;

   // valor(10);

  // direccion(&k);

  referencia(k);

  cout << " K: " << k << endl;

  cout << "&K: " << &k << endl;
  
  return 0;
}