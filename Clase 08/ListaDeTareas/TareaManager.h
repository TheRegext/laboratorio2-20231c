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

	void Listar(Tarea tarea);

private:
	TareaArchivo _archivo;
};

#endif
