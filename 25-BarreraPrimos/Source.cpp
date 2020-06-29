
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include <queue>
#include "bintree_eda.h"
using namespace std;

struct sol {
	bool esMultiplo = false;
	int num = 0, nivel = 0;
};

bool esPrimo(int num) {
	int divisores = 0; int cont = 1;
	do {
		if (num % cont == 0) ++divisores;
		++cont;
	} while (cont <= num);
	return divisores == 2;
}

std::vector<pair<int, int>> levelorderSinPrimos(bintree<int> const& arbol) {
	std::vector<pair<int, int>> levels;
	if (!arbol.empty()) {
		queue<pair<bintree<int>, int>> pendientes;
		if (!esPrimo(arbol.root())) pendientes.push({ arbol, 1 });
		while (!pendientes.empty()) {
			pair<bintree<int>, int> sig = pendientes.front();
			pendientes.pop();
			levels.push_back({ sig.first.root(), sig.second });
			if (!sig.first.left().empty() || !sig.first.right().empty()) ++sig.second;
			if (!sig.first.left().empty()) {
				if (!esPrimo(sig.first.left().root())) 
					pendientes.push({ sig.first.left(), sig.second });
			}
			if (!sig.first.right().empty()) {
				if (!esPrimo(sig.first.right().root()))
					pendientes.push({ sig.first.right(), sig.second });
			}
		}
	}
	return levels;
}

sol resolver(bintree<int> const& arbol) {
	// Obtengo el recorrido por niveles pero solo con nodos accesibles
	vector<pair<int, int>> v = levelorderSinPrimos(arbol);
	sol s;
	for (pair<int, int> const & p : v) {
		if (p.first % 7 == 0) {
			s.num = p.first;
			s.nivel = p.second;
			s.esMultiplo = true;
			break;
		}
	}
	return s;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	sol s = resolver(arbol);
	if (s.esMultiplo) cout << s.num << " " << s.nivel;
	else cout << "NO HAY";
	cout << '\n';
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
