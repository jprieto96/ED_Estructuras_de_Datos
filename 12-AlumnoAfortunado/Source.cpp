
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "queue_eda.h"


bool resuelveCaso() {
	int nAlumnos, saltos;
	cin >> nAlumnos >> saltos;
	if (nAlumnos == 0 && saltos == 0) return false;

	queue<int> l;
	for (int i = 0; i < nAlumnos; i++) {
		l.push(i + 1);
	}
	int i = 0;
	while (l.size() > 1) {
		if (i == saltos) {
			l.pop();
			i = 0;
		}
		int e = l.front();
		l.pop();
		l.push(e);
		++i;
	}

	for (int i = 0; i < l.size(); i++) {
		cout << l.front() << '\n';
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
