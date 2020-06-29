#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
	T minimo() const {
		return minimo(this->raiz);
	}
private:
	static T minimo(Link r) {
		if (r->left == nullptr && r->right == nullptr) return r->elem;
		else if (r->left != nullptr && r->right == nullptr) return std::min(minimo(r->left), r->elem);
		else if (r->left == nullptr && r->right != nullptr) return std::min(minimo(r->right), r->elem);
		else {
			T izq = minimo(r->left);
			T der = minimo(r->right);
			T comp = izq < der ? izq : der;
			return std::min(comp, r->elem);
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

