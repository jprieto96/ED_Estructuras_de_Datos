#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <unordered_map>
#include <map>

using namespace std;

// n -> numero de instrucciones
void resuelveCaso() {
	map<int, pair<string, int>> instrucciones; // Arbol binario de busqueda equilibrado
	unordered_map<int, int> instNuevaLinea; // Tablas con listas de nodos, coste dependiente del factor de carga
	int nLinea, referencia, nuevaLinea = 10;
	string inst;
	cin >> nLinea;

	// O(n log n)
	while(nLinea != 0) { // O(n)
		cin >> inst;
		if(inst != "RETURN") cin >> referencia;
		auto & datos = instrucciones[nLinea]; // O(log n)
		datos.first = inst;
		datos.second = referencia;
		instNuevaLinea[nLinea] = nuevaLinea; // O(1 + factor de carga)
		nuevaLinea += 10;
		cin >> nLinea;
	}

	nuevaLinea = 10;
	// O(n)
	for (auto const& p : instrucciones) { // O(n)
		cout << nuevaLinea << " " << p.second.first << " ";
		
		if(p.second.first != "RETURN")
			cout << instNuevaLinea.at(p.second.second); // O(1 + factor de carga)
		
		cout << "\n";

		nuevaLinea += 10;
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
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();
	
		// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
