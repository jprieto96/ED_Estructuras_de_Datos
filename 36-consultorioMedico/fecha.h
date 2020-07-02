#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument

class fecha {
public:

   int dia; 
   int hora; 
   int minuto; 

   // constructora
   fecha(int dia = 0, int hora = 0, int minuto = 0) {
	   this->dia = dia;
      this->hora = hora;
      this->minuto = minuto;
   }

   bool operator<(fecha const& f) const {
      if(dia < f.dia) return true;
      if(dia == f.dia) {
         if(hora < f.hora) return true;
         if(hora == f.hora) return minuto < f.minuto;
      }
      return false;
   }

   bool operator==(fecha const& f) const {
      return dia == f.dia && hora == f.hora && minuto == f.minuto;
   }

   void read(std::istream & input = std::cin) {
	   int d, h, m; char c;
	   input >> d >> h >> c >> m;
	   dia = d; hora = h; minuto = m;
   }

   void print(std::ostream& o = std::cout) const {
      o << std::setfill('0') << std::setw(2) << hora << ':'
        << std::setfill('0') << std::setw(2) << minuto;
   }
};

inline std::ostream & operator<<(std::ostream & salida, fecha const& f) {
   f.print(salida);
   return salida;
}

inline std::istream & operator>>(std::istream & entrada, fecha & f) {
   f.read(entrada);
   return entrada;
}

#endif
