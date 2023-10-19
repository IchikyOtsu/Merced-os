#include "pilotes.h"

int main() {
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;

    // Lire les données à partir du fichier CSV
    if (lireFichierCSV("pilotes.csv", joueurs, &ligneIndex) != 0) {
        return 1;
    }

    // Ajouter de nouvelles données au tableau (par exemple, ajouter un nouveau joueur)
    strcpy(joueurs[ligneIndex].Prenom, "Nouveau");
    strcpy(joueurs[ligneIndex].Nom, "Joueur");
    joueurs[ligneIndex].nb = 23;
    ligneIndex++;

    // Sauvegarder les données dans le fichier CSV
    if (sauvegarderFichierCSV("pilotes.csv", joueurs, ligneIndex) != 0) {
        return 1;
    }

    return 0;
}

