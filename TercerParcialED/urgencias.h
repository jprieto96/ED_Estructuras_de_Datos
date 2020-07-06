
// JOSE RAMON PRIETO DEL PRADO (E56)

/* 
	He utilizado un diccionario no ordenado para representar a los pacientes
	junto con su gravedad y un iterador a la lista que va a representar a cada
	uno en la sala de espera ordenados por gravedad.
	He utilizado un vector en el cada posicion es la gravedad y en cada posicion
	tengo una lista para representar a los pacientes por su gravedad
	He utilizado un conjunto ordenado para tener una lista de pacientes ordenada
	alfabeticamente de los que se han recuperado en la sala de espera.
*/
#ifndef URGENCIAS
#define URGENCIAS

#include <iostream>          
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

using paciente = string;
using gravedad = int;
using info_paciente = pair <gravedad, list<paciente>::iterator>;

#define clave first
#define valor second

class urgencias {

	unordered_map<paciente, info_paciente> pacs;
	vector<list<paciente>> porGravedad;
	set<paciente> recs;

public:

	urgencias() : porGravedad(3) {}

	// O(1) ya que se hacen operaciones a un diccionario no ordenado
	// y a un vector
	void nuevo_paciente(paciente const& p, gravedad const& g) {
		if(g < 1 || g > 3)
			throw domain_error("Gravedad incorrecta");
		else {
			if(pacs.count(p))
				throw domain_error("Paciente repetido");
			else {
				auto& l = porGravedad[g - 1];
				pacs.insert({ p, { g, l.insert(l.end(), p)} });
			}
		}	
	}

	// O(1) ya que se hacen operaciones a un diccionario no ordenado
	gravedad gravedad_actual(paciente const& p) const {
		auto it = pacs.find(p);
		if (it == pacs.end())
			throw domain_error("Paciente inexistente");
		else
			return it->valor.first;
	}

	// O(1) ya que se hacen operaciones a un diccionario no ordenado
	// a un vector y tambien se hacen operaciones constantes a una lista
	paciente siguiente() {
		paciente sig;
		if (!porGravedad[2].empty()) {
			sig = porGravedad[2].front();
			porGravedad[2].pop_front();
			pacs.erase(sig);
			return sig;
		}
		else if (!porGravedad[1].empty()) {
			sig = porGravedad[1].front();
			porGravedad[1].pop_front();
			pacs.erase(sig);
			return sig;
		}
		else if (!porGravedad[0].empty()) {
			sig = porGravedad[0].front();
			porGravedad[0].pop_front();
			pacs.erase(sig);
			return sig;
		}	
		else
			throw domain_error("No hay pacientes");
	}

	// O(log P) ya que se inserta un paciente en un conjunto ordenado
	// y las demas operaciones sobre un diccionario no ordenado son O(1)
	void mejora(paciente const& p) {
		auto it = pacs.find(p);
		if (it == pacs.end())
			throw  domain_error("Paciente inexistente");
		else {
			porGravedad[it->valor.first - 1].erase(it->valor.second);
			--it->valor.first;
			if (it->valor.first > 0) {
				auto& l = porGravedad[it->valor.first - 1];
				it->valor.second = l.insert(l.begin(), p);
			}
			else {
				pacs.erase(p);
				recs.insert(p); // O(log P)
			}
		}
	}

	// O(1)
	set<paciente> recuperados() {
		return recs;
	}

};


#endif
