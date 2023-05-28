#ifndef ESTADISTICAAGENTE_H
#define ESTADISTICAAGENTE_H
#include <string>

class EstadisticaAgente{
public:
  void Inicializar(int IDAgente, std::string Apellidos, std::string Nombres);
  void Acumular(float totalAAcumular);
  void ContarMulta();
  std::string toString();
  std::string getApellidos();
  std::string getNombres();
  
private:
  int _IDAgente;
  std::string _apellidos;
  std::string _nombres;
  int _cantMultas;
  float _totalAcumulado;
};

#endif

