
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "stack_eda.h"

bool esCerrada(const char &c) {
	return c == ')' || c == ']' || c == '}';
}

bool esAbierta(const char& c) {
	return c == '(' || c == '[' || c == '{';
}

char getAbierta(const char& c) {
	if (c == ')') return '(';
	else if (c == ']') return '[';
	else return '{';
}

bool resuelveCaso() {
	string secuencia;
	stack<char> s;
	bool ok = true;
	if (!getline(cin, secuencia)) return false;
	for (int i = 0; i < secuencia.size(); i++) {
		char c = secuencia[i];
		if (esAbierta(c)) s.push(c);
		else if (esCerrada(c)) {
			if (!s.empty() && getAbierta(c) == s.top()) s.pop();
			else { i = secuencia.size(); ok = false; }
		}
	}

	if (ok && s.empty()) cout << "SI\n";
	else cout << "NO\n";

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
