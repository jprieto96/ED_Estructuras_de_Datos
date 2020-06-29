#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "set_eda.h"

bool resuelveCaso() {
	int n, m, aux;
	set<int> c;
	vector<int> v;
	cin >> n;
	if (n == 0) return false;
	for (int i = 0; i < n; i++){
		cin >> aux;
		c.insert(aux);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	pair<bool, int> pair;
	for (int const& n : v) {
		pair = c.lower_bound(n);
		if (pair.first) cout << pair.second;
		else cout << "NO HAY";
		cout << '\n';
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
