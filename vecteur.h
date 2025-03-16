#pragma once
#include<cassert>
#include<iostream>

class vecteur{
private:
	int m_dim;
	float* vect_tab;

public:

	//Constructeur avec la dimension du vecteur et la valeur par defaut
	vecteur(int dimension,float default_value);

	//Constructeur avec la dimension du vecteur
	//constructeur par defaut en l'absensce de paraletre
	vecteur(int dimension = 3);

	//Destructeur
	~vecteur();

	//Constructeur de copie
	vecteur(const vecteur& copied);



	//_______________GETTERS________________
	// 
	//methode permettant de consluter la valeur de la dimension "i"
	const float get(const int position) const;
	
	//pour acceder a la dimension
	const int getDimension()const;

    const int dimensions()const;


	//______________SETTERS___________________

	//methode permettant de modifie la valeur de la dimension "i"
	void set(const int position, float valeur);

	//____________________OPERATORS_______________________________
	//On desactive l'operateur "=" pour la classe vecteur.
	vecteur& operator=(const vecteur&);

	/*Cette operateur ne doit pas renvoyer un resultat par pointeur car l'operation n'est valide
	que entre des objet du type vecteur des pointeurs. Pas par reference non plus car la reference qui sera retourner
	etre detruite une fois la somme terminer, elle ne sera donc plus valide. On donc retourner par valeur 
	pour obtenir une copie du resultat*/
	vecteur operator+(const vecteur&);

	//Et je me suis rendu compte qu'il fallait que cette operateur soit ami de la classe 
	//pour poupoir acceder a sa dimension et la modifie ainsi que son tableau et liberer la mémoire
	friend std::istream& operator>>(std::istream&, vecteur&);

	//Redefinition de l'operateur [] pour acceder au element et pourvoir les modifier
	float& operator[](const int position);

	/**
	*si l'on souhaite uniquement consulter la valeur on devra declarer la surcharge comme ceci
	*___const float& operator[](const int position)const;
	* On revoie quand meme une reference pour eviter une copie inutile et l'implementation restera inchanger
	*/

};

//fonction pour afficher le vecteur
void afficherVecteur(const vecteur* v, std::ostream& out = std::cout);

//Fonction qui initialise un vecteur grace au donne rentre par l'utilisateur
vecteur* lireVecteur(std::istream& in = std::cin);

//fonction pour additionner deux vecteur
vecteur add(const vecteur* v1, const vecteur* v2);

//surcharge de l'operateur * pour le produit scalaire
float operator*(const vecteur& v1, const vecteur& v2);

//operateur d'affichage de vecteur
std::ostream& operator<<(std::ostream&,vecteur&);

//operateur de saisie de vecteur
std::istream& operator>>(std::istream&,vecteur&);



