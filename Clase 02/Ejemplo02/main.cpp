#include <iostream>
using namespace std;

int main()
{
   float capacidadesVasos[3] = {0.15f, 0.2f, 0.3f};

   ///Stock batidos
   float stockBanana=0.5, stockAnana=3, stockSandia=4;

   ///Cantidad batidos vendidos
   int cantBanana=0, cantAnana=0, cantSandia=0;

   /// Registro de una venta
   int codBatido, codVaso;
   float litros;

   cout << "Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
   cin >> codBatido;

   while(codBatido != 0){

      cout << "Vaso (1 - 150ml, 2 - 200ml, 3 - 300ml): ";
      cin >> codVaso;

      litros = capacidadesVasos[codVaso-1];

      switch(codBatido){
         case 1:
            if (stockBanana >= litros){
               stockBanana-=litros;
               cantBanana++;
            }
            else{
               cout << "Sin stock de ese producto" << endl;
            }
         break;
         case 2:
            if (stockAnana >= litros){
               stockAnana-=litros;
               cantAnana++;
            }
            else{
               cout << "Sin stock de ese producto" << endl;
            }
         break;
         case 3:
            if (stockSandia >= litros){
               stockSandia-=litros;
               cantSandia++;
            }
            else{
               cout << "Sin stock de ese producto" << endl;
            }
         break;
         default:
            cout << "No existe ese sabor" << endl;
         break;
      }
      cout <<  "-------------------------------------" << endl;
      cout << "Batido (1 - Banana, 2 - Anana, 3 - Sandia): ";
      cin >> codBatido;
   }

   cout << endl << "Estadisticas del dia: " << endl;
   cout << "-------------------------------------" << endl;
   cout << "Banana: " << stockBanana << " lts (" << cantBanana << " ventas)" << endl;
   cout << "Anana : " << stockAnana << " lts (" << cantAnana << " ventas)" << endl;
   cout << "Sandia: " << stockSandia << " lts (" << cantSandia << " ventas)" << endl;


    return 0;
}
