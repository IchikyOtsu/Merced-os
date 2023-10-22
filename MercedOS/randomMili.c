#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calculer_temps_aleatoire() {
    return rand() % 20001 + 25000; // Génère un nombre entre 25000 et 45000 inclusivement (entre 0 et 20000 puis ajoute 25000)	
}

float calculer_temps_minimum() {
    float temps_minimum = 45000.0; // Initialisation avec une valeur maximale

    for (int i = 0; i < 60; i++) {
        int temps = calculer_temps_aleatoire();
        //printf("%d\n",temps);
        float temps_en_secondes = (float)temps / 1000.0; // Convertit en secondes

        if (temps_en_secondes < temps_minimum) {
            temps_minimum = temps_en_secondes; // Met à jour le temps minimum si un nouveau minimum est trouvé
        }
    }

    return temps_minimum;
}

int main() {
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires avec le temps actuel

    float temps_minimum = calculer_temps_minimum();

    printf("Le temps minimum est : %.3f secondes\n", temps_minimum);

    return 0;
}