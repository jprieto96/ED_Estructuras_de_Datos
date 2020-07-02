
#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>
#include <iterator>
#include "fecha.h"

using namespace std;

using medico = string;
using paciente = string;

#define clave first
#define valor second

class consultorio_medico {

   unordered_map<medico, map<fecha, paciente>> medicos;

public:

   // O(1)
   void nuevoMedico(medico const& m) {
      medicos.insert({ m, {} });
   }

   // O(1)
   void pideConsulta(paciente const& p, medico const& m, fecha const& f) {
      auto it = medicos.find(m);
      if(it == medicos.end())
         throw domain_error("Medico no existente");
      else {
         auto &pacs = it->valor;
         if(pacs.count(f))
            throw domain_error("Fecha ocupada");
         else
            pacs[f] = p;
      }
   }

    // O(1)
   paciente siguientePaciente(medico const& m) const {
      auto it = medicos.find(m);
      if(it == medicos.end())
         throw domain_error("Medico no existente");
      else {
         auto &pacs = it->valor;
         if(pacs.empty())
            throw domain_error("No hay pacientes");
         else
            return pacs.begin()->second;
      }
   }

   // O(1)
   void atiendeConsulta(medico const& m) {
      auto it = medicos.find(m);
      if(it == medicos.end())
         throw domain_error("Medico no existente");
      else {
         auto &pacs = it->valor;
         if(pacs.empty())
            throw domain_error("No hay pacientes");
         else {
            pacs.erase(pacs.begin());
         }
      }
   }

   
   vector<pair<paciente, fecha>> listaPacientes(medico const& m, const int & dia) const{
      vector<pair<paciente, fecha>> pacsRes;
      auto it = medicos.find(m);
      if(it == medicos.end())
         throw domain_error("Medico no existente");
      else {
         for(auto const& p : it->valor) {
            if(p.first.dia == dia)
               pacsRes.push_back({ p.second, p.first });
         }
      }
      return pacsRes;
   }
};

#endif
