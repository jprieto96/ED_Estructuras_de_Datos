#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

void perfilIzq(bintree<int> const& arbol, vector<int> &sol, int alt, int &altMax) {
	if (arbol.empty()) return;
	++alt;
	if(alt > altMax) {
		altMax = alt;
		sol.push_back(arbol.root());
	} 
	perfilIzq(arbol.left(), sol, alt, altMax);
	perfilIzq(arbol.right(), sol, alt, altMax);
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	vector<int> sol;
	int altMax = 0;
	perfilIzq(arbol, sol, 0, altMax);
	for (int const& n : sol) cout << n << " ";
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
