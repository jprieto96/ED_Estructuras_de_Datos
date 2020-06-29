
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "queue_eda.h"

template <class T>
class ListaInvertir : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const{
		Nodo* n = this->prim;
		while (n != nullptr) {
			o << n->elem << " ";
			n = n->sig;
		}
	}

	// Orden lineal -> O(n) siendo n el tamaño de la cola
	// invertir los nodos de una lista enlazada simple
	void invertir() {
		Nodo* n = this->prim;
		Nodo* inverso = nullptr;
		while (n != nullptr) { // n veces siendo n el tamaño de la cola
			Nodo* ref = n;
			n = n->sig;
			ref->sig = inverso;
			inverso = ref;
		}
		this->ult = this->prim;
		this->prim = inverso;
	}
};template <class T>inline std::ostream& operator<<(std::ostream& salida, ListaInvertir<T>& l) {
	l.print(salida);
	return salida;
}