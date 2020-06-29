
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "deque_eda.h"
#include "queue_eda.h"

void recolocar(queue<int> &l) {
	deque<int> aux;
	aux.push_back(l.front());
	l.pop();
	while (!l.empty()) {
		if (l.front() >= aux.front())
			aux.push_back(l.front());
		else
			aux.push_front(l.front());
		l.pop();
	}

	while (!aux.empty()) {
		l.push(aux.front());
		aux.pop_front();
	}
}

bool resuelveCaso() {
	int nElementos, n;
	cin >> nElementos;
	if (nElementos == 0) return false;

	queue<int> l;
	for (int i = 0; i < nElementos; i++) {
		cin >> n;
		l.push(n);
	}
	
	recolocar(l);

	for (int i = 0; i < nElementos; i++) {
		cout << l.front() << " ";
		l.pop();
	}

	cout << '\n';
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
