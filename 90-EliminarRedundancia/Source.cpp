#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

bool resuelveCaso() {
	int nCasos, valor;
	cin >> nCasos;
	if (!cin) return false;

	unordered_map<int, pair<int, int>> resultados;
	for (size_t i = 0; i < nCasos; i++) {
		cin >> valor;
		if(!resultados.count(valor)) resultados[valor].second = i;
		resultados[valor].first++;
	}

	map<int, pair<int, int>> v;
	for(pair<int, pair<int, int>> const & p : resultados) {
		v[p.second.second] = { p.first, p.second.first };
	}

	for(pair<int, pair<int, int>> const & p : v) {
		cout << p.second.first << " " << p.second.second << '\n';
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
