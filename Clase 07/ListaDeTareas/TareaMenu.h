#pragma once

#include "Tarea.h"
#include "TareaArchivo.h"

class TareaMenu
{
public:
    void Mostrar();

private:
    void Cargar();
    void ListarTodos();
    void ListarXId();
    void Editar();


    void Listar(Tarea tarea);

    TareaArchivo _archivo;
};
