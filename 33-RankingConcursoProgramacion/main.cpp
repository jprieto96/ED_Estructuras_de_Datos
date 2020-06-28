#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <unordered_map>

using namespace std;

struct datos {
	int numeroAciertos, tiempo;
	unordered_map<string, pair<bool, int>> problemas;
};

struct datosAMostrar {
	string equipo;
	int aciertos, tiempo;
};

bool orden(datosAMostrar const& d1, datosAMostrar const& d2) {
	if(d1.aciertos > d2.aciertos) return true;
	if(d1.aciertos == d2.aciertos && d1.tiempo < d2.tiempo) return true;
	if(d1.aciertos == d2.aciertos && d1.tiempo == d2.tiempo && d1.equipo < d2.equipo) return true;
	return false;
}

bool resuelveCaso() {
	// Diccionario con el equipo de clave y de datos tenemos el numero de aciertos, 
	// el tiempo empleado total para resolver los ejercicios y otro diccionario
	// con el problema de clave y de datos un par con un booleano de si se ha resuelto 
	// el problema y un entero con el numero de fallos
	unordered_map<string, datos> datosPorEquipo;
	vector<datosAMostrar> v;
	string linea, equipo, problema, envio;
	int minutos;
	getline(cin, linea);
	while(linea != "FIN") {
		stringstream ss(linea);
		while(ss >> equipo >> problema >> minutos >> envio) {
			datos & d = datosPorEquipo[equipo];
			pair<bool, int> &p = d.problemas[problema];
			if(!p.first) { // Si todavia no se ha recibido un AC del juez tratamos el caso
				if(envio == "AC") { // Problema correcto
					d.numeroAciertos++;
					// Sumamos 20 mins de mas por cada error antes de hacer correctamente el problema
					d.tiempo += minutos + (20 * p.second);
					p.first = true;
				}
				else { // Problema incorrecto
					p.first = false;
					// Aumentamos numero de errores en ese problema
					++p.second;
				}		
			}
		}
		getline(cin, linea);
	}

	for(auto const& p : datosPorEquipo) {
		v.push_back({ p.first, p.second.numeroAciertos, p.second.tiempo });
	}

	sort(v.begin(), v.end(), orden);
	for(auto const& m : v) {
		cout << m.equipo << " " << m.aciertos << " " << m.tiempo << '\n';
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

	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++)
		resuelveCaso();
	
		// restablecimiento de cin
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
