
#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

using dni = string;
using puntos = int;

#define clave first
#define valor second
#define MAX_PUNTOS 16

class carnet_puntos {

   unordered_map<dni, puntos> conductores;
   vector<int> conductores_por_puntos;

public:

   carnet_puntos() : conductores_por_puntos(MAX_PUNTOS) {}

   // O(1) -   constante ya que solamente se realiza una operacion
   //          sobre un diccionario no ordenado y suponiendo que el 
   //          hash esta bien implementado seria O(1 + factor de carga)
   //          y la otra operacion que se realiza es un acceso a un vector con la operacion []
   void nuevo(dni const& id) { // O(1)
      auto res = conductores.insert({ id, MAX_PUNTOS - 1 });
      if(!res.second)
         throw std::domain_error("Conductor duplicado");
      else
         ++conductores_por_puntos[MAX_PUNTOS - 1];
   }

   // O(1) -   constante ya que solamente se realiza una operacion
   //          sobre un diccionario no ordenado y suponiendo que el 
   //          hash esta bien implementado seria O(1 + factor de carga)
   //          y la otra operacion que se realiza es un acceso a un vector con la operacion []
   void quitar(dni const& id,puntos const& p) {
      auto it = conductores.find(id);
      if(it == conductores.end())
         throw std::domain_error("Conductor inexistente");
      else {
         --conductores_por_puntos[it->valor];
         it->valor = std::max(0, it->valor - p);
         ++conductores_por_puntos[it->valor];
      }
   }

   // O(1) -   constante ya que solamente se realiza una operacion
   //          sobre un diccionario no ordenado y suponiendo que el 
   //          hash esta bien implementado seria O(1 + factor de carga)
   //          y la otra operacion que se realiza es un acceso a un vector con la operacion []
   int consultar(dni const& id) const {
      auto it = conductores.find(id);
      if(it == conductores.end())
         throw std::domain_error("Conductor inexistente");
      else
         return it->valor;
   }

   // O(1) -   constante ya que solamente se hace una operacion
   //          que es un acceso a una posicion de un vector
   int cuantos_con_puntos(puntos const& p) const{
      if(p < 0 || p > 15)
         throw std::domain_error("Puntos no validos");
      else 
         return conductores_por_puntos[p];
   }
};

#endif
