#ifndef CLASSEMENT_H
#define CLASSEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilote.h"

// Variable globale pour la colonne de tri (à utiliser avec précaution)
static int colonneDeTri;

// Fonction pour comparer deux pilotes
int comparerJoueurs(const void *a, const void *b) {
    const struct Joueur *joueurA = (const struct Joueur *)a;
    const struct Joueur *joueurB = (const struct Joueur *)b;

    switch (colonneDeTri) {
        case 1:
            return (joueurA->P1 > joueurB->P1) - (joueurA->P1 < joueurB->P1);
        case 2:
            return (joueurA->P2 > joueurB->P2) - (joueurA->P2 < joueurB->P2);
        // Ajoutez des cas pour d'autres colonnes ici
    }
    return 0;
}


void afficherClassement(int colonne) {
    struct Joueur joueurs[25], joueursTries[25];
    int ligneIndex = 0;

    // Lire les données des pilotes
    if (lireFichierCSV("data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return;
    }
    memcpy(joueursTries, joueurs, sizeof(struct Joueur) * ligneIndex);
    colonneDeTri = colonne;  // Mise à jour de la variable globale

    // Tri des joueurs
    qsort(joueursTries, ligneIndex, sizeof(struct Joueur), comparerJoueurs);

    // Affichage du classement
    for (int i = 0; i < ligneIndex; i++) {
        // Afficher en fonction de la colonne (exemple pour P1)
        printf("Position %d: Pilote %s %s, Voiture %d, Temps : %.2f\n", 
               i + 1, joueursTries[i].Prenom, joueursTries[i].Nom, joueursTries[i].Num, joueursTries[i].P1);
    }
}
#endif
