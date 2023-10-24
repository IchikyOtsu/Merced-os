#ifndef PILOTES_H
#define PILOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100  
#define MAX_FIELDS 10 

struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
    int P1;
    int P2;
    int P3;
    int Q1;
    int Q2;
    int Q3;
    int RACE;
    
};

/// Fonction pour lire un fichier CSV et renvoyer un tableau de structures
int lireFichierCSV(const char *nomFichier, struct Joueur joueurs[], int *ligneIndex) {
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1024];

    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        fclose(fichier);
        return 1; // Gestion de l'erreur si le fichier est vide
    }

    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = 0;

        if (ligne[0] == '\0') {
            continue;
        }

        char *token = strtok(ligne, ",");
        int fieldIndex = 0;
        while (token != NULL) {
            switch (fieldIndex) {
                case 0:
                    joueurs[*ligneIndex].nb = atoi(token);
                    break;
                case 1:
                    joueurs[*ligneIndex].Num = atoi(token);
                    break;
                case 2:
                    strcpy(joueurs[*ligneIndex].Prenom, token);
                    break;
                case 3:
                    strcpy(joueurs[*ligneIndex].Nom, token);
                    break;
                case 4:
                    strcpy(joueurs[*ligneIndex].Team, token);
                    break;
                case 5:
                    strcpy(joueurs[*ligneIndex].Naissance, token);
                    break;
                case 6:
                    strcpy(joueurs[*ligneIndex].Nationalite, token);
                    break;
                case 7:
                    joueurs[*ligneIndex].P1= atoi(token);
                    break;
                case 8:
                    joueurs[*ligneIndex].P2= atoi(token);
                    break;
                case 9:
                    joueurs[*ligneIndex].P3= atoi(token);
                    break;
                case 10:
                    joueurs[*ligneIndex].Q1= atoi(token);
                    break;
                case 11:
                    joueurs[*ligneIndex].Q2= atoi(token);
                    break;
                case 12:
                    joueurs[*ligneIndex].Q3= atoi(token);
                    break;
                case 13:
                    joueurs[*ligneIndex].RACE= atoi(token);
                    break;
                default:
                    break;
            }
            fieldIndex++;
            token = strtok(NULL, ",");
        }
        (*ligneIndex)++;
    }

    fclose(fichier);
    return 0;
}

// Fonction pour sauvegarder un tableau de structures dans un fichier CSV
int sauvegarderFichierCSV(const char *nomFichier, struct Joueur joueurs[], int ligneIndex) {
    FILE *fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    fprintf(fichier, "nb,Num,Prénom,Nom,Team,Naissance,Nationalité\n");

    for (int i = 0; i < ligneIndex; i++) {
        if (joueurs[i].Prenom[0] != '\0' && joueurs[i].Nom[0] != '\0') {
            fprintf(fichier, "%d,%d,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d\n", joueurs[i].nb, joueurs[i].Num, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team, joueurs[i].Naissance, joueurs[i].Nationalite,joueurs[i].P1,joueurs[i].P2,joueurs[i].P3,joueurs[i].Q1,joueurs[i].Q2,joueurs[i].Q3,joueurs[i].RACE);
        }
    }

    fclose(fichier);
    return 0;
}

#endif
