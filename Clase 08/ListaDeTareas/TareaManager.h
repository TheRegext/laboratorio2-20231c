#ifndef TAREAMANAGER_H
#define TAREAMANAGER_H
#include "Tarea.h"
#include "TareaArchivo.h"

class TareaManager {
public:
	void Cargar();
	void ListarTodos();
	void ListarXId();
	void Editar();
	void Eliminar();
	void ListarOrdenadosPorFecha();
	void Listar(Tarea tarea);
	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

private:
	TareaArchivo _archivo;
	TareaArchivo _archivoBkp = TareaArchivo("tareas.bkp");

	void Ordenar(Tarea *vec, int cantidadRegistros);
	bool ExisteId(int id);
	int GenerarId();
};

#endif

