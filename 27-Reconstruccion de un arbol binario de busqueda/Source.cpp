#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <sstream> 
using namespace std;

#include "bintree_eda.h"

bintree<int> reconstruccionArbol(vector<int> const& preorden, int a, int b) {
	if(a > b) return {};
	int raiz = preorden[a];
	++a;
	int i = a;
	while(i < preorden.size() && preorden[i] <= raiz)
		++i;
	auto izq = reconstruccionArbol(preorden, a, i - 1);
	auto der = reconstruccionArbol(preorden, i, b);
	return { izq, raiz, der };
}

bool resuelveCaso() {
	string linea;
	vector<int> preorden;
	if (!getline(cin, linea)) return false;
	stringstream ssPre(linea);
	int valor;
	while (ssPre >> valor) {
		preorden.push_back(valor);
	}

	bintree<int> arbol = reconstruccionArbol(preorden, 0, preorden.size() - 1);
	vector<int> arbolPostOrden = arbol.postorder();
	for (int const& n : arbolPostOrden) cout << n << " ";
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
