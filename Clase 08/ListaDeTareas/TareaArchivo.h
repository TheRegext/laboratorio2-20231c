#pragma once
#include "Tarea.h"

#include <string>

class TareaArchivo
{
public:
    int getCantidadRegistros();
    bool guardar(Tarea reg);
    bool guardar(Tarea reg, int posicionAReemplazar);
	bool guardar(Tarea *vec, int cantidadRegistrosAEscribir);
	
    //bool leer(Tarea &reg, int nroRegistro);
    Tarea leer(int nroRegistro);
	void leer(Tarea *vec, int cantidadRegistrosALeer);
    int buscar(int ID);
	void vaciar();

    TareaArchivo();
    TareaArchivo(std::string ruta);
private:
    std::string _ruta;
};
