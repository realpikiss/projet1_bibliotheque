#include <iostream>
#include "Bibliotheque.h"
#include "Livre.h"
#include "Emprunteur.h"
int main() {
    // Création de la bibliothèque
    Bibliotheque bibliotheque;
    // Création de quelques livres
    Livre* livre1 = new Livre("Le Petit Prince", "Antoine de Saint-Exupery");
    Livre* livre2 = new Livre("1984", "George Orwell");
    // Ajout des livres à la bibliothèque
    bibliotheque.ajouterLivre(livre1);
    bibliotheque.ajouterLivre(livre2);
    // Création d'un emprunteur
    Emprunteur* emprunteur1 = new Emprunteur("123", "Jean Dupont");
    // Ajout de l'emprunteur à la bibliothèque
    bibliotheque.ajouterEmprunteur(emprunteur1);
    // L'emprunteur emprunte un livre
    bibliotheque.effectuerPret(emprunteur1, livre1);
    // Affichage de l'état du livre
    std::cout << "Le livre \"" << livre1->getTitre() << "\" est disponible ? " << (livre1->estDisponible() ? "Oui" : "Non") << std::endl;
    // L'emprunteur retourne le livre
    bibliotheque.retournerLivre(livre1);
    // Affichage de l'état du livre après le retour
    std::cout << "Apres retour, le livre \"" << livre1->getTitre() << "\" est disponible ? " << (livre1->estDisponible() ? "Oui" : "Non") << std::endl;
    // Libération de la mémoire
    delete livre1;
    delete livre2;
    delete emprunteur1;
    return 0;
}