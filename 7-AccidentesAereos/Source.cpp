
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
using accidentes = pair<string, int>;

#include "stack_eda.h"

/*
	O(n) -> el bucle principal es de O(n) y el interno como mucho es tambien de O(n) asi que -> O(n) + O(n) = O(n)
*/
bool resuelveCaso() {
	int nCasos;
	cin >> nCasos;
	if (!cin) return false;

	vector<accidentes> v(nCasos);
	stack<accidentes> pila;
	for (pair<string, int> &a : v)
		cin >> a.first >> a.second;

	pila.push(v[0]);
	cout << "NO HAY\n";
	for (int i = 1; i < v.size(); i++) { // n vueltas siendo n el tamaño del vector de accidentes
		while (!pila.empty() && pila.top().second <= v[i].second) // Como maximo hacemos n pops siendo n el tamaño del vector de accidentes
			pila.pop();

		if (!pila.empty())
			cout << pila.top().first << '\n';
		else
			cout << "NO HAY\n";

		pila.push(v[i]);
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
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
