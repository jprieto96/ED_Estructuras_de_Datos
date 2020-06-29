
// ALBERTO VERDEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"
#include "peliculas.h" 

bool resuelveCaso() {
	int nPeliculas;
	cin >> nPeliculas;
	if (nPeliculas == 0) return false;

	vector<peliculas> pelis(nPeliculas);
	for (peliculas &p : pelis)
		cin >> p;

	sort(pelis.begin(), pelis.end());

	for (peliculas const& p : pelis) {
		p.print();
		std::cout << "\n";
	}

	cout << "---\n";

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
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
