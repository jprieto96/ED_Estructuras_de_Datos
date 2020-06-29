#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
	void frontera(std::vector<int> &v) const {
		frontera(this->raiz, v);
	}
private:
	static void frontera(Link r, std::vector<int>& v) {
		if (r == nullptr) return;
		else if (r->left == nullptr && r->right == nullptr) v.push_back(r->elem);
		else {
			frontera(r->left, v);
			frontera(r->right, v);
		}
	}
};

// lee un árbol binario de la entrada estándar

template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}

