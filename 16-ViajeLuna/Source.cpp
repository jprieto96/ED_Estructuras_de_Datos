
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "ListaFiltrar.h"

class Persona {
private:
	int edad;
	string nombre;
public:
	Persona() : edad(0), nombre("") {}
	Persona(int _edad, string _nombre) : edad(_edad), nombre(_nombre) {}

	int getEdad() { return edad; }

	void read(istream& input = cin) {
		input >> edad;
		getline(input, nombre);
	}

	void print(ostream& c = cout) const{
		c << nombre;
	}
};

inline istream & operator>>(istream& entrada, Persona & p) {
	p.read();
	return entrada;
}

inline ostream& operator<<(ostream& salida, Persona const& p) {
	p.print();
	return salida;
}

template <class T>
class Predicate {
private:
	T min, max;
public:
	Predicate(T _min, T _max) : min(_min), max(_max) {}

	bool notValid(T elem) {
		return elem <= min || elem >= max;
	}
};

bool resuelveCaso() {
	int nPersonas, min, max;
	cin >> nPersonas >> min >> max;
	if (nPersonas == 0 && min == 0 && max == 0) return false;

	ListaFiltrar<Persona> lista;
	Persona aux;
	for (int i = 0; i < nPersonas; i++) {
		cin >> aux;
		lista.push_back(aux);
	}

	Predicate p(min, max);
	lista.removeIf(p);

	while (!lista.empty()) {
		cout << lista.front(); 
		lista.pop_front();
	}

	return true;
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
