
#include <iostream>
#include <fstream>

#include "carnet_puntos.h"

bool resuelveCaso() {
   std::string orden, dni;
   int puntos;
   std::cin >> orden;
   if(!std::cin)
      return false;
   
   carnet_puntos CP;

   while (orden != "FIN") {
      try {
         if (orden == "nuevo") {
            std::cin >> dni;
            CP.nuevo(dni);
         } else if (orden == "quitar") {
            std::cin >> dni >> puntos;
            CP.quitar(dni, puntos);
         } else if (orden == "consultar") {
            std::cin >> dni;
            int p = CP.consultar(dni);
            std::cout << "Puntos de " << dni << ": " << p << '\n';
         } else if (orden == "cuantos_con_puntos") {
            std::cin >> puntos;
            int m = CP.cuantos_con_puntos(puntos);
            std::cout << "Con " << puntos << " puntos hay " << m << '\n';
         }
      } catch (std::domain_error e) {
         std::cout << "ERROR: " << e.what() << '\n';
      }
      std::cin >> orden;
   }
   std::cout << "---\n";
   return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());
	
		// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}

