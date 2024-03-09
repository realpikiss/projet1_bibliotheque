#include "Livre.h"
int Livre::compteurIsbn = 1; // Initialisation du compteur ISBN.

// Constructeur de la classe Livre.
Livre::Livre(const std::string& titre, const std::string& auteur, bool disponible)
    : titre(titre), auteur(auteur), disponible(disponible) {
    // Générer l'ISBN en utilisant le compteur, puis incrémente le compteur.
    isbn = "ISBN" + std::to_string(compteurIsbn++);
}
//Methode pour obtenir ISBN
std::string Livre::getIsbn()const { return isbn; }
// Methode pour obtenir le titre du livre.
std::string Livre::getTitre() const { return this->titre; }

// Methode pour obtenir l'auteur du livre.
std::string Livre::getAuteur() const { return this->auteur; }

// Methode pour verifier si le livre est disponible.
bool Livre::estDisponible() const { return this->disponible; }

// Methode pour marquer le livre comme emprunte.
void Livre::emprunter() { this->disponible = false; }

// Methode pour marquer le livre comme retourne.
void Livre::retourner() { this->disponible = true; }
