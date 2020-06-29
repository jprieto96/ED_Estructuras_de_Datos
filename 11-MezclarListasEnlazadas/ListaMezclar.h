
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "queue_eda.h"

template <class T>
class ListaMezclar : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const{
		Nodo* n = this->prim;
		while (n != nullptr) {
			o << n->elem << " ";
			n = n->sig;
		}
	}

	// O(n) -> Orden lineal siendo n la suma del tamaño de las dos colas
	// Los otros dos bucles solo se encargan de terminar de "vaciar" cada una de las listas por lo que no supondria un coste superior adicional
	void mezclar(ListaMezclar<T> &lista) {
		Nodo* l1 = this->prim;
		Nodo* l2 = lista.prim;
		Nodo* sort = nullptr;

		// Si la lista recibida por parametros esta vacia dejamos la lista this tal cual esta
		if (lista.nelems == 0) return;

		// Inicializamos sort como el nodo en el que guardaremos el ultimo nodo ordenado
		if (this->nelems > 0 && lista.nelems > 0) { 
			if (l1->elem <= l2->elem) {
				sort = l1;
				this->prim = l1;
				l1 = sort->sig;
			}
			else {
				sort = l2;
				this->prim = l2;
				l2 = sort->sig;
			}
		}
		

		if (this->empty()) { // Caso de lista this vacia
			this->prim = lista.prim;
			this->ult = lista.ult;
		}
		else {
			while (l1 != nullptr && l2 != nullptr) { // n veces siendo n el la suma del tamaño de las colas this y la pasada por parametros
				if (l1->elem <= l2->elem) {
					sort->sig = l1;
					sort = l1;
					this->ult = l1;
					l1 = sort->sig;
				}
				else {
					sort->sig = l2;
					sort = l2;
					this->ult = l2;
					l2 = sort->sig;
				}
			}

			while (l1 != nullptr) { // checkeamos por si queda algo en la lista this despues del while principal
				sort->sig = l1;
				sort = l1;
				this->ult = l1;
				l1 = sort->sig;
			}

			while (l2 != nullptr) { // checkeamos por si queda algo en la lista por parametros despues del while principal
				sort->sig = l2;
				sort = l2;
				this->ult = l2;
				l2 = sort->sig;
			}

		}
		
		// Suma del tamaño de las dos colas
		this->nelems += lista.nelems;

		//Dejamos la lista que recibimos por parametros vacia
		lista.prim = nullptr;
		lista.ult = nullptr;
		lista.nelems = 0;
	}
};template <class T>inline std::ostream& operator<<(std::ostream& salida, ListaMezclar<T>& l) {
	l.print(salida);
	return salida;
}