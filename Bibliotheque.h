#pragma once

#include <unordered_map>
#include <string>
#include "Livre.h"
#include "Emprunteur.h"
#include "Pret.h"

class Bibliotheque {
private:
    std::unordered_map<std::string, Livre*> livres; // Clé : ISBN, Valeur : pointeur vers Livre.
    std::unordered_map<std::string, Emprunteur*> emprunteurs; // Clé : ID de l'emprunteur, Valeur : pointeur vers Emprunteur.
    std::unordered_map<std::string, Pret*> prets; // Clé : ISBN, Valeur : pointeur vers Pret.

public:
    Bibliotheque(); // Constructeur
    ~Bibliotheque(); // Destructeur
    
    
    void ajouterLivre(Livre* livre); // Ajoute un livre à la bibliothèque.
    void ajouterEmprunteur(Emprunteur* emprunteur); // Ajoute un emprunteur à la bibliothèque.
    void effectuerPret(Emprunteur* emprunteur, Livre* livre); // Effectue un prêt si possible.
    void retournerLivre(Livre* livre); // Marque un livre comme retourné.
    void afficherStatistiques(); // Affiche des statistiques basiques de la bibliothèque.
};


