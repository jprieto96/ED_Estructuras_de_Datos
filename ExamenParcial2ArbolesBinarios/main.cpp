
// JOSE RAMON PRIETO DEL PRADO (E56)

/*
    Para calcular si un arbol es diestro vamos a recorrer recursivamente
    el arbol nodo a nodo y vamos a llevar para cada nodo un booleano y 
    la suma(hasta ese momento) de su hijo izquierdo y su hijo derecho.
    Los casos base serian:
    - Si es un arbol vacio es diestro y la suma es 0
    - Si es una hoja tambien es diestro y la suma es el elemento de la hoja

    Se llama recursivamente al arbol (hijo izquiero e hijo derecho)
    y con los datos que devuelven calculamos los nuevos datos de la siguiente
    manera:
    - Si el hijo izquierdo es diestro, el hijo derecho es diestro y la suma
    del hijo derecho es mayor que la suma del hijo izquierdo, el arbol es diestro
    - La suma la calculamos sumando las sumas de ambos hijos(izquierdo y derecho)
    con el elemento de la raiz del arbol

    Coste del algoritmo:

            { k0 si n = 0 Caso base de arbol vacio
    T(n) =	{ k1 si n = 1 Caso base de nodo hoja
            { T(nizq) + T(nder) + k0 si n > 1 y se recorren los dos hijos

        n = numero de elementos o nodos del arbol

    ->	Por lo que deducimos que el coste del algoritmo
        es lineal - O(n) ya que se recorren todos los
        nodos del arbol y las operaciones realizadas con ellos son
        constantes - O(1) por lo que el coste total del algoritmo
        es lineal - O(n)
*/


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


struct sol {
    bool diestro = false;
    int suma = 0;
};

sol esDiestro(bintree<int> const& arbol) {
    if (arbol.empty()) // Si es un arbol vacio
        return { true, 0 };
    if (arbol.left().empty() && arbol.right().empty()) // Si es una hoja
        return { true, arbol.root() };
    sol izq = esDiestro(arbol.left()); // Llamo al hijo izquierdo
    sol der = esDiestro(arbol.right()); // Llamo al hijo derecho

    // Si el hijo izquierdo es diestro, el hijo derecho es diestro
    // y la suma de todos los nodos del hijo derecho es mayor que la suma
    // de todos los nodos del hijo izquierdo el arbol es diestro
    // Luego calculamos la suma actual sumando
    // la suma acumulada del hijo izq + la suma acumulada del hijo derecho +
    // el elemento de la raiz del arbol
    return { izq.diestro && der.diestro && der.suma > izq.suma,
               izq.suma + der.suma + arbol.root() };
}

bool diestro(bintree<int> const& arbol) {
    return esDiestro(arbol).diestro;
}

void resuelveCaso() {
    auto arbol = leerArbol(-1);
    if (diestro(arbol))
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
