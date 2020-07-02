
#ifndef autoescuela_h
#define autoescuela_h
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

using profesor = string;
using alumno = string;
using info_alumno = pair<int, profesor>;

#define clave first
#define valor second

class autoescuela {

   unordered_map<profesor, set<alumno>> profesores;
   unordered_map<alumno, info_alumno> alumnos;

public:

   // A -> alumno
   // P -> profesor

    // O(log A) ya que se elimina sobre un conjunto ordenado que esta
   // representado como un arbol binario de busqueda equilibrado por
   // lo que en el caso peor esta operacion de eliminar siempre va a 
   // ser logA
   void alta(alumno const& a, profesor const& p) {
      auto it = alumnos.find(a); // O(1)
      if(it == alumnos.end()) { // Alumno no existente
         alumnos.insert({ a, { 0, p }}); //O(1)
      }
      else { // Alumno ya existente
         profesores[it->valor.second].erase(a); // O(log A)
         it->valor.second = p;
      }
      profesores[p].insert(a); // O(log A)
   }

   // O(1) ya que consulta un diccionario no ordenado
   bool es_alumno(alumno const& a, profesor const& p) const {
      auto it = alumnos.find(a); // O(1)
      return it != alumnos.end() && it->valor.second == p;
   }

   // O(1) ya que consulta un diccionario no ordenado
   int puntuacion(alumno const& a) const {
      auto it = alumnos.find(a); // O(1)
      if(it == alumnos.end())
         throw domain_error("El alumno " + a + " no esta matriculado");
      else
         return it->valor.first;
   }

   // O(1) ya que consulta un diccionario no ordenado
   void actualizar(alumno const& a, int n) {
      auto it = alumnos.find(a); // O(1)
      if(it == alumnos.end())
         throw domain_error("El alumno " + a + " no esta matriculado");
      else
         it->valor.first += n;
   }

   // O(A), es lineal en el numero de alumnos que tiene asignados
   // cada profesor. Las demas operaciones como hacer un push back
   // a un vector o consultas al diccionario no ordenador son O(1)
   vector<alumno> examen(profesor const& p, int n) const {
      vector<alumno> alumnosRes;
      auto it = profesores.find(p); // O(1)
      if(it != profesores.end()) {
         for(auto const& a : it->valor) { // O(A)
            if(alumnos.at(a).first >= n) // O(1)
               alumnosRes.push_back(a); // O(1)
         }
      }
      return alumnosRes;
   }

   // O(log A) ya que se elimina sobre un conjunto ordenado que esta
   // representado como un arbol binario de busqueda equilibrado por
   // lo que en el caso peor esta operacion de eliminar siempre va a 
   // ser logA
   void aprobar(alumno const& a) {
      auto it = alumnos.find(a); // O(1)
      if(it == alumnos.end())
         throw domain_error("El alumno " + a + " no esta matriculado");
      else {
         profesores[it->valor.second].erase(a); // O(log A)
         alumnos.erase(it); // O(1)
      }
   }
};

#endif
