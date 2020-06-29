
// ALBERTO VERDEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"

bool resuelveCaso() {
	int nTrenes, nConsultas;
	cin >> nTrenes >> nConsultas;
	if (nTrenes == 0 && nConsultas == 0) return false;

	vector<horas> trenes(nTrenes);
	for (horas & h : trenes)
		cin >> h;

	for (int i = 0; i < nConsultas; i++) {
		horas h;
		try {
			cin >> h;
			auto pos = lower_bound(trenes.begin(), trenes.end(), h);
			if (pos == trenes.end())
				cout << "NO\n";
			else
				cout << *pos << "\n";
		}
		catch (domain_error & e) {
			cout << "ERROR\n";
		}
	}

	cout << "---\n";

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
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}
