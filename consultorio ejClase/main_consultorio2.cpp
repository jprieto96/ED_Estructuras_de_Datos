
#include <iostream>
#include <fstream>

#include "consultorio2.h"


bool resuelveCaso() {
   std::string orden, pac, med;
   std::cin >> orden;
   if (!std::cin)
      return false;
   
   consultorio H;

   while (orden != "FIN") {
      try {
         if (orden == "ALTA") {
            std::cin >> med;
            H.alta_medico(med);
         } else if (orden == "PEDIR_CONSULTA") {
            std::cin >> pac >> med;
            H.pedir_consulta(pac, med);
         } else if (orden == "TIENE_PACIENTES") {
            std::cin >> med;
            std::cout << med
               << (H.tiene_pacientes(med) ? "" : " no")
               << " tiene pacientes\n";
         } else if (orden == "SIGUIENTE") {
            std::cin >> med;
            pac = H.siguiente_paciente(med);
            std::cout << med << " atiende a " << pac << '\n';
            H.atender_consulta(med);
         } else if (orden == "ABANDONAR_CONSULTA") {
            std::cin >> pac >> med;
            H.abandonar_consulta(pac, med);
         }
      } catch (std::domain_error e) {
         std::cout << "ERROR: " << e.what() << '\n';
      }
      std::cin >> orden;
   }
   std::cout << "---\n";
   return true;
}

#define DOMJUDGE

int main() {

   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("consultorio.txt");
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

