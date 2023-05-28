#include "AgenteArchivo.h"
#include <cstdio>

AgenteArchivo::AgenteArchivo()
{
  _ruta = "agentes.dat";
}

AgenteArchivo::AgenteArchivo(std::string ruta)
{
  _ruta = ruta;
}

int AgenteArchivo::getCantidadRegistros()
{
  FILE *p = fopen(_ruta.c_str(), "rb");
  
  if (p == NULL)
  {
    return 0;
  }
  
  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);
  
  return bytes / sizeof(Agente);
}

bool AgenteArchivo::guardar(Agente reg)
{
  FILE *p = fopen(_ruta.c_str(), "ab");
  
  if (p == NULL)
  {
    return false;
  }
  
  bool pudoEscribir = fwrite(&reg, sizeof(Agente), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool AgenteArchivo::guardar(Agente reg, int posicionAReemplazar)
{
  FILE *p = fopen(_ruta.c_str(), "rb+");
  
  if (p == NULL)
  {
    return false;
  }
  
  fseek(p, posicionAReemplazar * sizeof(Agente), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Agente), 1, p);
  fclose(p);
  return pudoEscribir;
}

bool AgenteArchivo::guardar(Agente *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(_ruta.c_str(), "ab");
  if (p == NULL)
  {
    return false;
  }
  
  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Agente), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


Agente AgenteArchivo::leer(int nroRegistro)
{
  Agente aux;
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return aux;
  }
  
  fseek(p, nroRegistro * sizeof(Agente), SEEK_SET);
  fread(&aux, sizeof(Agente), 1, p);
  fclose(p);
  return aux;
}

void AgenteArchivo::leer(Agente *vec, int cantidadRegistrosALeer){
  FILE *p = fopen(_ruta.c_str(), "rb");
  if (p == NULL)
  {
    return ;
  }
  
  fread(vec, sizeof(Agente), cantidadRegistrosALeer, p);
  fclose(p);
}

int AgenteArchivo::buscar(int ID)
{
  int i, cantidadRegistros = this->getCantidadRegistros();
  Agente aux;
  
  for(i=0; i<cantidadRegistros; i++)
  {
    aux = this->leer(i);
    if (aux.getIdAgente() == ID)
    {
      return i;
    }
  }
  return -1;
}

void AgenteArchivo::vaciar(){
  FILE *p = fopen(_ruta.c_str(), "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}
