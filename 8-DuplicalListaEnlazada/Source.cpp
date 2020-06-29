
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "ListaDuplica.h"


bool resuelveCaso() {
	ListaDuplica<int> l;
	int aux;
	cin >> aux;
	if (!cin) return false;
	while (aux != 0) {
		l.push(aux);
		cin >> aux;
	}

	l.duplica();

	// dar una vuelta completa (la cola debería quedarse igual)
	for (int i = 0; i < l.size(); ++i) {
		int elem = l.front(); l.pop();
		l.push(elem);
	}

	cout << l <<'\n';
	
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
