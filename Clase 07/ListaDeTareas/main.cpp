#include <iostream>
#include <clocale>
using namespace std;

#include "TareaArchivo.h"
#include "funciones.h"

int main()
{
/*
   TareaArchivo tareaArchivo;
   int i, cantidadRegistros = tareaArchivo.getCantidadRegistros();

   for(i=0; i<cantidadRegistros; i++){
      mostrarTarea(tareaArchivo.leer(i));
   }
*/

   /*
   TareaArchivo tareaArchivo;
   Tarea reg;
   int ID, posicion;
   cout << "ID a buscar: ";
   cin >> ID;
   cout << endl;
   posicion = tareaArchivo.buscar(ID);
   if (posicion >= 0){
      reg = tareaArchivo.leer(posicion);
      mostrarTarea(reg);
      cout << endl;
      int nuevoEstado;
      cout << "Nuevo estado: ";
      cin >> nuevoEstado;
      reg.setEstado(nuevoEstado);
      tareaArchivo.guardar(reg, posicion);
   }
   else{
      cout << "No existe el registro con ID #" << ID << endl;
   }
*/

   /* Lee el archivo de tareas y lo muestra por pantalla  */
   /*Tarea reg;

   FILE *p = fopen("tareas.dat", "rb");
   if (p == NULL){
      cout << "No se pudo abrir el archivo";
      return 1;
   }

   fseek(p, 0, SEEK_END);
   int bytes = ftell(p);
   int cantidadRegistros = bytes / sizeof(Tarea);
   cout << bytes << " bytes" << endl;
   cout << cantidadRegistros << " cantidad registros" << endl;*/

   /*while (fread(&reg, sizeof(Tarea), 1, p)){
      mostrarTarea(reg);
      cout << endl;
   }*/



   /* Escribe en el archivo de tareas tres tareas  */
   /*
   Tarea reg1(1, "Aprender archivos", Fecha(29, 4, 2023), 3, 0);
   Tarea reg2(2, "Estudiar estadistica", Fecha(29, 4, 2023), 3, 0);
   Tarea reg3(3, "Repasar POO", Fecha(28, 4, 2023), 2, 0);

   FILE *p = fopen("tareas.dat", "ab");
   if (p == NULL){
      cout << "No se pudo abrir el archivo";
      return 1;
   }

   fwrite(&reg1, sizeof(Tarea), 1, p);
   fwrite(&reg2, sizeof(Tarea), 1, p);
   fwrite(&reg3, sizeof(Tarea), 1, p);
   fclose(p);
*/

   /* Disponer de un menú que permita cargar una nueva tarea y guardarla en el archivo */
   /* Leer secuencialmente todas las tareas y mostrarlas por pantalla */

  return 0;
}
