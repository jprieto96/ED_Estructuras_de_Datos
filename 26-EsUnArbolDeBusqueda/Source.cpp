#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

bool esUnArbolDeBusqueda(bintree<int> const& arbol) {
	if (arbol.empty()) return true;
	vector<int> v = arbol.inorder();
	bool ok = true;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] >= v[i + 1]) ok = false;
	}
	return ok;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	if (esUnArbolDeBusqueda(arbol)) cout << "SI\n";
	else cout << "NO\n";
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
