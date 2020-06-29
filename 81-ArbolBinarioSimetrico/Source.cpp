
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

bool simetrico(bintree<char> const& izq, bintree<char> const& der) {
	if (izq.empty() && der.empty()) return true;
	if (!izq.empty() && !der.empty()) return simetrico(izq.left(), der.right()) && simetrico(izq.right(), der.left());
	return false;
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	if (simetrico(arbol.left(), arbol.right())) cout << "SI\n";
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
