#pragma once
#include "Tarea.h"

#include <string>

class TareaArchivo
{
public:
    int getCantidadRegistros();
    bool guardar(Tarea reg);
    bool guardar(Tarea reg, int posicionAReemplazar);
    //bool leer(Tarea &reg, int nroRegistro);
    Tarea leer(int nroRegistro);
    int buscar(int ID);

    TareaArchivo();
    TareaArchivo(std::string ruta);
private:
    std::string _ruta;
};
