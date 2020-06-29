
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

#include "bintree_eda.h"

struct sol {
	bool ok = false;
	int generaciones = 0;
};

bool isOk(bintree<int> const& arbol) {
	if (!arbol.left().empty() && arbol.right().empty()) {
		return arbol.root() >= arbol.left().root() + 18;
	}
	else if (!arbol.right().empty() && arbol.left().empty()) {
		return false;
	}
	else if (!arbol.right().empty() && !arbol.left().empty()) {
		return (arbol.root() >= arbol.left().root() + 18 && arbol.root() >= arbol.right().root() + 18) && 
			(arbol.left().root() >= arbol.right().root() + 2);
	}
	else return true;
}

sol resolver(bintree<int> const& arbol) {
	if (arbol.empty()) return { true, 0 };
	else {
		sol izq = resolver(arbol.left());
		sol der = resolver(arbol.right());
		return { isOk(arbol) && izq.ok && der.ok, max(izq.generaciones, der.generaciones) + 1 };
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	sol s = resolver(arbol);
	if(s.ok) cout << "SI" << " " << s.generaciones << '\n';
	else cout << "NO" << '\n';
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
