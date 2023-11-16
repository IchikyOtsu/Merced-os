#ifndef RANDOMMILI_H
#define RANOMMILI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calculer_temps_aleatoire() {
    return rand() % 20001 + 25000; // Génère un nombre entre 25000 et 45000 inclusivement (entre 0 et 20000 puis ajoute 25000)	
}

int nbrTours;

float trouver_temps_minimum(int nbrTours) {
    float min_temps = 45000.0;
    srand(time(NULL)); 

    for (int i = 0; i < nbrTours; i++) {
        int temps = calculer_temps_aleatoire();
	//printf("%d\n",temps);
        float temps_en_secondes = (float)temps / 1000.0;

        if (temps_en_secondes < min_temps) {
            min_temps = temps_en_secondes;
        }
    }
    
    return min_temps;
}

int main() {
    
    float temps_min = trouver_temps_minimum(60);
    printf("Le temps minimum est : %.3f secondes\n", temps_min);

    return 0;
}

#endif