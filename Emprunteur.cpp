#include "Emprunteur.h"
#include <iostream> // Nécessaire pour les opérations d'entrée/sortie

// Constructeur de la classe Emprunteur.
Emprunteur::Emprunteur(const std::string& id, const std::string& nom, bool aCarte)
: id(id), nom(nom), aCarte(aCarte) {maxLivres = aCarte ? MAX_AVEC_CARTE : MAX_SANS_CARTE;}

bool Emprunteur::peutEmprunter() const {
    return livresEmpruntes.size() < maxLivres;
}
std::string Emprunteur::getId()const {return id;}
// Méthode pour emprunter un livre.
void Emprunteur::emprunterLivre(Livre* livre) {
    
    // Vérifie si l'emprunteur a atteint sa limite d'emprunt.
    if (!(this->peutEmprunter())) {
        std::cerr << "Erreur : L'emprunteur a atteint sa limite de " << maxLivres << " livres." << std::endl;
        return; // Quitte la méthode si la limite est atteinte.
    }

    // Vérifie si le livre est disponible pour l'emprunt.
    if (livre && livre->estDisponible()) {
        livresEmpruntes[livre->getIsbn()] = livre; // Ajoute le livre à la liste des emprunts.
        livre->emprunter(); // Marque le livre comme emprunté.
    } else if (livre) {
        // Affiche une erreur si le livre n'est pas disponible.
        std::cerr << "Erreur : Le livre n'est pas disponible." << std::endl;
    } else {
        // Affiche une erreur si le livre est nullptr.
        std::cerr << "Erreur : Le pointeur vers le livre est nul." << std::endl;
    }
}

// Méthode pour retourner un livre.
void Emprunteur::retournerLivre(const std::string& isbn) {
    if (livresEmpruntes.find(isbn) != livresEmpruntes.end()) {
        livresEmpruntes[isbn]->retourner();
        livresEmpruntes.erase(isbn);
    } else {
        std::cerr << "Erreur : Ce livre n'a pas ete emprunte par cet emprunteur." << std::endl;
    }
}

