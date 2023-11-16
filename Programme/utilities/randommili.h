#ifndef RANDOMMILI_H
#define RANDOMMILI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Génère un temps aléatoire pour un tour et trouve le temps minimum parmi un nombre donné de tours.
 *
 * @param nbrTours Le nombre de tours pour lesquels générer des temps aléatoires.
 * @return Le temps minimum trouvé parmi tous les tours, en secondes.
 */
float trouver_temps_minimum(int nbrTours) {
    //srand(time(NULL));  // Initialisation du générateur de nombres aléatoires
    /*L'appel à srand(time(NULL)) est effectué à chaque fois que la fonction trouver_temps_minimum est appelée. Cela réinitialise le générateur de nombres aléatoires avec une nouvelle graine à chaque appel. Si ces appels sont rapprochés dans le temps (par exemple, lors de la simulation rapide de plusieurs pilotes), time(NULL) pourrait retourner la même valeur, ce qui entraînerait des séquences de nombres aléatoires identiques et donc des temps très similaires pour différents pilotes.*/
    float min_temps = 45.0;  // Initialisation du temps minimum à 45 secondes

    for (int i = 0; i < nbrTours; i++) {
        int temps_ms = rand() % 20001 + 25000;  // Génère un temps aléatoire entre 25000 et 45000 millisecondes
        float temps_s = (float)temps_ms / 1000.0;  // Convertit le temps en secondes

        if (temps_s < min_temps) {
            min_temps = temps_s;  // Met à jour le temps minimum si un temps plus court est trouvé
        }
    }

    return min_temps;
}

#endif  // RANDOMMILI_H
