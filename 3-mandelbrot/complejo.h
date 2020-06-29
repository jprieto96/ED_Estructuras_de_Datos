#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <math.h>

template<class T>
class complejo {
private:
	T parte_real, parte_imaginaria;
public:
	// constructora
	complejo(const T & r = 0, const T & i = 0) {
		parte_real = r;
		parte_imaginaria = i;
	}

	T calcularModulo() const{
		return sqrt((parte_real * parte_real) + (parte_imaginaria * parte_imaginaria));
	}

	complejo operator+(complejo const& c) const {
		return { parte_real + c.parte_real, parte_imaginaria + c.parte_imaginaria };
	}

	complejo operator*(complejo const& c) const {
		return { (parte_real * c.parte_real) - (parte_imaginaria * c.parte_imaginaria), 
			(parte_real * c.parte_imaginaria) + (c.parte_real * parte_imaginaria) };
	}

	void read(std::istream& input = std::cin) {
		input >> parte_real >> parte_imaginaria;
	}
};

template<class T>
inline std::istream& operator>>(std::istream& entrada, complejo<T>& c) {
	c.read(entrada);
	return entrada;
}

#endif
