#include "Pret.h"
#include <iostream>

// Constructeur qui initialise le pret, marquant le livre comme emprunte et definissant les dates de debut et de fin.
Pret::Pret(Emprunteur* emprunteur, Livre* livre) : emprunteur(emprunteur), livre(livre), estActif(true) {
    if (livre->estDisponible()) {
        livre->emprunter();
        time(&dateDebut); // Enregistre la date actuelle comme date de debut du pret.
        dateFin = ajouterMois(dateDebut, 1); // Definit la date de fin à un mois après la date de debut.
    } else {
        std::cerr << "Le livre n'est pas disponible pour l'emprunt." << std::endl;
        estActif = false;
    }
}

// Destructeur qui marque le livre comme retourne si le pret est actif.
Pret::~Pret() {
    if (estActif) {
        livre->retourner();
    }
}
//Methode retoutnant l'emprunteur actuel
Emprunteur* Pret::getEmprunteur()const{return emprunteur;}

// Methode permettant de marquer explicitement le livre comme retourne.
void Pret::marquerRetour() {
    if (estActif) {
        livre->retourner();
        estActif = false;
    }
}
bool Pret::estPretActif() const {
    return estActif;
}

// Fonction statique pour ajouter un nombre specifique de mois à une date.
#include <ctime> // Assurez-vous d'inclure l'en-tête ctime
// Fonction statique pour ajouter un nombre spécifique de mois à une date.
std::time_t Pret::ajouterMois(const std::time_t& date, int mois) {
    std::tm date_tm;
    // Utiliser localtime_s au lieu de localtime
    if (localtime_s(&date_tm, &date) != 0) {
        // Gérer l'erreur si localtime_s échoue
        std::cerr << "Erreur lors de la conversion de la date." << std::endl;
        return -1; // ou une valeur d'erreur appropriée
    }
    date_tm.tm_mon += mois; // Ajouter les mois
    // Ajuster l'année si nécessaire (en cas de dépassement de mois)
    while (date_tm.tm_mon > 11) {
        date_tm.tm_mon -= 12;
        date_tm.tm_year++;
    }
    return std::mktime(&date_tm); // Convertir tm struct de retour en time_t
}
