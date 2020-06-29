#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <map>
using namespace std;

string toLower(string cadena) {
	for (int i = 0; i < cadena.length(); i++)
		cadena[i] = tolower(cadena[i]);
	return cadena;
}

bool resuelveCaso() {
	int n;
	string linea;
	cin >> n;
	if (n == 0) return false;
	vector<string> v(n);
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, linea);
		v[i] = linea;
	}
	map<string, vector<int>> resultado;
	for (int i = 0; i < n; ++i) {
		string palabra;
		stringstream ss(v[i]);
		while (ss >> palabra) {
			palabra = toLower(palabra);
			if (palabra.size() > 2) {
				if (!resultado.count(palabra))
					resultado[palabra].push_back(i + 1);
				else {
					vector<int> & lineas = resultado.at(palabra);
					if (i + 1 != lineas[lineas.size() - 1])
						resultado[palabra].push_back(i + 1);
				}
			}
		}
	}

	for (auto const& p : resultado) {
		cout << p.first << " ";
		for (int const& fila : p.second) {
			cout << fila << " ";
		}
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
