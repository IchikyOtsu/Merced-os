//#include "/home/ichiky/Documents/Merced'OS/UseCSV/FichierH/utils/pilotes.h"
#include "utilities/pilote.h"
int main() {
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;
    if (lireFichierCSV("./data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return 1 ;  // Sortir de la fonction en cas d'erreur
    }
    if (sauvegarderFichierCSV("data/pilotes.csv", joueurs, ligneIndex) != 0) {
        return 1;
    }
}
