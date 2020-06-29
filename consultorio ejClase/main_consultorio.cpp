
#include <iostream>
#include <fstream>

#include "consultorio.h"

bool resuelveCaso() {
   std::string orden, pac, med;
   std::cin >> orden;
   if (!std::cin)
      return false;
   
   consultorio H;

   while (orden != "FIN") {
      try {
         if (orden == "alta_medico") {
            std::cin >> med;
            H.alta_medico(med);
         } else if (orden == "pedir_consulta") {
            std::cin >> pac >> med;
            H.pedir_consulta(pac, med);
         } else if (orden == "tiene_pacientes") {
            std::cin >> med;
            bool tiene = H.tiene_pacientes(med);
            std::cout << med
               << (tiene ? "" : " no")
               << " tiene pacientes\n";
         } else if (orden == "siguiente_paciente") {
            std::cin >> med;
            pac = H.siguiente_paciente(med);
            std::cout << med << " atiende a " << pac << '\n';
            H.atender_consulta(med);
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

   while (resuelveCaso());

   return 0;
}

