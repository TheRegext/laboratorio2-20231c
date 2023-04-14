#include <iostream>
#include "Pelicula.h"
#include "RankingPeliculas.h"
#include "funciones.h"

using namespace std;

int main()
{
  int opcion;
  RankingPeliculas ranking;
  do
  {
    cout << "1- CARGAR PELICULAS" << endl;
    cout << "2- PUNTUAR PELICULA" << endl;
    cout << "3- VER RANKING" << endl;
    cout << "0- SALIR" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      cout << "CARGAR PELICULAS" << endl;
      // ranking.agregar(cargarPelicula());

      ranking.agregar(Pelicula("Tetris", Fecha(31, 3, 2023), 4));
      ranking.agregar(Pelicula("Jurasic Park", Fecha(15, 7, 1993), 5));
      ranking.agregar(Pelicula("Matrix", Fecha(10,1,2012), 4));
      ranking.agregar(Pelicula("Indie Game", Fecha(20,1,2012), 4));
      ranking.agregar(Pelicula("Hackers", Fecha(15, 9, 2012), 3));

      break;
    case 2:
      cout << "PUNTUAR PELICULA" << endl;
      break;
    case 3:
      ranking.mostrar();
      break;
    case 0:
      cout << "SALIR" << endl;
      break;
    default:
      cout << "Opcion incorrecta" << endl;
      break;
    }
  } while (opcion != 0);
  return 0;
}
