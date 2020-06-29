
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>  // invalid_argument

#include "list_eda.h"

template <class T>
class ListaFiltrar : public list<T> {
	using Nodo = typename list<T>::Nodo; // para poder usar Nodo aquí
public:
	template<class Predicate>
	void removeIf(Predicate pred) {
		Nodo* p = this->fantasma->sig;
		while (p != this->fantasma) {
			Nodo* sig = p->sig;
			if (pred.notValid(p->elem)) this->borra_elem;
			p = sig;
		}
	}
};