#ifndef CLASSEMENT_H
#define CLASSEMENT_H
#include <stdio.h>
#include "classement.h"
#include "../utilities/pilote.h" // Incluez le fichier d'en-tête des structures nécessaires

// Fonction de comparaison pour le tri des résultats (par exemple, par temps)
int comparerResultats(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;
    
    // Comparez les critères de classement souhaités (par exemple, S1P1)
    if (joueurA->S1P1 < joueurB->S1P1) return -1;
    if (joueurA->S1P1 > joueurB->S1P1) return 1;
    return 0;
}

void afficherClassement(struct Joueur *resultats, int nombreDeJoueurs) {
    // Triez les résultats en utilisant la fonction de comparaison
    qsort(resultats, nombreDeJoueurs, sizeof(struct Joueur), comparerResultats);

    // Affichez le classement trié
    printf("Classement :\n");
    for (int i = 0; i < nombreDeJoueurs; i++) {
        printf("Position %d - Nom : %s, Temps : %.2f\n", i + 1, resultats[i].Nom, resultats[i].S1P1);
    }
}


#endif
