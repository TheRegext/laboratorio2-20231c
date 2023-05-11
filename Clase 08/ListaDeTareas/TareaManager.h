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

	void Listar(Tarea tarea);

private:
	TareaArchivo _archivo;

	bool ExisteId(int id);
	int GenerarId();
};

#endif

