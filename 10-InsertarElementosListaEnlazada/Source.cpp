
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "ListaInsertar.h"


bool resuelveCaso() {
	int pos, nL1, nL2, aux;
	ListaInsertar<int> l1, l2;
	cin >> nL1;
	if (!cin) return false;
	for (int i = 0; i < nL1; i++) {
		cin >> aux;
		l1.push(aux);
	}

	cin >> nL2 >> pos;
	for (int i = 0; i < nL2; i++) {
		cin >> aux;
		l2.push(aux);
	}

	l1.insertar(l2, pos);

	// dar una vuelta completa (la cola debería quedarse igual)
	for (int i = 0; i < l1.size(); ++i) {
		int elem = l1.front(); l1.pop();
		l1.push(elem);
	}

	cout << l1 << '\n';

	return true;
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
