#include "vecteur.h"

// Implémentation des constructeurs
vecteur::vecteur(int dimension, float default_value) {
    if (dimension < 0) {
        std::cout << "La taille d'un vecteur doit être positive" << std::endl;
    }
    assert(dimension > 0);

    dim = dimension;
    tab = new float[dim];

    for (int i = 0; i < dim; i++) {
        tab[i] = default_value;
    }
    std::cout << "Vecteur initialisé avec " << dim << " dimensions" << std::endl;
}

vecteur::vecteur(int dimension) {
    dim = dimension;
    tab = new float[dim];
    for (int i = 0; i < dim; i++) {
        tab[i] = 0.f;
    }
    std::cout << "Vecteur initialisé avec " << dim << " dimensions" << std::endl;
}

vecteur::~vecteur() {
    delete[] tab;
    tab = nullptr;
}

vecteur::vecteur(const vecteur& copied) {
    dim = copied.dim;
    tab = new float[dim];
    for (int i = 0; i < dim; i++) {
        tab[i] = copied.get(i);
    }
}

// Accès aux éléments
const float vecteur::get(const int position) const {
    assert(position < dim);
    return tab[position];
}

const int vecteur::getDimension() const {
    return dim;
}

const int vecteur::dimensions() const {
    return getDimension();
}

// Modification des éléments
void vecteur::set(const int position, float valeur) {
    assert(position < dim);
    tab[position] = valeur;
}

// Opérateurs
vecteur& vecteur::operator=(const vecteur& other) {
    assert(dim == other.dim);
    for (int i = 0; i < dim; i++) {
        tab[i] = other.get(i);
    }
    return *this;
}

vecteur vecteur::operator+(const vecteur& other) {
    assert(dim == other.dim);
    vecteur result(other.dim);
    result = add(this, &other);
    return result;
}

std::ostream& operator<<(std::ostream& out, vecteur& vect) {
    afficherVecteur(&vect, out);
    return out;
}

std::istream& operator>>(std::istream& in, vecteur& vect) {
    delete[] vect.tab;
    int dimension;
    std::cout << "Entrez la dimension du vecteur : ";
    in >> dimension;
    vect.dim = dimension;
    vect.tab = new float[dimension];

    for (int i = 0; i < dimension; i++) {
        std::cout << "Valeur pour la dimension " << i + 1 << " : ";
        in >> vect.tab[i];
    }
    return in;
}

float& vecteur::operator[](const int position) {
    assert(position < dim);
    return tab[position];
}

void afficherVecteur(const vecteur* v, std::ostream& out) {
    const int dimension = v->getDimension();
    out << "Vecteur de " << dimension << " dimensions: (";
    for (int i = 0; i < dimension; i++) {
        out << v->get(i);
        if (i + 1 < dimension) out << ", ";
    }
    out << ")\n";
}

vecteur* lireVecteur(std::istream& in) {
    int dimension;
    std::cout << "Entrez la dimension du vecteur : ";
    in >> dimension;

    vecteur* myVect = new vecteur(dimension);
    for (int i = 0; i < dimension; i++) {
        float value;
        std::cout << "Valeur pour la dimension " << i + 1 << " : ";
        in >> value;
        myVect->set(i, value);
    }
    return myVect;
}

vecteur add(const vecteur* v1, const vecteur* v2) {
    assert(v1->getDimension() == v2->getDimension());
    int dimension = v1->getDimension();
    vecteur result(dimension);
    for (int i = 0; i < dimension; i++) {
        result.set(i, v1->get(i) + v2->get(i));
    }
    return result;
}

float operator*(const vecteur& v1, const vecteur& v2) {
    assert(v1.getDimension() == v2.getDimension());
    float produitScalaire = 0.f;
    for (int i = 0; i < v1.getDimension(); i++) {
        produitScalaire += v1.get(i) * v2.get(i);
    }
    return produitScalaire;
}
