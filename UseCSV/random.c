#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculer_temps_aleatoire() {
    return rand() % 11 + 15; // Génère un nombre entre 15 et 25 inclusivement
}

int trouver_temps_minimum() {
    int min_temps = calculer_temps_aleatoire();

    for (int i = 1; i < 10; i++) {
        int temps = calculer_temps_aleatoire();
        if (temps < min_temps) {
            min_temps = temps;
        }
    }

    return min_temps;
}

int main() {
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires avec une graine basée sur le temps

    int temps_min = trouver_temps_minimum();
    printf("Le temps minimum est : %d secondes\n", temps_min);

    return 0;
}
