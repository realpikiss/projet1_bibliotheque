#pragma once

#include <string>
#include <unordered_map>
#include "Livre.h"

class Emprunteur {
private:
    std::string id; // Identifiant unique pour l'emprunteur.
    std::string nom; // Nom de l'emprunteur.
    bool aCarte; // Indique si l'emprunteur possède une carte (permettant plus d'emprunts).
    std::unordered_map<std::string, Livre*> livresEmpruntes; // Cartographie des livres empruntés par l'ISBN.

    static const int MAX_SANS_CARTE = 12; // Limite d'emprunt pour les utilisateurs sans carte.
    static const int MAX_AVEC_CARTE = 40; // Limite d'emprunt pour les utilisateurs avec carte.
    int  maxLivres;
public:
    Emprunteur(const std::string& id, const std::string& nom, bool aCarte = false); // Constructeur.
    std::string getId() const; // Méthode pour obtenir l'ID de l'emprunteur.
    bool peutEmprunter() const; // Vérifie si l'emprunteur peut emprunter un autre livre.
    void emprunterLivre(Livre* livre); // Méthode pour emprunter un livre.
    void retournerLivre(const std::string& isbn); // Méthode pour retourner un livre en utilisant l'ISBN.
};


