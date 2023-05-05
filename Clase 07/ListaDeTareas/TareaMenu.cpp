#include <iostream>
using namespace std;

#include "TareaMenu.h"
#include "TareaArchivo.h"
#include "funciones.h"



/*
Cargar
Editar
Listar todos
Listar x ID
*/
void TareaMenu::Cargar()
{
    string descripcion;
    int id;
    int dia, mes, anio;
    int dificultad;

    cout << "Ingrese el ID: ";
    cin >> id;

    cout << "Ingrese la descripción de la tarea: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Ingrese día límite: ";
    cin >> dia;

    cout << "Ingrese mes límite: ";
    cin >> mes;

    cout << "Ingrese año límite: ";
    cin >> anio;

    cout << "Ingrese dificultad de la tarea (1 - Bajo, 2 - Media, 3 - Alta): ";
    dificultad = getInteger(1, 3);

    Tarea aux;
    aux.setID(id);
    aux.setFechaLimite(Fecha(dia, mes, anio));
    aux.setNivelDificultad(dificultad);
    aux.setDescripcion(descripcion);

    if (_archivo.guardar(aux))
    {
        cout << "Tarea guardada correctamente" << endl;
    }
    else
    {
        cout << "Ups! Algo salio mal :(" << endl;
    }
}

void TareaMenu::ListarTodos()
{
    int cantidadRegistros = _archivo.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Tarea reg = _archivo.leer(i);
        Listar(reg);
        cout << endl;
    }
}

void TareaMenu::ListarXId()
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = _archivo.buscar(id);
    if (posicion >= 0)
    {
        Tarea reg = _archivo.leer(posicion);
        Listar(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void TareaMenu::Listar(Tarea tarea)
{
    cout << "ID          : " << tarea.getID() << endl;
    cout << "Descripcion : " << tarea.getDescripcion() << endl;
    cout << "Fecha       : " << tarea.getFechaLimite().toString() << endl;
    cout << "Dificultad  : " << tarea.getNivelDificultad() << endl;
    cout << "Estado      : " << tarea.getDescripcionEstado() << endl;
}

void TareaMenu::Editar()
{
    Tarea reg;
    int id, posicion;
    cout << "ID a buscar: ";
    cin >> id;
    cout << endl;

    posicion = _archivo.buscar(id);
    if (posicion >= 0)
    {
        reg = _archivo.leer(posicion);
        Listar(reg);
        cout << endl;

        int nuevoEstado;
        cout << "Nuevo estado: ";
        cin >> nuevoEstado;
        reg.setEstado(nuevoEstado);
        _archivo.guardar(reg, posicion);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void TareaMenu::Mostrar()
{
    int opcion;
    do
    {
        Tarea reg;
        cout << "---------------" << endl;
        cout << "--MENU TAREAS--" << endl;
        cout << "---------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Listar todos" << endl;
        cout << "4. Listar x ID" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            Cargar();
            break;
        case 2:
            Editar();
            break;
        case 3:
            ListarTodos();
            break;
        case 4:
            ListarXId();
            break;
        }


    }
    while(opcion != 0);
}
