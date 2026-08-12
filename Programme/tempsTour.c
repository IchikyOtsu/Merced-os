#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nbrTours = 60;

// Fonction pour générer un temps aléatoire entre min et max
int tempsAleatoire(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

void circuit() {
    srand(time(NULL));

    int tempsTourMin = 9999999;
    int tempsSecteurMin[3];

    for (int tour = 1; tour <= nbrTours; tour++) {
        printf("Tour %d:\n", tour);

        int tempsTour = 0;

        for (int i = 0; i < 3; i++) {
            int tempsSecteur = tempsAleatoire(25000, 45000);
            tempsTour += tempsSecteur;

            printf("    Secteur %d: %.3f secondes\n", i + 1, tempsSecteur/1000.0);

            // Mettre à jour le temps minimum par secteur
            if (tour == 1 || tempsSecteur < tempsSecteurMin[i]) {
                tempsSecteurMin[i] = tempsSecteur;
            }
        }

        printf("    Temps total du tour: %.3f secondes\n", tempsTour/1000.0);

        // Mettre à jour le temps minimum du tour
        if (tour == 1 || tempsTour < tempsTourMin) {
            tempsTourMin = tempsTour;
        }

        printf("\n");
    }

    // Afficher les temps minimum par secteur et le temps minimum du tour
    printf("Temps minimum par secteur:\n");
    for (int secteur = 0; secteur < 3; secteur++) {
        printf("    Secteur %d: %.3f secondes\n", secteur + 1, tempsSecteurMin[secteur]/1000.0);
    }

    printf("Temps minimum du tour: %.3f secondes\n",tempsTourMin/1000.0);
}

int main() {
    circuit();
    return 0;
}
