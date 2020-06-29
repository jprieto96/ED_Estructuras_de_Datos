#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>

using namespace std;

bool orden(string const& s1, string const& s2) {
	return s1 < s2;
}

bool resuelveCaso() {
	string inst;
	int linea, referencia;
	map<int, pair<string, int>> instrucciones;
	map<int, pair<string, int>> instruccionesConRenum;

	cin >> linea;;
	while(linea != 0) {
		cin >> inst;
		if(inst != "RETURN") cin >> referencia;
		else referencia = 0;
		auto & i = instrucciones[linea];
		i.first = inst;
		i.second = referencia;
		cin.ignore();
		cin >> linea;
	}

	int l = 10;
	for(auto const& p : instrucciones) {
		auto & i = instruccionesConRenum[l];
		
		l += 10;
	}
	
	
	return true;
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
