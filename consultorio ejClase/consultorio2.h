

#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

using medico = std::string;
using paciente = std::string;

#define clave first
#define valor second


class consultorio {
   unordered_map<medico, list<paciente>> meds;
   unordered_map<paciente,
       unordered_map<medico, list<paciente>::iterator>> pacs;
   
public:
   void alta_medico(medico const& m) { // O(1)
      auto res = meds.insert({m, {}});
      if (!res.second)
         throw domain_error(m + " repetido");
   }

   void pedir_consulta(paciente const& p, medico const& m) { // O(1)
      auto it = meds.find(m);
      if (it == meds.end())
         throw domain_error(m + " no existe");
      else {
         auto & ip = pacs[p];
         auto itMP = ip.find(m);
         if (itMP == ip.end())
            throw domain_error(p + " repite con " + m);
         else {
            itMP->valor = it->valor.insert(it->valor.end(), p);
         }
            
      }
   }

   bool tiene_pacientes(medico const& m) const {
      auto it = meds.find(m);
      if (it == meds.end())
         throw domain_error(m + " no existe");
      else
         return !it->valor.empty();
   }

   paciente const& siguiente_paciente(medico const& m) const {
      auto it = meds.find(m);
      if (it == meds.end())
        throw domain_error(m + " no existe");
     else if (it->valor.empty())
        throw domain_error(m + " sin pacientes");
      else
         return it->valor.front();
        
   }

   void atender_consulta(medico const& m) {
      auto it = meds.find(m);
      if (it == meds.end())
        throw domain_error(m + " no existe");
     else if (it->valor.empty())
        throw domain_error(m + " sin pacientes");
     else {
        pacs[it->valor.front()].erase(m);
         it->valor.pop_front();
     }
   }
   
   void abandonar_consulta(paciente const& p, medico const& m) {
      auto it = meds.find(m);
      if (it == meds.end())
         throw domain_error(m + " no existe");
      else {
         auto itP = pacs.find(p);
         if (itP == pacs.end()) {
            throw domain_error(p + " no existe");
         } else {
            auto & ip = itP->valor;
            auto itMP = ip.find(m);
            if (itMP == ip.end())
               throw domain_error(p + " no espera a " + m);
            else {
               it->valor.erase(itMP->valor);
               ip.erase(m);
               if (ip.empty())
                  pacs.erase(itP);
            }
               
         }
      }
   }
};

#endif
