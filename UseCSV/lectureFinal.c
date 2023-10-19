#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100  
#define MAX_FIELDS 7   

struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
};

int main() {
    FILE *fichier = fopen("pilotes.csv", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1024];
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;

    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        fclose(fichier);
        return 1; // Gestion de l'erreur si le fichier est vide
    }

    while (fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, ",");
        int fieldIndex = 0;
        while (token != NULL) {
            switch (fieldIndex) {
                case 0:
                    joueurs[ligneIndex].nb = atoi(token);
                    break;
                case 1:
                    joueurs[ligneIndex].Num = atoi(token);
                    break;
                case 2:
                    strcpy(joueurs[ligneIndex].Prenom, token);
                    break;
                case 3:
                    strcpy(joueurs[ligneIndex].Nom, token);
                    break;
                case 4:
                    strcpy(joueurs[ligneIndex].Team, token);
                    break;
                case 5:
                    strcpy(joueurs[ligneIndex].Naissance, token);
                    break;
                case 6:
                    strcpy(joueurs[ligneIndex].Nationalite, token);
                    break;
                default:
                    break;
            }
            fieldIndex++;
            token = strtok(NULL, ",");
        }
        ligneIndex++;
    }

    fclose(fichier);

    // Afficher toutes les informations des joueurs
    for (int i = 0; i < ligneIndex; i++) {
        printf("Joueur %d:\n", i + 1);
        printf("nb: %d\n", joueurs[i].nb);
        printf("Num: %d\n", joueurs[i].Num);
        printf("Prénom: %s\n", joueurs[i].Prenom);
        printf("Nom: %s\n", joueurs[i].Nom);
        printf("Team: %s\n", joueurs[i].Team);
        printf("Naissance: %s\n", joueurs[i].Naissance);
        printf("Nationalité: %s\n", joueurs[i].Nationalite);
        printf("\n");
    }

    return 0;
}

