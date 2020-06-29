
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "deque_eda.h"

bool resuelveCaso() {
	int sobresGuardados, sobresEntregar, aux;
	cin >> sobresGuardados >> sobresEntregar;
	if (sobresGuardados == 0 && sobresEntregar == 0) return false;

	vector<int> sobres;
	deque<int> cola;
	vector<int> salida;
	for (int i = 0; i < sobresGuardados; i++) {
		cin >> aux;
		sobres.push_back(aux);
	}

	int k = 0;
	int cont = sobresEntregar;
	for (int i = 0; i < sobres.size(); i++) {
		cola.push_back(sobres[i]);
		if (k == cont - 1) {
			salida.push_back(cola.back());
			cont += sobresEntregar;
		}
		else {
			if(cola.back() > cola.front()) cola.pop_front();
		}
		++k;
	}
	
	for (int const& n : salida) cout << n << " ";
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
