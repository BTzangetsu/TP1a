#include "vecteur.h"

//[,

//Constructeur avec la dimension du vecteur et la valeur par defaut
vecteur::vecteur(int dimension, float default_value) {
	//on verifie si la dimension est strictement superieur a zero
	if (dimension < 0) {
		std::cout << "la dimension d'un vecteur doit etre superieur a zero"<<std::endl;
	}
	assert(dimension > 0);

	m_dim = dimension;

	//ensuite on alloue un tableau dynamique
	vect_tab = new float[m_dim];

	//ensuite on remplie le tableau avec la valeur par defaut
	for (int i = 0; i < m_dim; i++) {
		vect_tab[i] = default_value;
	}
	//message de fin de construction
	std::cout << "initialisation d'un vecteur a, " << m_dim << " dimensions"<<std::endl;
}

//Constructeur par default
//Constructeur avec la dimension du vecteur
vecteur::vecteur(int taille) {
	m_dim = taille;

	//ensuite on alloue un tableau dynamique
	vect_tab = new float[m_dim];

	//ensuite on remplie le tableau avec la valeur par defaut
	for (int i = 0; i < m_dim; i++) {
		vect_tab[i] = 0.f;
	}
	//message de fin de construction
	std::cout << "initialisation d'un vecteur a, " << m_dim << " dimensions" << std::endl;
}

vecteur::~vecteur() {
	delete[] vect_tab;
	vect_tab = nullptr;
}

vecteur::vecteur(const vecteur& copied) {
	this->m_dim = copied.m_dim;
	this->vect_tab = new float[this->m_dim];
	for (int i = 0; i < this->m_dim; i++) {
		*(this->vect_tab + i) = copied.get(i);
	}
}

//_______________GETTERS________________
// 
//methode permettant de consluter la valeur de la dimension "i"
const float vecteur::get(const int position) const {

	//on verifie que la position demander est bien valide
	assert(position < m_dim);
	return vect_tab[position];
}

//pour acceder a la dimension
const int vecteur::getDimension()const {
	return m_dim;
}

const int vecteur::dimensions()const {
    return getDimension();
}


//______________SETTERS___________________

//methode permettant de modifie la valeur de la dimension "i"
void vecteur::set(const int position, float valeur) {
	//on veridie que la position que 'on sohaite modifie est bien valide
	assert(position < m_dim);

	vect_tab[position] = valeur;
}

//________________OPERATORS____________________
vecteur& vecteur::operator=(const vecteur& other) {
	//On verifie d'abord que les deux vecteurs ont les memes dimensions*
	assert(this->m_dim == other.m_dim);

	//en suit on copie les elements un a un
	for (int i = 0; i < this->m_dim; i++) {
		this->vect_tab[i] = other.get(i);
	}

	return *this;
}

vecteur vecteur::operator+(const vecteur& other) {
	//On verifie d'abord que les deux vecteurs ont les memes dimensions*
	assert(this->m_dim == other.m_dim);

	//on instancie le vecteur quon va retourner
	vecteur result(other.m_dim);

	//on somme
	result = add(this, &other);

	return result;
}

//operateur d'affichage
std::ostream& operator<<(std::ostream& out,vecteur& vect) {
	afficherVecteur(&vect, out);
	return out;
}

std::istream& operator>>(std::istream& in,vecteur& vect) {
	
	//on libere d'abord le tableau de vect
	delete[] vect.vect_tab;

	int value;
	int dim;

	//Messsage pour demander la dim du vecteur
	std::cout << "Entrez la dimension de votre vecteur" << std::endl;
	in >> dim;

	//on change la dim du vecteur
	vect.m_dim = dim;
	vect.vect_tab = new float[dim];

	//Boucle pour personnalizer le vecteur
	for (int i = 0; i < dim; i++) {
		//on demande a l'utilisateur de rentre la valeur de la i +1 ieme dimension
		std::cout << "Quel valeur pour la dimension " << i + 1 << std::endl;
		in >> value;
		vect.set(i, value);
	}
	return in;
}

float& vecteur::operator[](const int position) {
	//On verifie d'abord si la postion qu'on souhaite est valide
	assert(this->m_dim > position);
	return *(this->vect_tab + position);
}


void afficherVecteur(const vecteur* v, std::ostream& out) {
	const int dim = v->getDimension();
	out << "Vecteur a "<< dim<<" dimensions: (";
	for (int i = 0; i < dim; i++) {
		if (i + 1 == dim) {
			out << v->get(i) << ")";
			break;
		}
		out << v->get(i)<< ", ";
	}
	out << std::endl;
}

vecteur* lireVecteur(std::istream& in) {
	int value;
	int dim;

	//Messsage pour demander la dim du vecteur
	std::cout << "Entrez la dimension de votre vecteur" << std::endl;
	in >> dim;

	//initialization du vecteur qui va etre retourné
	vecteur* my_vect = new vecteur(dim);
	
	//Boucle pour personnalizer le vecteur
	for (int i=0; i < dim; i++) {
		//on demande a l'utilisateur de rentre la valeur de la i +1 ieme dimension
		std::cout << "Quel valeur pour la dimension " << i + 1 << std::endl;
		in >> value;
		my_vect->set(i, value);
	}
	return my_vect;
}

vecteur add(const vecteur* v1, const vecteur* v2) {
	//on verifie d'abord que les deux vecteurs v1 et v2 ont la meme dimension
	int dim1, dim2;
	dim1 = v1->getDimension();
	dim2 = v2->getDimension();
	assert(dim1 == dim2);

	//on instancie un vecteur de dimension dim1 = dim2
	vecteur my_vect(dim1);

	//ensuite on peut faire la somme des deux vecteurs
	for (int i = 0; i < dim1; i++) {
		my_vect.set(i,v1->get(i)+ v2->get(i));
	}
	//on retourne le resulta;t
	return my_vect;
}

float operator*(const vecteur& v1, const vecteur& v2) {
	// Vérification que les deux vecteurs ont la meme dim
	assert(v1.getDimension() == v2.getDimension());

	float produit_scalaire = 0.f;
	int dimension = v1.getDimension();

	// Calcul du produit scalaire
	for (int i = 0; i < dimension; i++) {
		produit_scalaire += v1.get(i) * v2.get(i);
	}

	return produit_scalaire;
}
