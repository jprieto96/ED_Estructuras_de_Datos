#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool esDeporte(string const &linea) {
	return linea[0] >= 65 && linea[0] <= 90;
}

bool orden(pair<string, int> const &i, pair<string, int> const &j) {
	if(i.second > j.second) return true;
	if(i.second == j.second && i.first < j.first) return true;
	return false;
}

bool resuelveCaso() {
	string linea, deporteActual;
	cin >> linea;
	if (!cin) return false;
	unordered_map<string, unordered_set<string>> datosPorDeporte; // <deporte, conjunto de alumnos que jugaran a ese deporte>
	unordered_map<string, string> datosPorAlumno; // <alumno, deporte a realizar>
	vector<pair<string, int>> resultado;
	while (linea != "_FIN_") {
		if (esDeporte(linea)) { // la linea es un deporte
			deporteActual = linea;
			datosPorDeporte[deporteActual];
		}
		else { // la linea es un alumno
			if (datosPorAlumno.count(linea)) { // si el alumno ya estaba apuntado
				string & deportePorAlumno = datosPorAlumno.at(linea);
				// si el deporte en el que estaba apuntado el alumno
				if(deportePorAlumno != deporteActual)
					datosPorDeporte[deportePorAlumno].erase(linea);
			}
			else { // si el alumno no estaba apuntado
				datosPorAlumno[linea] = deporteActual;
				datosPorDeporte[deporteActual].insert(linea);
			}	
				
		}
		cin >> linea;
	}

	// Guardo el diccionario de datosPorDeporte en el vector que posteriormente se ordenara y se mostrara
	for (pair<string, unordered_set<string>> const & p : datosPorDeporte) {
		resultado.push_back({p.first, p.second.size()});
	}

	sort(resultado.begin(), resultado.end(), orden);
	for (pair<string, int> const &p : resultado) {
		cout << p.first << " " << p.second << '\n';
	}

	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

		// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
