#pragma once
#include <cassert>
#include <iostream>

class vecteur {
private:
    int dim;
    float* tab;

public:
    // Constructeur prenant une dimension et une valeur initiale
    vecteur(int dimension, float default_value);

    // Constructeur avec une dimension par défaut si aucun paramètre n'est fourni
    vecteur(int dimension = 3);

    // Destructeur
    ~vecteur();

    // Constructeur de copie
    vecteur(const vecteur& copied);

    
    // Récupère la valeur d'une dimension spécifique
    const float get(const int position) const;
    
    // Retourne le nombre total de dimensions
    const int getDimension() const;
    
    // Alias de getDimension()
    const int dimensions() const;

  
    
    // Modifie la valeur d'une dimension spécifique
    void set(const int position, float valeur);

    
    vecteur& operator=(const vecteur&);

    /* L'opérateur + retourne un vecteur en valeur pour éviter des problèmes de mémoire.
       Une référence temporaire serait invalide après l'opération. */
    vecteur operator+(const vecteur&);

    // Opérateur ami permettant la saisie d'un vecteur via un flux d'entrée
    friend std::istream& operator>>(std::istream&, vecteur&);

    // Surcharge de l'opérateur [] pour accéder et modifier les éléments
    float& operator[](const int position);
};

// Affichage du vecteur dans un flux de sortie
void afficherVecteur(const vecteur* v, std::ostream& out = std::cout);

// Création d'un vecteur à partir d'une entrée utilisateur
vecteur* lireVecteur(std::istream& in = std::cin);

// Additionne deux vecteurs et retourne le résultat
vecteur add(const vecteur* v1, const vecteur* v2);

// Produit scalaire entre deux vecteurs
float operator*(const vecteur& v1, const vecteur& v2);

// Opérateur de sortie pour afficher un vecteur
std::ostream& operator<<(std::ostream&, vecteur&);

// Opérateur d'entrée pour saisir un vecteur
std::istream& operator>>(std::istream&, vecteur&);
