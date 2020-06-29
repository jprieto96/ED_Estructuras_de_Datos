
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

struct sol {
	int eRescate = 0, nExcursionistas = 0;
};

sol resolver(bintree<int> const& arbol) {
	if (arbol.empty()) return { 0, 0 };
	else {
		sol izq = resolver(arbol.left());
		sol der = resolver(arbol.right());
		sol s;
		if (izq.eRescate + der.eRescate == 0 && arbol.root() > 0) s.eRescate = 1;
		else s.eRescate = izq.eRescate + der.eRescate;
		s.nExcursionistas = arbol.root() + max(izq.nExcursionistas, der.nExcursionistas);
		return s;
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	sol s = resolver(arbol);
	cout << s.eRescate << " " << s.nExcursionistas << '\n';
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
