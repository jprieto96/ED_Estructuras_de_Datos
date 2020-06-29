
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "complejo.h"

void resuelveCaso() {
	complejo<float> c, z(0, 0);
	bool ok = true;
	int iteraciones;

	cin >> c >> iteraciones;

	for (int i = 1; i < iteraciones; i++) {
		if (z.calcularModulo() > 2) { ok = false; i = iteraciones; }
		else z = (z * z) + c;
	}

	if (ok) cout << "SI\n";
	else cout << "NO\n";
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
