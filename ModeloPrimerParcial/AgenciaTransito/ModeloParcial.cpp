#include <iostream>
using namespace std;

#include "ModeloParcial.h"
#include "Agente.h"
#include "AgenteArchivo.h"
#include "Multa.h"
#include "MultaManager.h"

// Para el punto B
#include "EstadisticaAgente.h"

void ModeloParcial::ponerCero(int *vec, int tam){
  for(int i=0; i<tam; i++){
    vec[i] = 0;
  }
}

void ModeloParcial::ponerCero(float *vec, int tam){
  for(int i=0; i<tam; i++){
    vec[i] = 0;
  }
}

void ModeloParcial::PuntoA(){
  cout << "PUNTO A" << endl << endl;
  AgenteArchivo archivoAgentes;
  MultaArchivo archivoMultas;
  
  int cantidadAgentes = archivoAgentes.getCantidadRegistros();
  int cantidadMultas = archivoMultas.getCantidadRegistros();
  
  if (cantidadAgentes == 0)
    return;
  
  int *vecMultas2022;
  vecMultas2022 = new int[cantidadAgentes];

  if (vecMultas2022 == nullptr)
    return;
  
  ponerCero(vecMultas2022, cantidadAgentes);
  
  for(int i=0; i<cantidadMultas; i++){
    Multa multa = archivoMultas.leer(i);
    if (multa.getFechaMulta().getAnio() == 2022 && !multa.getEliminado()){
      int posicionAgente = archivoAgentes.buscar(multa.getIDAgente());
      vecMultas2022[posicionAgente]++;
    }
  }
  
  int cantidadAgentesSinMultasEn2022 = 0;
  for(int i=0; i<cantidadAgentes; i++){
    if(vecMultas2022[i] == 0){
      cantidadAgentesSinMultasEn2022++;
    }
  }
  
  cout << "La cantidad de agentes sin realizar multas en el 2022 fue de : ";
  cout << cantidadAgentesSinMultasEn2022 << endl << endl;
  
  delete[] vecMultas2022;
  
}

// Una alternativa en el que usamos una clase auxiliar aunque se puede resolver de otras maneras
// sin la necesidad de crear una nueva clase.


void ModeloParcial::PuntoB(){
  cout << "PUNTO B" << endl << endl;
  AgenteArchivo archivoAgentes;
  MultaArchivo archivoMultas;
  
  int cantidadAgentes = archivoAgentes.getCantidadRegistros();
  int cantidadMultas = archivoMultas.getCantidadRegistros();
  
  EstadisticaAgente *vecEstadisticasAgentes2023;
  vecEstadisticasAgentes2023 = new EstadisticaAgente[cantidadAgentes];
  
  if (vecEstadisticasAgentes2023 == nullptr)
    return;
  
  // Por cada agente mapeamos los datos del archivo de Agente
  for(int i=0; i<cantidadAgentes; i++){
    Agente agente; // Like si te hizo acordar a una canción de Los Sultanes.
    agente = archivoAgentes.leer(i);
    vecEstadisticasAgentes2023[i].Inicializar(agente.getIdAgente(), agente.getApellidos(), agente.getNombres());
  }
  
  // Por cada multa acumulamos a la estadística del agente
  for(int i=0; i<cantidadMultas; i++){
    Multa multa = archivoMultas.leer(i);
    if (multa.getFechaMulta().getAnio() == 2022 && !multa.getEliminado()){
        int posAgente = archivoAgentes.buscar(multa.getIDAgente());
        vecEstadisticasAgentes2023[posAgente].ContarMulta();
        vecEstadisticasAgentes2023[posAgente].Acumular(multa.getMonto());
    }  
  }
  
  // Mostramos la información final, la prolijidad se las debo
  for(int i=0; i<cantidadAgentes; i++){
    cout << vecEstadisticasAgentes2023[i].toString() << endl;
  }
  
  delete[] vecEstadisticasAgentes2023;
  
}

void ModeloParcial::PuntoC(){
  cout << "PUNTO C" << endl << endl;
  
  MultaArchivo archivoMultas;
  int cantidadMultasPorTipoInfraccion[10] = {};
  int cantidadMultas = archivoMultas.getCantidadRegistros();
  
  for(int i=0; i<cantidadMultas; i++){
    Multa multa = archivoMultas.leer(i);
    if (!multa.getEliminado() && multa.getPagada()){
      cantidadMultasPorTipoInfraccion[multa.getTipoInfraccion()-1]++;
    }
  }
  
  cout << "ID     CANTIDAD" << endl;
  for(int i=0; i<10; i++){
    cout << i+1 << "      " << cantidadMultasPorTipoInfraccion[i] << endl;
  }
  cout << endl << endl; 
  
}

void ModeloParcial::PuntoD(){
  cout << "PUNTO D" << endl << endl;
  
  MultaArchivo archivoMultas;
  MultaArchivo archivoMultasPagadas2022("multaspagadas2022.dat");
  archivoMultasPagadas2022.vaciar();
  
  int cantidadMultas = archivoMultas.getCantidadRegistros();
  int cantidadMultasPagadas2022 = 0;
  
  for(int i=0; i<cantidadMultas; i++){
    Multa multa = archivoMultas.leer(i);
    if (!multa.getEliminado() && multa.getPagada() && multa.getFechaMulta().getAnio() == 2022){
      archivoMultasPagadas2022.guardar(multa);
      cantidadMultasPagadas2022++;
    }
  }
  
  MultaManager multaManager;
  for(int i=0; i<cantidadMultasPagadas2022; i++){
    Multa multa = archivoMultasPagadas2022.leer(i);
    multaManager.Listar(multa);
    cout << endl;
  }
}
