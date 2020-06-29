
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "ListaMezclar.h"


void resuelveCaso() {
	int aux;
	ListaMezclar<int> l1, l2;
	
	cin >> aux;
	while (aux != 0) {
		l1.push(aux);
		cin >> aux;
	}

	cin >> aux;
	while (aux != 0) {
		l2.push(aux);
		cin >> aux;
	}

	l1.mezclar(l2);

	// dar una vuelta completa (la cola debería quedarse igual)
	for (int i = 0; i < l1.size(); ++i) {
		int elem = l1.front(); l1.pop();
		l1.push(elem);
	}

	cout << l1 << '\n';
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
