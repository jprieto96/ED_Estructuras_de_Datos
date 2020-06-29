#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

struct sol {
	int alturaMax = 0, alturaConRaizP = 0;
};

sol subArbolMasGrande(bintree<char> const& arbol) {
	if (arbol.empty()) return { 0, 0 };
	else {
		sol izq = subArbolMasGrande(arbol.left());
		sol der = subArbolMasGrande(arbol.right());
		sol s;
		s.alturaConRaizP = min(izq.alturaConRaizP, der.alturaConRaizP) + 1;
		s.alturaMax = max(izq.alturaMax, der.alturaMax);
		if (s.alturaConRaizP > s.alturaMax) s.alturaMax = s.alturaConRaizP;
		return s;
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	sol s = subArbolMasGrande(arbol);
	cout << s.alturaMax << '\n';
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
