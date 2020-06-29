
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

int diametro(bintree<char> const& arbol, int & maxD) {
	if (arbol.empty()) return 0;
	else {
		int izq = diametro(arbol.left(), maxD);
		int der = diametro(arbol.right(), maxD);
		if (izq + der + 1 > maxD) maxD = izq + der + 1;
		return 1 + max(izq, der);
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int maxD = 0;
	diametro(arbol, maxD);
	cout << maxD << '\n';
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
