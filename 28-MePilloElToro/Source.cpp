#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
using namespace std;

map<string, int> obtenerResultados(int n) {
	string nombre, ejercicio;
	map<string, int> resultados;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		getline(cin, nombre);
		cin >> ejercicio;
		if (ejercicio == "INCORRECTO")
			--resultados[nombre];
		else
			++resultados[nombre];
	}
	return resultados;
}

bool resuelveCaso() {
	int nCasos;
	cin >> nCasos;
	if (nCasos == 0) return false;
	map<string, int> resultados = obtenerResultados(nCasos);
	for (pair<string, int> const& p : resultados) {
		if(p.second != 0)
			cout << p.first << ", " << p.second << '\n';
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
