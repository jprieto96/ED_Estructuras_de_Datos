
#include <iostream>
#include <fstream>
#include <list>

#include "autoescula.h"

bool resuelveCaso() {
   std::string orden, alumno, profesor;
   int puntos;
   std::cin >> orden;
   if(!std::cin)
      return false;
   
   autoescuela a;

   while (orden != "FIN") {
      try {
         if (orden == "alta") {
            std::cin >> alumno >> profesor;
            a.alta(alumno, profesor);
         } else if (orden == "es_alumno") {
            std::cin >> alumno >> profesor;
            bool ok = a.es_alumno(alumno, profesor);
            if(ok)
               std::cout << alumno + " es alumno de " + profesor;
            else
               std::cout << alumno + " no es alumno de " + profesor;
            std::cout << '\n';
         } else if (orden == "puntuacion") {
            std::cin >> alumno;
            int p = a.puntuacion(alumno);
            std::cout << "Puntuacion de " + alumno + ": " << p << '\n';
         } else if (orden == "actualizar") {
            std::cin >> alumno >> puntos;
            a.actualizar(alumno, puntos);
         } else if (orden == "examen") {
            std::cin >> profesor >> puntos;
            auto v = a.examen(profesor, puntos);
            std::cout << "Alumnos de " + profesor + " a examen:\n";
            for(auto const& s : v) {
               std::cout << s << '\n';
            }
         } else if(orden == "aprobar"){
            std::cin >> alumno;
            a.aprobar(alumno);
         }
      } catch (std::domain_error e) {
         std::cout << "ERROR" << '\n';
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

