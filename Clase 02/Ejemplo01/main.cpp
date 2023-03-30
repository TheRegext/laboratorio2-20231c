#include <iostream>
using namespace std;

/**
*   @brief Busca un elemento dentro del vector que se envía como parámetro.
*   @param vec El vector donde buscar
*   @param TAM El tamaño del vector
*   @param elementoBuscado El elemento a buscar en el vector
*   @return bool
*/
bool existeElementoEnVector(int *vec, const int TAM, int elementoBuscado){
   for(int i=0; i<TAM; i++){
      if (vec[i] == elementoBuscado){
         return true;
      }
   }
   return false;
}

/**
  Muestra los elementos que existen en el vector A pero no en el vector B y viceversa.
*/
void mostrarDiferenciaSimetrica(int *vecA, const int tamA, int *vecB, const int tamB){
   int *vecC = nullptr;
   int pos = 0;

   vecC = new int[tamA+tamB];
   if (vecC != nullptr){
      /// Relleno los elementos que están en A pero no en B
      for(int i=0; i<tamA; i++){
         if (!existeElementoEnVector(vecB, tamB, vecA[i])){
            vecC[pos++] = vecA[i];
         }
      }
      /// Relleno los elementos que están en B pero no en A
      for(int i=0; i<tamB; i++){
         if (!existeElementoEnVector(vecA, tamA, vecB[i])){
            vecC[pos++] = vecB[i];
         }
      }

      if (pos > 0){
         for(int i=0; i<pos; i++){
          cout << vecC[i] << " ";
         }
      }
      delete []vecC;
   }
}


int main()
{
   int vecA[5] = {1, 2, 3, 4, 5};
   int vecB[7] = {1, 2, 3, 10, 20, 30, 40};

   mostrarDiferenciaSimetrica(vecA, 5, vecB, 7);

   return 0;
}
