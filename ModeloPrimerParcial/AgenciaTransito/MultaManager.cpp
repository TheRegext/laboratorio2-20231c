#include <iostream>
#include "MultaManager.h"

using namespace std;

void MultaManager::Cargar() {
  
  string patente;
  int idMulta;
  float monto;
  int idAgente;
  int tipoInfraccion;
  int idLocalidad;
  bool pagada;
  bool eliminado;
  int dia, mes, anio;
  
  cout << "Ingrese los detalles de la multa:\n";
  
  cout << "Patente: ";
  cin >> patente;
  
  cout << "ID Multa: ";
  cin >> idMulta;
  
  cout << "Fecha Multa: ";
  cin >> dia;
  cin >> mes;
  cin >> anio;
  
  Fecha f(dia, mes, anio);
  
  cout << "Monto: ";
  cin >> monto;
  
  cout << "ID Agente: ";
  cin >> idAgente;
  
  cout << "Tipo Infracción: ";
  cin >> tipoInfraccion;
  
  cout << "ID Localidad: ";
  cin >> idLocalidad;
  
  cout << "Pagada (1: Sí, 0: No): ";
  cin >> pagada;
  
  eliminado = 0;
  
  Multa multa(patente, idMulta, f, monto, idAgente, tipoInfraccion, idLocalidad, pagada, eliminado);
  _archivo.guardar(multa);
}

void MultaManager::ListarTodos()
{
  int cantidadRegistros = _archivo.getCantidadRegistros();
  
  for (int i = 0; i<cantidadRegistros; i++)
  {
    Multa reg = _archivo.leer(i);
    if (!reg.getEliminado())
    {
      Listar(reg);
      cout << endl;
    }
  }
}

void MultaManager::ListarXId()
{
  int id;
  
  cout << "Ingrese el ID: ";
  cin >> id;
  
  int posicion = _archivo.buscar(id);
  if (posicion >= 0)
  {
    Multa reg = _archivo.leer(posicion);
    Listar(reg);
  }
  else
  {
    cout << "No existe el registro con ID #" << id << endl;
  }
}

void MultaManager::Listar(Multa multa) {
  cout << "Detalles de la multa:\n";
  cout << "Patente: " << multa.getPatente() << "\n";
  cout << "ID Multa: " << multa.getIDMulta() << "\n";
  cout << "Fecha Multa: " << multa.getFechaMulta().toString() << "\n";
  cout << "Monto: " << multa.getMonto() << "\n";
  cout << "ID Agente: " << multa.getIDAgente() << "\n";
  cout << "Tipo Infraccion: " << multa.getTipoInfraccion() << "\n";
  cout << "ID Localidad: " << multa.getIDLocalidad() << "\n";
  cout << "Pagada: " << multa.getPagada() << "\n";
}

bool MultaManager::ExisteId(int id)
{
  return _archivo.buscar(id) >= 0;
}

int MultaManager::GenerarId()
{
  return _archivo.getCantidadRegistros() + 1;
}

void MultaManager::HacerCopiaDeSeguridad(){
  int cantidadRegistros = _archivo.getCantidadRegistros();
  Multa *vec = new Multa[cantidadRegistros];
  
  if (vec == nullptr){
    cout << "Falla al realizar backup" << endl;
    return;
  }
  
  _archivo.leer(vec, cantidadRegistros);
  _archivoBkp.vaciar();
  if (_archivoBkp.guardar(vec, cantidadRegistros)){
    cout << "Backup realizado correctamente" << endl;
  }
  else{
    cout << "Falla al realizar backup" << endl;
  }
  
  delete []vec;
}

void MultaManager::RestaurarCopiaDeSeguridad(){
  
  int cantidadRegistros = _archivoBkp.getCantidadRegistros();
  Multa *vec = new Multa[cantidadRegistros];
  
  if (vec == nullptr){
    cout << "Falla al restaurar backup" << endl;
    return;
  }
  
  _archivoBkp.leer(vec, cantidadRegistros);
  _archivo.vaciar();
  if (_archivo.guardar(vec, cantidadRegistros)){
    cout << "Backup restaurado correctamente" << endl;
  }
  else{
    cout << "Falla al restaurar backup" << endl;
  }
  
  delete []vec;
  
  
}
