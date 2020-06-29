
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "queue_eda.h"
#include "stack_eda.h"

void insertarDePila(stack<char> & pila, string &secuencia) {
	while (!pila.empty()) {
		char c = pila.top(); pila.pop();
		secuencia += c;
	}
}

bool esVocal(const char & c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// O(n) -> Orden lineal siendo n como maximo el tamaño de los caracteres del mensaje
string decodificacion(string const& mensaje) {
	queue<char> cola;
	stack<char> pila;
	int i = 1;
	for (char c : mensaje) { // n veces siendo n el numero de caracteres del mensaje
		if (i % 2 == 0) pila.push(c);
		else cola.push(c);
		++i;
	}
	while (!pila.empty()) { // tamaño de la pila
		cola.push(pila.top());
		pila.pop();
	}

	string resultado;

	while (!cola.empty()) { // tamaño de la cola
		char c = cola.front(); cola.pop();
		if (!esVocal(c)) pila.push(c);
		else {
			insertarDePila(pila, resultado);
			resultado += c;
		}
	}
	insertarDePila(pila, resultado);

	return resultado;
}

bool resuelveCaso() {
	string frase;
	if (!getline(cin, frase)) return false;

	cout << decodificacion(frase) << '\n';

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
