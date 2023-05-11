#include "TareaArchivo.h"

#include <cstdio>


TareaArchivo::TareaArchivo()
{
    _ruta = "tareas.dat";
}

TareaArchivo::TareaArchivo(std::string ruta)
{
    _ruta = ruta;
}

int TareaArchivo::getCantidadRegistros()
{
    FILE *p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Tarea);
}

bool TareaArchivo::guardar(Tarea reg)
{
    FILE *p = fopen(_ruta.c_str(), "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Tarea), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool TareaArchivo::guardar(Tarea reg, int posicionAReemplazar)
{
    FILE *p = fopen(_ruta.c_str(), "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Tarea), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Tarea), 1, p);
    fclose(p);
    return pudoEscribir;
}

Tarea TareaArchivo::leer(int nroRegistro)
{
    Tarea aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Tarea), SEEK_SET);
    fread(&aux, sizeof(Tarea), 1, p);
    fclose(p);
    return aux;
}

int TareaArchivo::buscar(int ID)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Tarea aux;

    for(i=0; i<cantidadRegistros; i++)
    {
        aux = this->leer(i);
        if (aux.getID() == ID)
        {
            return i;
        }
    }
    return -1;
}

