#ifndef CLASSEMENT_H
#define CLASSEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilote.h"

// Fonction pour comparer deux pilotes en fonction d'une colonne spécifique
int comparerJoueurs(const void *a, const void *b, int colonne) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    // Exemple de comparaison pour une colonne de temps (float)
    switch (colonne) {
        case 1: // Comparaison sur la base de P1
            return (joueurA->P1 > joueurB->P1) - (joueurA->P1 < joueurB->P1);
        // Ajoutez des cas pour d'autres colonnes ici
    }
    return 0;
}

void afficherClassement(int colonne) {
    struct Joueur joueurs[25];
    int ligneIndex = 0;

    // Lire les données des pilotes depuis le fichier CSV
    if (lireFichierCSV("data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return;  // Sortir de la fonction en cas d'erreur
    }
    memcpy(joueursTries, joueurs, sizeof(struct Joueur) * ligneIndex);

    // Tri des joueurs en fonction de la colonne spécifiée
    qsort(joueursTries, ligneIndex, sizeof(struct Joueur), comparerJoueurs, colonne);

    // Affichage du classement
    for (int i = 0; i < ligneIndex; i++) {
        printf("Position %d: Pilote %s %s, Voiture %d, Temps : %.2f\n", 
               i + 1, joueursTries[i].Prenom, joueursTries[i].Nom, joueursTries[i].Num, joueursTries[i].P1);
    }
}
#endif