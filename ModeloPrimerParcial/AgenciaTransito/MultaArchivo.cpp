#include "MultaArchivo.h"
#include <cstdio>

MultaArchivo::MultaArchivo()
{
  _ruta = "multas.dat";
}

MultaArchivo::MultaArchivo(std::string ruta)
{
  _ruta = ruta;
}

int MultaArchivo::getCantidadRegistros()
{
  FILE *p = fopen(_ruta.c_str(), "rb");
  
  if (p == NULL)
  {
    return 0;
  }
  
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  
  return bytes / sizeof(Multa);
}

bool MultaArchivo::guardar(Multa reg)
{
  FILE *p = fopen(_ruta.c_str(), "ab");
  
  if (p == NULL)
  {
    return false;
  }
  
  bool pudoEscribir = fwrite(&reg, sizeof(Multa), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool MultaArchivo::guardar(Multa reg, int posicionAReemplazar)
{
  FILE *p = fopen(_ruta.c_str(), "rb+");
  
  if (p == NULL)
  {
    return false;
  }
  
  fseek(p, posicionAReemplazar * sizeof(Multa), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Multa), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool MultaArchivo::guardar(Multa *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(_ruta.c_str(), "ab");
  if (p == NULL)
  {
    return false;
  }
  
  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Multa), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


Multa MultaArchivo::leer(int nroRegistro)
{
  Multa aux;
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return aux;
  }
  
  fseek(p, nroRegistro * sizeof(Multa), SEEK_SET);
  fread(&aux, sizeof(Multa), 1, p);
  fclose(p);
  return aux;
}

void MultaArchivo::leer(Multa *vec, int cantidadRegistrosALeer){
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return ;
  }
  
  fread(vec, sizeof(Multa), cantidadRegistrosALeer, p);
  fclose(p);
}

int MultaArchivo::buscar(int ID)
{
  int i, cantidadRegistros = this->getCantidadRegistros();
  Multa aux;
  
  for(i=0; i<cantidadRegistros; i++)
  {
    aux = this->leer(i);
    if (aux.getIDMulta() == ID)
    {
      return i;
    }
  }
  return -1;
}

void MultaArchivo::vaciar(){
  FILE *p = fopen(_ruta.c_str(), "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}
