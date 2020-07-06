
// JOSE RAMON PRIETO DEL PRADO (E56)

// El coste de particion es O(n) y de print tambien es O(n)
// ya que en ambos se recorre n veces siendo n el numero de
// nodos de la cola doble y en cada paso del recorrido se realizan
// operaciones constantes con cada nodo

/*
    Utilizo tres nodos, uno para saber cual es el nodo anterior(aux)
    otro el actual(n) y otro para el siguiente(s), entonces recorro 
    la cola n veces siendo el numero de elementos de la cola.
    Si el elemento del nodo apuntado por n es mayor que el pivote
    traslado este nodo al final de la cola, haciendo que su anterior
    sea el anterior del fantasma y que su siguiente sea el fantasma.
    (Obviamente tambien modifico los anterior y siguiente de fantasma y del
    nodo que antes era el ultimo)
    Si el elemento de la cola no es mayor que el pivote unicamente voy avanzando los punteros
    alrededor de la cola

*/


#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
public:
    void print(std::ostream& o = std::cout) const {
        Nodo* n = this->fantasma->sig;
        if (n == nullptr) return;
        while (n != this->fantasma) {
            o << n->elem << " ";
            n = n->sig;
        }
    }

    // produce la partición de la lista respecto al privote
    void particion(int pivote) {
        if (this->nelems <= 1) return;
        Nodo* aux = this->fantasma;
        Nodo* n = aux->sig;
        Nodo* s = n->sig;
        int i = 0; 
        while (i < this->nelems) { // recorro n veces siendo n el tamaño de la lista doble enlazada
            if (n->elem > pivote) {
                aux->sig = s;
                s->ant = aux;

                // Aqui lo que hago es basicamente mandar el nodo
                // que es mayor que el pivote al final de la cola
                n->ant = this->fantasma->ant;
                this->fantasma->ant->sig = n;
                this->fantasma->ant = n;
                n->sig = this->fantasma;
                n = aux->sig;

                s = n->sig;
            }
            else {
                aux = n;
                n = n->sig;
                s = n->sig;
            }
            ++i;
        }
    }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada
inline std::ostream& operator<<(std::ostream& o, ListaParticion const& a) {
    a.print(o);
    return o;
}

bool resuelveCaso() {
    int N, pivote;
    cin >> N >> pivote;
    if (!cin)
        return 0;

    ListaParticion lista;
    // leemos la lista de la entrada
    int elem;
    for (int i = 0; i < N; ++i) {
        cin >> elem;
        lista.push_back(elem);
    }


    lista.particion(pivote);

    cout << lista.front() << " " << lista.back() << '\n';

    cout << lista << '\n';

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
    // system("PAUSE");
#endif
    return 0;
}
