#ifndef PILOTES_H
#define PILOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 22
#define MAX_FIELDS 40
enum {
    INDEX_S1P1 = 0,
    INDEX_S2P1 = 1,
    INDEX_S3P1 = 2,
    INDEX_P1 = 3,
    INDEX_S1P2 = 4,
    INDEX_S2P2 = 5,
    INDEX_S3P2 = 6,
    INDEX_P2 = 7,
    INDEX_S1P3 = 8,
    INDEX_S2P3 = 9,
    INDEX_S3P3 = 10,
    INDEX_P3 = 11,
    INDEX_S1Q1 = 12,
    INDEX_S2Q1 = 13,
    INDEX_S3Q1 = 14,
    INDEX_Q1 = 15,
    INDEX_S1Q2 = 16,
    INDEX_S2Q2 = 17,
    INDEX_S3Q2 = 18,
    INDEX_Q2 = 19,
    INDEX_S1Q3 = 20,
    INDEX_S2Q3 = 21,
    INDEX_S3Q3 = 22,
    INDEX_Q3 = 23,
    INDEX_S1R = 24,
    INDEX_S2R = 25,
    INDEX_S3R = 26,
    INDEX_RACE = 27
};
struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
    float temps[MAX_FIELDS - 10];  // Tous les temps sont regroupés dans un seul tableau
    int stand;
    int out;
};

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
        for (int fieldIndex = 0; fieldIndex < MAX_FIELDS; fieldIndex++) {
            if (token == NULL) break;

            switch (fieldIndex) {
                case 0: joueurs[*ligneIndex].nb = atoi(token); break;
                case 1: joueurs[*ligneIndex].Num = atoi(token); break;
                case 2: strcpy(joueurs[*ligneIndex].Prenom, token); break;
                case 3: strcpy(joueurs[*ligneIndex].Nom, token); break;
                case 4: strcpy(joueurs[*ligneIndex].Team, token); break;
                case 5: strcpy(joueurs[*ligneIndex].Naissance, token); break;
                case 6: strcpy(joueurs[*ligneIndex].Nationalite, token); break;
                default:
                    if (fieldIndex >= 7 && fieldIndex < MAX_FIELDS - 2) {
                        joueurs[*ligneIndex].temps[fieldIndex - 7] = atof(token);
                    } else if (fieldIndex == MAX_FIELDS - 2) {
                        joueurs[*ligneIndex].stand = atoi(token);
                    } else if (fieldIndex == MAX_FIELDS - 1) {
                        joueurs[*ligneIndex].out = atoi(token);
                    }
                    break;
            }
            token = strtok(NULL, ",");
        }
        (*ligneIndex)++;
    }
    fclose(fichier);
    return 0;
}

const char *nomsTemps[] = {
    "S1P1", "S2P1", "S3P1", "P1", "S1P2", "S2P2", "S3P2", "P2",
    "S1P3", "S2P3", "S3P3", "P3", "S1Q1", "S2Q1", "S3Q1", "Q1",
    "S1Q2", "S2Q2", "S3Q2", "Q2", "S1Q3", "S2Q3", "S3Q3", "Q3",
    "S1R", "S2R", "S3R", "RACE"
};

int sauvegarderFichierCSV(const char *nomFichier, struct Joueur joueurs[], int ligneIndex) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Écriture de l'en-tête
    fprintf(fichier, "nb,Num,Prenom,Nom,Team,Naissance,Nationalite");
    for (int i = 0; i < MAX_FIELDS - 10; i++) {
        fprintf(fichier, ",%s", nomsTemps[i]);
    }
    fprintf(fichier, ",stand,out\n");

    // Écriture des données de chaque joueur
    for (int i = 0; i < ligneIndex; i++) {
        fprintf(fichier, "%d,%d,%s,%s,%s,%s,%s",
                joueurs[i].nb, 
                joueurs[i].Num, 
                joueurs[i].Prenom, 
                joueurs[i].Nom, 
                joueurs[i].Team, 
                joueurs[i].Naissance, 
                joueurs[i].Nationalite);

        for (int j = 0; j < MAX_FIELDS - 10; j++) {
            fprintf(fichier, ",%.3f", joueurs[i].temps[j]);
        }

        fprintf(fichier, ",%d,%d\n", joueurs[i].stand, joueurs[i].out);
    }

    fclose(fichier);
    return 0;
}


#endif
