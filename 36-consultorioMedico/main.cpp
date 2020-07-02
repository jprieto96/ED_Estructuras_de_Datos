
#include <iostream>
#include <fstream>

#include "consultorio_medico.h"

bool resuelveCaso() {
   std::string orden, medico, paciente;
   fecha f;
   int dia, nCasos;
   std::cin >> nCasos;
   if(!std::cin)
      return false;
   
   consultorio_medico c;

   for (size_t i = 0; i < nCasos; i++) {
      try {
         std::cin >> orden;
         if (orden == "nuevoMedico") {
            std::cin >> medico;
            c.nuevoMedico(medico);
         } else if (orden == "pideConsulta") {
            std::cin >> paciente >> medico >> f;
            c.pideConsulta(paciente, medico, f);
         } else if (orden == "siguientePaciente") {
            std::cin >> medico;
            paciente = c.siguientePaciente(medico);
            std::cout << "Siguiente paciente doctor " + medico + '\n';
            std::cout << paciente + '\n';
         } else if (orden == "atiendeConsulta") {
            std::cin >> medico;
            c.atiendeConsulta(medico);
         } else if (orden == "listaPacientes") {
            std::cin >> medico >> dia;
            auto v = c.listaPacientes(medico, dia);
            std::cout << "Doctor " + medico + " dia " << dia << '\n';
            for(auto const& s : v) {
               std::cout << s.first << " " << s.second << '\n';
            }
         }
      } catch (std::domain_error e) {
         std::cout << e.what() << '\n';
      }
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

