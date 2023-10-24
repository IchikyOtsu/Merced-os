//#include "/home/ichiky/Documents/Merced'OS/UseCSV/FichierH/utils/pilotes.h"
#include "utils/pilotes.h"
int main() {
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;

    // Lire les données à partir du fichier CSV
    if (lireFichierCSV("data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        return 1;
    }
    int temps1 = 500;
	joueurs[6].Q1 = temps1;
    // Ajouter de nouvelles données au tableau (par exemple, ajouter un nouveau joueur)
    /*strcpy(joueurs[ligneIndex].Prenom, "Nouveau");
    strcpy(joueurs[ligneIndex].Nom, "Joueur");
    joueurs[ligneIndex].nb = 23;
    ligneIndex++;*/

    // Sauvegarder les données dans le fichier CSV
    if (sauvegarderFichierCSV("data/pilotes.csv", joueurs, ligneIndex) != 0) {
        return 1;
    }

    return 0;
}
