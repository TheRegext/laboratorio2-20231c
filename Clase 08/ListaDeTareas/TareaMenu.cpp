#include <iostream>
using namespace std;
#include "TareaMenu.h"

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
        cout << "5. Eliminar" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            _tareaManager.Cargar();
            break;
        case 2:
			_tareaManager.Editar();
            break;
        case 3:
			_tareaManager.ListarTodos();
            break;
        case 4:
			_tareaManager.ListarXId();
            break;
        case 5:
            _tareaManager.Eliminar();
            break;
        }

    }
    while(opcion != 0);
}
