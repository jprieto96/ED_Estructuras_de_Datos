#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <sstream> 
using namespace std;

#include "bintree_eda.h"

// Reconstruccion del arbol pero que en el caso peor tendria O(n²)
bintree<int> reconstruccionArbol(vector<int> const& preorden, vector<int> const& inorden, int a, int b, int c, int d) {
	if (a > b) 
		return {};

	int raiz = preorden[a];
	int raizInorden = c;
	while(inorden[raizInorden] != raiz)
		++raizInorden;

	auto izq = reconstruccionArbol(preorden, inorden, a + 1, a + raizInorden - c, c, raizInorden - 1);
	auto der = reconstruccionArbol(preorden, inorden, a + raizInorden - c + 1, b, raizInorden + 1, d);
	return { izq, raiz, der };
}

// Reconstruccion del arbol pero que en el caso peor tendria O(n)
bintree<int> reconstruccionArbolOptimizada(vector<int> const& preorden, vector<int> const& inorden, int &i, int &j, int tope) {
	if(i == preorden.size() || inorden[j] == tope) return {};
	int raiz = preorden[i];
	++i;
	auto izq = reconstruccionArbolOptimizada(preorden, inorden, i, j, raiz);
	++j;
	auto der = reconstruccionArbolOptimizada(preorden, inorden, i, j, tope);
	return { izq, raiz, der };
}

bool resuelveCaso() {
	string linea;
	vector<int> preorden;
	vector<int> inorden;
	if (!getline(cin, linea)) return false;
	stringstream ssPre(linea);
	int valor;
	while (ssPre >> valor) {
		preorden.push_back(valor);
	}
	getline(cin, linea);
	stringstream ssIn(linea);
	while (ssIn >> valor) {
		inorden.push_back(valor);
	}
	int i = 0, j = 0;
	bintree<int> arbol = reconstruccionArbolOptimizada(preorden, inorden, i, j, -1);
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
