#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdexcept>  // invalid_argument
#include <math.h>

class polinomio {
private:
	std::vector<std::pair<int, int>> pNomio;

public:
	// constructora
	polinomio(std::pair<int, int> p) {
		addMonomio(p);
	}

	polinomio() {}

	void addMonomio(const std::pair<int, int> & p) {
		if (p.first != 0) {
			std::vector<std::pair<int, int>>::iterator it = std::lower_bound(pNomio.begin(), pNomio.end(), p,
				[](const std::pair<int, int>& l, const std::pair<int, int>& r) {
					return l.second < r.second;
				});
			if (it >= pNomio.begin() && it < pNomio.end() && p.second == (*it).second)
				(*it).first += p.first;
			else 
				pNomio.insert(it, p);
		}
	}

	int evaluarPolinomio(int valor) {
		int sol = 0;
		for (std::pair<int, int>& p : pNomio)
			sol += (int) (p.first * (pow(valor, p.second)));
		return sol;
	}

	void read(std::istream& input = std::cin) {
		std::pair<int, int> p(11, 10);
		while (p.first != 0 || p.second != 0) {
			input >> p.first >> p.second;
			if (p.first == 11 && p.second == 10) { p.first = 0; p.second = 0; }
			if(p.first != 0 || p.second != 0) addMonomio(p);
		}
	}
};

inline std::istream& operator>>(std::istream& entrada, polinomio& p) {
	p.read(entrada);
	return entrada;
}

#endif
