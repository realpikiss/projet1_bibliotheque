#include "Bibliotheque.h"
#include <iostream>

Bibliotheque::Bibliotheque() {
   
}

Bibliotheque::~Bibliotheque() {
    //  libérer la mémoire allouée si nécessaire.
    for (auto& livre : livres) {
        delete livre.second;
    }

    for (auto& emprunteur : emprunteurs) {
        delete emprunteur.second;
    }

    for (auto& pret : prets) {
        delete pret.second;
    }
}

void Bibliotheque::ajouterLivre(Livre* livre) {
    if (livre != nullptr) {
           livres[livre->getIsbn()] = livre;
       }
    
}

void Bibliotheque::ajouterEmprunteur(Emprunteur* emprunteur) {
    if (emprunteur != nullptr) {
        emprunteurs[emprunteur->getId()] = emprunteur;
    }
}

void Bibliotheque::effectuerPret(Emprunteur* emprunteur, Livre* livre) {
    if (emprunteur == nullptr || livre == nullptr) {
            std::cerr << "Erreur : L'emprunteur ou le livre est nul." << std::endl;
            return;
        }

        if (!livre->estDisponible()) {
            std::cerr << "Erreur : Le livre n'est pas disponible." << std::endl;
            return;
        }

        if (!emprunteur->peutEmprunter()) {
            std::cerr << "Erreur : L'emprunteur ne peut plus emprunter de livres." << std::endl;
            return;
        }

        Pret* pret = new Pret(emprunteur, livre);  
        prets[livre->getIsbn()] = pret;
        emprunteur->emprunterLivre(livre);
    }

void Bibliotheque::retournerLivre(Livre* livre) {
    if (livre == nullptr) {
        std::cerr << "Erreur : Le livre est nul." << std::endl;
        return;
    }

    auto it = prets.find(livre->getIsbn());
    if (it != prets.end()) {
        // Marquer le livre comme retourné
        livre->retourner();

        // Obtenir l'emprunteur depuis le prêt
        Emprunteur* emprunteur = it->second->getEmprunteur();

        if (emprunteur != nullptr) {
            // Mettre à jour les enregistrements de l'emprunteur
            emprunteur->retournerLivre(livre->getIsbn());
        }

        // Supprimer le prêt de la liste des prêts et libérer la mémoire
        delete it->second;
        prets.erase(it);
    } else {
        std::cerr << "Erreur : Aucun pret trouve pour ce livre." << std::endl;
    }
}

void Bibliotheque::afficherStatistiques() {
    int nombreLivresEmpruntes = 0;

    for (auto& pret : prets) {
        if (pret.second->estPretActif()) {
            nombreLivresEmpruntes++;
        }
    }

    std::cout << "Statistiques de la Bibliotheque :" << std::endl;
    std::cout << "Nombre total de livres : " << livres.size() << std::endl;
    std::cout << "Nombre total d'emprunteurs : " << emprunteurs.size() << std::endl;
    std::cout << "Nombre de livres actuellement empruntes : " << nombreLivresEmpruntes << std::endl;
}
