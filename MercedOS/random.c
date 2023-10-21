#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculer_temps_aleatoire() {
    return rand() % 21 + 25; // Génère un nombre entre 25 et 45 inclusivement (entre 0 et 20 puis ajoute 25)	
}

int trouver_temps_minimum() {
    int min_temps = calculer_temps_aleatoire();

    for (int i = 1; i < 10; i++) {
        int temps = calculer_temps_aleatoire();
        //printf("%d\n",temps); // Pour voir tous les temps générés
        if (temps < min_temps) {
            min_temps = temps;
        }
    }

    return min_temps;
}

int main() {
    srand(time(NULL)); 

    int temps_min = trouver_temps_minimum();
    printf("Le temps minimum est : %d secondes\n", temps_min);

    return 0;
}
