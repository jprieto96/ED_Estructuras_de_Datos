
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_ext.h"

void resuelveCaso() {
	bintree_ext<int> arbol = leerArbol_ext(-1);
	std::vector<int> v;
	arbol.frontera(v);
	for (int const& n : v) cout << n << " ";
	cout << '\n';
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
