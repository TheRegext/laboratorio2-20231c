#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>

class Fecha{
   private:
   int _dia, _mes, _anio;

   void establecerFechaPorDefecto();
   bool esBisiesto();
   void agregarDia();

   public:
      Fecha();
      Fecha(int dia, int mes, int anio);

      int getDia();
      int getMes();
      int getAnio();
      void agregarDias(int cantidadDias);
      std::string toString(std::string formatoFecha = "DD/MM/YYYY");
};

#endif // FECHA_H_INCLUDED
