
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "queue_ext.h"
#include "horas.h"

bool resuelveCaso() {
	int nCasos;
	horas aux;
	cin >> nCasos;
	if (nCasos == 0) return false;

	queue_ext<horas> h;
	for (int i = 0; i < nCasos; i++) {
		cin >> aux;
		h.push(aux);
	}

	h.eliminarUnoDeCadaDos();
	h.print();
	cout << '\n';

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
