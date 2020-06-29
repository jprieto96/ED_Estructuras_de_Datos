#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

void resuelveCaso() {
	map<string, unsigned int> dAntiguo, dNuevo;
	vector<vector<string>> cambios(3);
	string linea, key;
	int value;

	// leer datos diccionario antiguo
	getline(cin, linea);
	stringstream dicAnt(linea);
	while (dicAnt >> key >> value) {
		dAntiguo[key] = value;
	}

	// leer datos diccionario nuevo
	getline(cin, linea);
	stringstream dicNuevo(linea);
	while (dicNuevo >> key >> value) {
		dNuevo[key] = value;
	}

	for (pair<string, unsigned int> const& p : dNuevo) {
		if (dAntiguo.count(p.first)) {
			if (dAntiguo.at(p.first) != dNuevo.at(p.first)) {
				cambios[2].push_back(p.first); // 2 representa el *
			}
		}
		else {
			cambios[0].push_back(p.first); // 0 representa el +
		}
	}

	for (pair<string, unsigned int> const& p : dAntiguo) {
		if (!dNuevo.count(p.first)) {
			cambios[1].push_back(p.first); // 1 representa el -
		}
	}

	if (cambios[0].empty() && cambios[1].empty() && cambios[2].empty()) cout << "Sin cambios\n";
	else {
		for (int i = 0; i < cambios.size(); ++i) {
			if (!cambios[i].empty()) {
				if (i == 0) cout << '+' << " ";
				else if (i == 1)  cout << '-' << " ";
				else cout << '*' << " ";
				for (string const& s : cambios[i])
					cout << s << " ";
				cout << '\n';
			}
		}
	}
	
	cout << "---\n";
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nCasos;
	cin >> nCasos;
	cin.ignore();
	for (int i = 0; i < nCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
