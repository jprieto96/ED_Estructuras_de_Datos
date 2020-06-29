
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const{
		Nodo* n = this->prim;
		while (n != nullptr) {
			o << n->elem << " ";
			n = n->sig;
		}
	}
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		Nodo* n = this->prim;
		while (n != nullptr) {
			Nodo* add = new Nodo(n->elem, n->sig);
			n->sig = add;
			n = add->sig;
			this->ult = add;
			++this->nelems;
		}
	}
};template <class T>inline std::ostream& operator<<(std::ostream& salida, ListaDuplica<T>& l) {
	l.print(salida);
	return salida;
}