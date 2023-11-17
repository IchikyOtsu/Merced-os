//#include "/home/ichiky/Documents/Merced'OS/UseCSV/FichierH/utils/pilotes.h"
#include "utilities/pilote.h"
#include "utilities/random.h"
int main() {
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;
    if (lireFichierCSV("./data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return 1 ;  // Sortir de la fonction en cas d'erreur
    }
    float tempsSecteurs[4];
    genererTempsAleatoires(20001, 25000, tempsSecteurs); // Utilisez min = 20001 ms et max = 25000 ms

    // Afficher les temps
    printf("S1: %.3f, S2: %.3f, S3: %.3f, Tour: %.3f\n", 
           tempsSecteurs[0], tempsSecteurs[1], tempsSecteurs[2], tempsSecteurs[3]);





    if (sauvegarderFichierCSV("data/pilotes.csv", joueurs, ligneIndex) != 0) {
        return 1;
    }
}
