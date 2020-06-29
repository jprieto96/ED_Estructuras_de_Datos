
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

struct sol {
	int tNavegables = 0, cont = 0;
};

sol resolver(bintree<int> const& arbol) {
	if (arbol.empty()) return { 0, 0 };
	if (arbol.left().empty() && arbol.right().empty()) return { 0, 1 };
	sol izq = resolver(arbol.left());
	sol der = resolver(arbol.right());
	sol s;
	s.tNavegables = izq.tNavegables + der.tNavegables;
	if (izq.cont >= 3) ++s.tNavegables;
	if (der.cont >= 3) ++s.tNavegables;
	if (arbol.root() == 0) s.cont = izq.cont + der.cont;
	else s.cont = max(0, izq.cont + der.cont - arbol.root());
	return s;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	sol s = resolver(arbol);
	cout << s.tNavegables << '\n';
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
