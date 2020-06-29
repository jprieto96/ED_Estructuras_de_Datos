
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "queue_eda.h"

template <class T>
class ListaInsertar : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const{
		Nodo* n = this->prim;
		while (n != nullptr) {
			o << n->elem << " ";
			n = n->sig;
		}
	}

	void insertar(ListaInsertar<T> &lista, int const & pos) {
		// Me guardo dos punteros a las primeras posiciones de las dos lista enlazadas simples
		Nodo* aux = lista.prim;
		Nodo* n = this->prim;

		// Quito los punteros prim y ult a la lista pasada por parametros para ser una lista vacia
		lista.prim = nullptr;
		lista.ult = nullptr;
		lista.nelems = 0;

		bool salir = false;
		if (pos == 0) {
			this->prim = aux; // guardo como primer nodo de la lista el primero de la lista a insertar
			while (!salir) {
				this->nelems++;
				// si hemos llegado al ultimo nodo de la lista a insertar, su siguiente lo ponemos con el primero de nuestra lista
				if (aux->sig == nullptr) { salir = true;  aux->sig = n; }
				else aux = aux->sig;
			}
		}
		else if (pos == this->nelems) {
			this->ult->sig = aux; // El siguiente del ultimo le asigno el primero de la lista a insertar
			while (aux != nullptr) {
				this->nelems++;
				this->ult = aux;
				aux = aux->sig;
			}
		}
		else {
			for (int i = 1; i <= pos; i++) {
				if (i == pos) {
					Nodo* sig = n->sig; // Me guardo el nodo al que hay que ir despues de inserar la nueva lista
					n->sig = aux;
					while (!salir) {
						this->nelems++;
						if (aux->sig == nullptr) { salir = true;  aux->sig = sig; }
						else aux = aux->sig;
					}
				}
				else n = n->sig;
			}
		}
		
	}
};template <class T>inline std::ostream& operator<<(std::ostream& salida, ListaInsertar<T>& l) {
	l.print(salida);
	return salida;
}