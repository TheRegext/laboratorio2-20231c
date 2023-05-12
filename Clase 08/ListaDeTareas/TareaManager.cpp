#include <iostream>
#include "TareaManager.h"

using namespace std;

#include "funciones.h"

void TareaManager::Cargar()
{
	string descripcion;
	int id;
	int dia, mes, anio;
	int dificultad;

//	cout << "Ingrese el ID: ";
//	cin >> id;

//    if (ExisteId(id))
//    {
//        cout << "ID repetido" << endl;
//        return;
//    }
    id = GenerarId();
    cout << "ID Tarea #" << id << endl;


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

void TareaManager::ListarTodos()
{
	int cantidadRegistros = _archivo.getCantidadRegistros();

	for (int i = 0; i<cantidadRegistros; i++)
	{
		Tarea reg = _archivo.leer(i);
        if (!reg.getEliminado())
        {
            Listar(reg);
            cout << endl;
        }
	}
}

void TareaManager::Ordenar(Tarea *vec, int cantidadRegistros) {
	int mayor = 0;
	Tarea aux; // lo necesitamos unicamente en este metodo
	
	for (int i = 0; i < cantidadRegistros-1; i++) {
		mayor = i;
		
		for (int j = i + 1; j < cantidadRegistros; j++) {
			//if(_peliculas[j].getFechaPublicacion().toString("YYYY/MM/DD") > _peliculas[mayor].getFechaPublicacion().toString("YYYY/MM/DD")) {
			//if(_peliculas[j].getTitulo().size() > _peliculas[mayor].getTitulo().size()) {
			
			if (vec[j].getFechaLimite().toString("YYYY/MM/DD") > vec[mayor].getFechaLimite().toString("YYYY/MM/DD")) {
				mayor = j;
			}
		}
		
		if (i != mayor) {
			aux = vec[i]; // se hace una copia del objeto 
			vec[i] = vec[mayor];
			vec[mayor] = aux;
		}
		// mayor
	}
}

void TareaManager::ListarOrdenadosPorFecha(){
	int cantidadRegistros = _archivo.getCantidadRegistros();
	Tarea *vec = new Tarea[cantidadRegistros];
	
	if (vec == nullptr){
		cout << "Error al visualizar el listado";
		return;
	}
	
	_archivo.leer(vec, cantidadRegistros);
	Ordenar(vec, cantidadRegistros);
	
	for(int i=0; i<cantidadRegistros; i++){
		Listar(vec[i]);
		cout << endl;
	}
	
	delete []vec;
	
}

void TareaManager::ListarXId()
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

void TareaManager::Listar(Tarea tarea)
{
	cout << "ID          : " << tarea.getID() << endl;
	cout << "Descripcion : " << tarea.getDescripcion() << endl;
	cout << "Fecha       : " << tarea.getFechaLimite().toString() << endl;
	cout << "Dificultad  : " << tarea.getNivelDificultad() << endl;
	cout << "Estado      : " << tarea.getDescripcionEstado() << endl;
}

void TareaManager::Editar()
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

void TareaManager::Eliminar()
{
    /*
    pedir el id
    buscarlo
    cambiar el estado
    guardarlo
    */
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
		reg.setEliminado(true);
		_archivo.guardar(reg, posicion);
		cout << "Registro #" << id << " eliminado correctamente" << endl;
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
}



bool TareaManager::ExisteId(int id)
{
    return _archivo.buscar(id) >= 0;
    /*
    if (_archivo.buscar(id) >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
}

int TareaManager::GenerarId()
{
    return _archivo.getCantidadRegistros() + 1;
    /*
    int proximoId = _archivo.getCantidadRegistros();
    proximoId++;
    return proximoId;
    */
}

void TareaManager::HacerCopiaDeSeguridad(){
	/*
		ArchivoDAT = Archivo donde trabajan las acciones del menú (Cargar, Listar, Editar)
		ArchivoBKP = Archivo de respaldo
	
		Leer todos los registros ArchivoDAT en un vector dinámico X
		Vaciar ArchivoBKP X
		Guardar todos los registros del vector en ArchivoBKP 
		
	*/
	int cantidadRegistros = _archivo.getCantidadRegistros();
	Tarea *vec = new Tarea[cantidadRegistros];
	
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

void TareaManager::RestaurarCopiaDeSeguridad(){
	/*
	ArchivoDAT = Archivo donde trabajan las acciones del menú (Cargar, Listar, Editar)
	ArchivoBKP = Archivo de respaldo
	
	Leer todos los registros ArchivoBKP en un vector dinámico
	Vaciar ArchivoDAT
	Guardar todos los registros del vector en ArchivoDAT
	
	*/
	int cantidadRegistros = _archivoBkp.getCantidadRegistros();
	Tarea *vec = new Tarea[cantidadRegistros];
	
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
