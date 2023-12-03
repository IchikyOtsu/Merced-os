#ifndef CLASSEMENT_H
#define CLASSEMENT_H
#include <stdio.h>
#include "classement.h"
#include "../utilities/pilote.h"
#include "../utilities/affichageV1.h"


// Fonction de comparaison pour le tri des résultats (par exemple, par temps)
int comparerResultats(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;
    

    
	
    if (joueurA->P1 == 0 && joueurB->P1 != 0) return 1;
    if (joueurA->P1 != 0 && joueurB->P1 == 0) return -1;
    
    // Comparez les critères de classement souhaités (par exemple, S1P1)
    if (joueurA->P1 < joueurB->P1) return -1;
    if (joueurA->P1 > joueurB->P1) return 1;
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

    // Trier la copie temporaire
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultats);

    // Afficher la copie temporaire
    affichage(temp, que_afficher, joueurs_qui_roullent);

}

#endif
