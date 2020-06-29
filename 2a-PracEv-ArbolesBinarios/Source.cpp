
// JOSE RAMON PRIETO DEL PRADO

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct sol {
	int caminoMax = 0, caminoMaxConRaizP = 0;
};

bool esPar(int const& n) {
	return n % 2 == 0;
}

// Coste lineal -> O(n) siendo n el numero de nodos del arbol.
// Se recorren los n nodos del arbol y es constante el uso que se hace con ellos

/* 
	Voy a tomar nota del camino mas largo sin tener en cuenta la
	raiz y el camino mas largo con la raiz incluida.
*/
sol caminoPares(bintree<int> const & arbol, int &caminoMasLargo) {
  	if(arbol.empty()) return { 0, 0 };
	sol izq = caminoPares(arbol.left(), caminoMasLargo);
	sol der = caminoPares(arbol.right(), caminoMasLargo);
	sol s;
	if(esPar(arbol.root())) { 
		s.caminoMaxConRaizP = max(izq.caminoMaxConRaizP, der.caminoMaxConRaizP) + 1;
		s.caminoMax = izq.caminoMaxConRaizP + der.caminoMaxConRaizP + 1;
	}
	else {
		s.caminoMaxConRaizP = 0;
		s.caminoMax = max(izq.caminoMax, der.caminoMax);
	}
	caminoMasLargo = max(caminoMasLargo, s.caminoMax);
	return s;
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   int caminoMasLargo = 0;
   caminoPares(arbol, caminoMasLargo);
   cout << caminoMasLargo << '\n'; 
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("datos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
