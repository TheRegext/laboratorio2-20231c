#include <iostream>
using namespace std;
#include "Fecha.h"

int main()
{
   Fecha f(2, 10, 1986);

   f.agregarDias(10000);
   cout << f.toString();

   return 0;
}
