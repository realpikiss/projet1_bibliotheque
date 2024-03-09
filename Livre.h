#pragma once

#include <string>

class Livre {
private:
 static int compteurIsbn; // Compteur statique pour générer des ISBN uniques.
    std::string isbn; // ISBN est un attribut privé généré automatiquement.
    std::string titre;
    std::string auteur;
    
    bool disponible;

public:
    // Constructeur qui initialise un livre avec un titre, un auteur et un état (disponible par défaut).
    Livre(const std::string& titre,const std::string & auteur, bool disponible = true);

    // Retourne le titre du livre.
    std::string getTitre() const;

    // Retourne l'auteur du livre.
    std::string getAuteur() const;
    std::string getIsbn() const; // Méthode pour obtenir l'ISBN généré.
    // Vérifie si le livre est disponible.
    bool estDisponible() const;

    // Marque le livre comme emprunté.
    void emprunter();

    // Marque le livre comme retourné (donc disponible).
    void retourner();
};


