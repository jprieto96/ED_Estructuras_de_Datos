
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_ext.h"

bool resuelveCaso() {
	string tipo;
	cin >> tipo;
	if (!cin) return false;
	if (tipo == "N") {
		bintree_ext<int> arbol = leerArbol_ext(-1);
		cout << arbol.minimo();
	}
	else {
		string o = "#";
		bintree_ext<string> arbol = leerArbol_ext(o);
		cout << arbol.minimo();
	}
	cout << '\n';
	return true;
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
