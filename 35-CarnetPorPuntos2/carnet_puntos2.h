
#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

using dni = string;
using puntos = int;
using info_puntos = pair<puntos, list<dni>::iterator>;

#define clave first
#define valor second
#define MAX_PUNTOS 16

class carnet_puntos {

   unordered_map<dni, info_puntos> conductores;
   vector<list<dni>> ptos;

public:

   carnet_puntos() : ptos(MAX_PUNTOS) {}

   // O(1)
   void nuevo(dni const& id) {
      auto res = conductores.insert({ id, {} });
      if(!res.second)
         throw std::domain_error("Conductor duplicado");
      else {
         auto & i_ptos = conductores.at(id);
         i_ptos.first = MAX_PUNTOS - 1;
         auto & l = ptos[MAX_PUNTOS - 1];
         i_ptos.second = l.insert(l.begin(), id);
      }
         
   }

   // O(1)
   void quitar(dni const& id,puntos const& p) {
      auto it = conductores.find(id);
      if(it == conductores.end())
         throw std::domain_error("Conductor inexistente");
      else {
         auto &l = ptos[it->valor.first];
         it->valor.first = max(it->valor.first - p, 0);

         l.erase(it->valor.second);

         auto &nL = ptos[it->valor.first];
         it->valor.second = nL.insert(nL.begin(), id);
      }
   }

    // O(1)
   void recuperar(dni const& id,puntos const& p) {
      auto it = conductores.find(id);
      if(it == conductores.end())
         throw std::domain_error("Conductor inexistente");
      else {
         auto &l = ptos[it->valor.first];
         it->valor.first = min(it->valor.first + p, MAX_PUNTOS - 1);

         l.erase(it->valor.second);

         auto &nL = ptos[it->valor.first];
         it->valor.second = nL.insert(nL.begin(), id);
      }
   }

   // O(1)
   int consultar(dni const& id) const {
      auto it = conductores.find(id);
      if(it == conductores.end())
         throw std::domain_error("Conductor inexistente");
      else
         return it->valor.first;
   }

   // O(1)
   int cuantos_con_puntos(puntos const& p) const{
      if(p < 0 || p > 15)
         throw std::domain_error("Puntos no validos");
      else {
         return ptos[p].size();
      }
   }

   // O(1)
   list<dni> lista_por_puntos(puntos const& p) const{
      if(p < 0 || p > 15)
         throw std::domain_error("Puntos no validos");
      else {
         return ptos[p];
      }
   }
};

#endif
