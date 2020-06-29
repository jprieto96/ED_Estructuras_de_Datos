
// ALBERTO VERDEJO

#ifndef HORAS_H
#define HORAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument

class horas {
private:
   int HH; // las horas
   int MM; // los minutos
   int SS; // los segundos 
   bool check(int h, int m, int s) {
	   return h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
   }
public:
   // constructora
   horas(int h = 0, int m = 0, int s = 0) {
	   if (check(h, m, s)) {
		   HH = h; MM = m; SS = s;
	   }
	   else throw std::domain_error("hora invalida");
   }
   
   // observadoras
   int hora() const { return HH; }
   int minuto() const { return MM; }
   int segundo() const { return SS; }

   // operador de comparación
   bool operator<(horas const& h) const {
	   return (HH * 3600 + MM * 60 + SS) < (h.HH * 3600 + h.MM * 60 + h.SS);
   }

   bool operator==(horas const& h) const {
	   return (HH * 3600 + MM * 60 + SS) == (h.HH * 3600 + h.MM * 60 + h.SS);
   }

   // operador de suma
   horas operator+(horas const& h) const {
	   horas aux(HH, MM, SS);
	   aux.SS += h.SS;
	   if (aux.SS >= 60) {
		   aux.SS -= 60; aux.MM++;
	   }
	   aux.MM += h.MM;
	   if (aux.MM >= 60) {
		   aux.MM -= 60; aux.HH++;
	   }
	   aux.HH += h.HH;
	   if(aux.HH >= 24) throw std::domain_error("Se excede del dia actual");
	   return aux;
   }

   void read(std::istream & input = std::cin) {
	   int h, m, s; char c;
	   input >> h >> c >> m >> c >> s;
	   if (check(h, m, s)) {
		   HH = h; MM = m; SS = s;
	   }
	   else throw std::domain_error("hora invalida");
   }
   void print(std::ostream& o = std::cout) const {
      o << std::setfill('0') << std::setw(2) << HH << ':'
        << std::setfill('0') << std::setw(2) << MM << ':'
        << std::setfill('0') << std::setw(2) << SS;
   }
};

inline std::ostream & operator<<(std::ostream & salida, horas const& h) {
   h.print(salida);
   return salida;
}

inline std::istream & operator>>(std::istream & entrada, horas & h) {
   h.read(entrada);
   return entrada;
}

#endif
