#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <stdio.h>
#include "pilote.h"
#include "affichageV1.h"

int globalIndexTemps;  // Variable globale pour l'index de temps

// Fonction de comparaison pour le tri des résultats
int comparerResultats(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    if (joueurA->temps[globalIndexTemps] == 0 && joueurB->temps[globalIndexTemps] != 0) return 1;
    if (joueurA->temps[globalIndexTemps] != 0 && joueurB->temps[globalIndexTemps] == 0) return -1;
    if (joueurA->temps[globalIndexTemps] < joueurB->temps[globalIndexTemps]) return -1;
    if (joueurA->temps[globalIndexTemps] > joueurB->temps[globalIndexTemps]) return 1;
    return 0;
}

void afficherClassement(struct Joueur *resultats, int joueurs_qui_roullent, char *que_afficher) {
    struct Joueur *temp = malloc(MAX_LINES * sizeof(struct Joueur));
    if (temp == NULL) {
        perror("malloc failed");
        exit(1);
    }

    // Copier les données dans la copie temporaire
    memcpy(temp, resultats, MAX_LINES * sizeof(struct Joueur));

    // Définir globalIndexTemps en fonction de que_afficher
    if (strcmp(que_afficher, "p2") == 0) {
        globalIndexTemps = INDEX_P2;
    } else if (strcmp(que_afficher, "p3") == 0) {
        globalIndexTemps = INDEX_P3;
    } else {
        globalIndexTemps = INDEX_P1;
    }

    // Trier la copie temporaire
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultats);

    // Afficher la copie temporaire
    affichage(temp, que_afficher, joueurs_qui_roullent);
    free(temp);
}

#endif  // CLASSEMENT_H
