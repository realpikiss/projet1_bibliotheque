#pragma once

#include <ctime>
#include "Emprunteur.h"
#include "Livre.h"

class Pret {
private:
    Emprunteur* emprunteur; // Pointeur vers l'emprunteur associe au pret.
    Livre* livre; // Pointeur vers le livre associe au pret.
    std::time_t dateDebut; // Date de debut du pret en temps UNIX.
    std::time_t dateFin; // Date de fin du pret en temps UNIX.
    bool estActif; // Indique si le pret est actif.

public:
    // Constructeur qui initialise un pret et definit les dates de debut et de fin.
    Pret(Emprunteur* emprunteur, Livre* livre);
    // Destructeur qui s'assure que le livre est retourne si le pret est toujours actif.
    ~Pret();

    //Retourne un pointeur vers l'emprumteur
    Emprunteur* getEmprunteur()const;
    // Methode pour marquer le livre comme retourne avant la fin de la periode de pret.
    void marquerRetour();

    // Fonction statique pour ajouter un nombre specifique de mois à une date.
    static std::time_t ajouterMois(const std::time_t& date, int mois);
     bool estPretActif() const;  // Méthode pour accéder à l'état du prêt.
};

