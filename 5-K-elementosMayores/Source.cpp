
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "set.h"

bool resuelveCaso() {
	string tipo;
	set<string> s;
	vector<int> vn;
	int k;
	cin >> tipo;
	if (!cin) return false;
	cin >> k;

	if (tipo == "P") {
		vector<string> vs;
		string aux;
		cin >> aux;
		while (aux != "FIN") {
			vs.push_back(aux);
			cin >> aux;
		}
		sort(vs.begin(), vs.end(), std::greater<int>());
		for (int i = 0; i < vs.size(); i++) {
			s.insert(vs[i]);
		}
	}
	else if (tipo == "N") {
		set<int> n;
		int aux;
		cin >> aux;
		while (aux != -1) {
			vn.push_back(aux);
			cin >> aux;
		}
		sort(vn.begin(), vn.end(), std::greater<int>());
		for (int i = 0; i < vn.size(); i++) {
			n.insert(vn[i]);
		}
	}

	


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
