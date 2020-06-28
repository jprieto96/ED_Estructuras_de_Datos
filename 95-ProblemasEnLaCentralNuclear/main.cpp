#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include "horas.h"

using namespace std;

// N -> numero de avisos
// M -> datos a consultar
/*
    El coste del algoritmo es O(N + M) ya que se recorren los N avisos
    y los M datos a consultar, y todas las operaciones que se realizan dentro
    de cada uno de los recorridos es O(1).
*/
bool resuelveCaso() {
    /* 
        Diccionario no ordenado implementado sobre una tabla hash
        Clave -> Tipo de sensor
        Valor -> Vector de horas que almacena en orden de aparicion las horas
    */
    unordered_map<string, vector<horas>> datosCentralNuclear;
	int nAvisos, mDatos, indiceARevisar;
    string tipo;
    horas h;

    cin >> nAvisos >> mDatos;
    if(!cin) return false;

    // N veces 
    for (size_t i = 0; i < nAvisos; i++) { // O(N)
        cin >> tipo >> h;
        datosCentralNuclear[tipo].push_back(h); // O(1 + factor de carga) y push_back -> O(1)
    }

    // M veces
    for (size_t i = 0; i < mDatos; i++) { // O(M)
        cin >> tipo >> indiceARevisar;
        if(!datosCentralNuclear.count(tipo)) // O(1 + factor de carga)
            cout << "--";
        else {
            auto &d = datosCentralNuclear.at(tipo); // O(1 + factor de carga)
            if(d.size() >= indiceARevisar)
                cout << d[indiceARevisar - 1];
            else
                cout << "--";
        }  

        cout << " ";
    }
    
    cout << '\n';
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
