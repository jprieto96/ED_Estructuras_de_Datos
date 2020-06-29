//Jose Ramon Prieto del Prado
//Pablo Morientes Lavin


//Complejidad del algoritmo: O(n) siendo n el numero de elementos de la cola
#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <typename T>
class listaPlus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void modifica() {
		if (this->nelems > 1) {
			Nodo* n = this->prim;
			Nodo* m = n->sig;
			Nodo* aux = nullptr;
			this->prim = m;
			while (n != nullptr && m != nullptr) {
				n->sig = m->sig;
				m->sig = n;
				if (aux != nullptr) aux->sig = m;
				aux = n;
				n = n->sig;
				if (n != nullptr) m = n->sig;
				else this->ult = aux;
				
			}
		}
    }

    void print() const {
		Nodo* p = this->prim;
		while (p != nullptr) {
			cout << p->elem << " ";
			p = p->sig;
		}
		cout << '\n';
    }
};



bool resuelveCaso() {
    int numElem;
    std::cin >> numElem;
    if (numElem == 0)
        return false;

    listaPlus<int> l;
    int p;
    for (int i = 0; i < numElem; ++i) {
        cin >> p;
        l.push(p);
    }

    l.modifica();

	for (int i = 0; i < l.size(); i++)
	{
		int elem = l.front(); l.pop();
		l.push(elem);
	}

    l.print();

    return true;
}



int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
