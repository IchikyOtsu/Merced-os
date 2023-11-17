#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Génère un temps aléatoire pour un tour et trouve le temps minimum parmi un nombre donné de tours.
 *
 * @param nbrTours Le nombre de tours pour lesquels générer des temps aléatoires.
 * @return Le temps minimum trouvé parmi tous les tours, en secondes.
 */
float zdds(int nbrTours) {
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


void genererTempsAleatoires(int min, int max, float temps[4]) {
    // Initialiser le générateur de nombres aléatoires
    //srand(time(NULL));

    // Générer des temps aléatoires pour chaque secteur
    temps[0] = (rand() % (max - min + 1) + min) / 1000.0f; // S1
    temps[1] = (rand() % (max - min + 1) + min) / 1000.0f; // S2
    temps[2] = (rand() % (max - min + 1) + min) / 1000.0f; // S3

    // Calculer le temps total du tour
    temps[3] = temps[0] + temps[1] + temps[2]; // Tour
}




#endif  // RANDOM_H
