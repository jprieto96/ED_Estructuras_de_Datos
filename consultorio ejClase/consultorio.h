
#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

using medico = std::string;
using paciente = std::string;

#define clave first
#define valor second


class consultorio : private unordered_map<medico, queue<paciente>> {
public:
   void alta_medico(medico const& m) { // O(1)
      auto res = insert({m, {}});
      if (!res.second)
         throw domain_error(m + " repetido");
   }

   void pedir_consulta(paciente const& p, medico const& m) { // O(1)
      auto it = find(m);
      if (it == end())
         throw domain_error(m + " no existe");
      else
         it->valor.push(p);
   }

   bool tiene_pacientes(medico const& m) const {
      auto it = find(m);
      if (it == end())
         throw domain_error(m + " no existe");
      else
         return !it->valor.empty();
   }

   paciente const& siguiente_paciente(medico const& m) const {
     auto it = find(m);
     if (it == end())
        throw domain_error(m + " no existe");
     else if (it->valor.empty())
        throw domain_error(m + " sin pacientes");
      else
         return it->valor.front();
        
   }

   void atender_consulta(medico const& m) {
     auto it = find(m);
     if (it == end())
        throw domain_error(m + " no existe");
     else if (it->valor.empty())
        throw domain_error(m + " sin pacientes");
      else
         it->valor.pop();
   }
};

#endif
