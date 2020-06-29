
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "queue_eda.h"

template <class T>
class queue_ext : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const{
		Nodo* n = this->prim;
		while (n != nullptr) {
			o << n->elem << " ";
			n = n->sig;
		}
	}
	// eliminar uno de cada dos
	void eliminarUnoDeCadaDos() {
		Nodo* n = this->prim;
		Nodo* aux = nullptr;
		while (n != nullptr && n->sig != nullptr) {
			aux = n->sig;
			n->sig = aux->sig;
			delete aux;
			if (this->nelems % 2 == 0) this->ult = n;
			n = n->sig;
		}

		if (this->nelems % 2 == 0) this->nelems /= 2;
		else this->nelems = (this->nelems / 2) + 1;
	}
};template <class T>inline std::ostream& operator<<(std::ostream& salida, queue_ext<T>& l) {
	l.print(salida);
	return salida;
}