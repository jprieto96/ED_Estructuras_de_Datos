#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

struct sol {
	bool completo = false, semicompleto = false;
	int altura = 0;
};

sol completoOrSemicompleto(bintree<char> const& arbol) {
	if (arbol.empty()) return { true, true, 0 };
	else {
		sol izq = completoOrSemicompleto(arbol.left());
		sol der = completoOrSemicompleto(arbol.right());
		sol s;
		s.altura = max(izq.altura, der.altura) + 1;
		if (izq.completo && der.completo && izq.altura == der.altura) {
			s.completo = true;
			s.semicompleto = true;
		}
		else if ((izq.completo && der.completo && izq.altura == der.altura) || 
			(izq.altura == der.altura && izq.completo && der.semicompleto) || 
			(izq.altura - 1 == der.altura && izq.semicompleto && der.completo)) {
			s.semicompleto = true;
			s.completo = false;
		}
		else {
			s.semicompleto = false;
			s.completo = false;
		}
		return s;
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	sol s = completoOrSemicompleto(arbol);
	if (!s.completo && !s.semicompleto) cout << "NADA";
	else if (!s.completo) cout << "SEMICOMPLETO";
	else cout << "COMPLETO";
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
