#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

int becarios(int k) {
	int raiz;
	cin >> raiz;
	if (raiz == 0) return k <= 0;
	else {
		int cont = 0;
		for (int i = 0; i < raiz; i++) {
			cont += becarios(k - 1);
		}
		return cont;
	}
}

bool resuelveCaso() {
	int k;
	cin >> k;
	if (!cin) return false;
	cout << becarios(k) << '\n';
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
