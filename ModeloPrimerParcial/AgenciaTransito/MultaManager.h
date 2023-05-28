#ifndef MultaMANAGER_H
#define MultaMANAGER_H
#include "Multa.h"
#include "MultaArchivo.h"

class MultaManager {
public:
  void Cargar();
  void ListarTodos();
  void ListarXId();
  void Listar(Multa Multa);
  void HacerCopiaDeSeguridad();
  void RestaurarCopiaDeSeguridad();
  
private:
  MultaArchivo _archivo;
  MultaArchivo _archivoBkp = MultaArchivo("Multas.bkp");
  
  bool ExisteId(int id);
  int GenerarId();
};

#endif

