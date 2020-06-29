#ifndef PELICULAS_H
#define PELICULAS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include "horas.h"

class peliculas {
private:
	horas hora_comienzo;
	horas duracion;
	horas hora_fin;
	std::string nombre;

public:
	peliculas(horas hc = NULL , horas d = NULL, std::string n = " ") {
		nombre = n;
		hora_comienzo = hc;
		duracion = d;
		hora_fin = hora_comienzo + duracion;
	}

	// observadoras
	horas horaFin() const { return hora_fin; }

	bool operator<(peliculas const& p) const {
		return hora_fin < p.hora_fin || (hora_fin == p.hora_fin) && nombre < p.nombre;
	}

	void read(std::istream & input = std::cin) {
		hora_comienzo.read();
		duracion.read();
		hora_fin = hora_comienzo + duracion;
		char arr[50];
		input.getline(arr, 50);
		nombre = arr;
	}

	void print(std::ostream& o = std::cout) const {
		hora_fin.print();
		o << " " << nombre;
	}

};

inline std::ostream& operator<<(std::ostream& salida, peliculas const& p) {
	p.print(salida);
	return salida;
}

inline std::istream& operator>>(std::istream& entrada, peliculas & p) {
	p.read(entrada);
	return entrada;
}

#endif
