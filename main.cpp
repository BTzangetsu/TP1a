#include "vecteur.h"

//lib virtual studio pour la detection de fuite
/*#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


int main() {

	//activation de la detection de fuite
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//DEMANDE A L'UTILISATEUR DE RENTRER UN VECTEUR PUIS L'AFFICHE
	vecteur* vect1 = lireVecteur();
	afficherVecteur(vect1);

	/*
	//______________________________________________________________________________________//
	//QUESTION 3
	//On cherche a modifier une des coordonnées
	int my_coordinate;//<position de changer
	float my_value;//< nouvel valeur

	//on demande d'abord la position
	std::cout << "Quel position souhaitez vous changer?" << std::endl;
	std::cin >> my_coordinate;

	//ensuite la valeur a insere
	std::cout << "Par quelle valeur souhaitez vous remplacer?" << std::endl;
	std::cin >> my_value;
	
	
	//LORSQUE ON ESSAIE DE MODIFIE UNE COORDONNE A UNE POSITION SUPERIEUR OU EGALE A LA DIM,
	//LE PROGRAMME S'INTERROMPE DIRECTEMENT
	vect1->set(my_coordinate, my_value);
	//________________________________________________________________________________________//
	*/

	/*vecteur* vect2 = lireVecteur();
	afficherVecteur(vect2);

	//test operateur +
	vecteur somme = *(vect1) + *(vect2);
	afficherVecteur(&somme);

	//test operateur=
	vecteur af_test(1);
	af_test = somme;
	afficherVecteur(&af_test);

	//test operateur*;
	float prodScal = af_test * somme;
	std::cout << prodScal << std::endl;

	//test operateur<<
	std::cout << af_test;

	//test operateur>>
	std::cin >> af_test;

	delete vect1;
	delete vect2;
	return 0;
}*/