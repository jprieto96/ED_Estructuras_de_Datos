#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

void resuelveCaso() {
	int n, cap, sinRepetir = 0, maxSinRepetir = 0;
	cin >> n;
	unordered_map<int, int> resultado;
	for (size_t i = 0; i < n; i++) {
		cin >> cap;
		if (i == 0 || !resultado.count(cap)) ++sinRepetir;
		else {
			if (i - sinRepetir > resultado[cap]) ++sinRepetir;
			else sinRepetir = i - resultado[cap];
		}
		resultado[cap] = i;
		if (sinRepetir > maxSinRepetir) maxSinRepetir = sinRepetir;
	}
	cout << maxSinRepetir << '\n';
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
