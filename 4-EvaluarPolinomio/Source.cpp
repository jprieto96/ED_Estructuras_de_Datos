
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "polinomio.h"

bool resuelveCaso() {
	int nCasos, aux;
	polinomio p;
	cin >> p;
	if (!cin) return false;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) {
		cin >> aux;
		cout << p.evaluarPolinomio(aux) << " ";
	}

	cout << "\n";

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
