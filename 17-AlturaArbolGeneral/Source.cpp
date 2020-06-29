#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

int calcularAltura() {
	int nHijos, altura = 0;
	cin >> nHijos;
	if (nHijos == 0) return 1;
	else {
		for (int i = 0; i < nHijos; ++i) {
			 altura = max(altura, calcularAltura());
		}
		return altura + 1;
	}
}

void resuelveCaso() {
	cout << calcularAltura() << '\n';
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
