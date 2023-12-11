#ifndef PILOTES_H
#define PILOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 22
#define MAX_FIELDS 38 

struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
    float S1P1;
    float S2P1;
    float S3P1;
    float P1;

    float S1P2;
    float S2P2;
    float S3P2;
    float P2;

    float S1P3;
    float S2P3;
    float S3P3;
    float P3;

    float S1Q1;
    float S2Q1;
    float S3Q1;
    float Q1;

    float S1Q2;
    float S2Q2;
    float S3Q2;
    float Q2;

    float S1Q3;
    float S2Q3;
    float S3Q3;
    float Q3;

    float S1R;
    float S2R;
    float S3R;
    float RACE;
    
};

/*Structure Joueur :

Cette structure contient toutes les informations nécessaires sur les pilotes, y compris leurs performances dans différentes sessions. C'est une bonne pratique de séparer les données et les opérations sur ces données.

Fonction lireFichierCSV :
Cette fonction lit les données d'un fichier CSV et les stocke dans un tableau de structures Joueur.
L'utilisation de strtok pour diviser les lignes en tokens est adéquate, bien que vous pourriez explorer strsep qui gère mieux les chaînes vides.
Vous gérez bien les erreurs de lecture de fichier.

Fonction sauvegarderFichierCSV :
Cette fonction écrit les données des joueurs dans un fichier CSV.
L'utilisation de fprintf pour écrire dans le fichier est correcte.*/


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
                    joueurs[*ligneIndex].S1P1= atoi(token);
                    break;
                case 8:
                    joueurs[*ligneIndex].S2P1= atoi(token);
                    break;
                case 9:
                    joueurs[*ligneIndex].S3P1= atoi(token);
                    break;
                case 10:
                    joueurs[*ligneIndex].P1= atoi(token);
                    break;
                case 11:
                    joueurs[*ligneIndex].S1P2= atoi(token);
                    break;
                case 12:
                    joueurs[*ligneIndex].S2P2= atoi(token);
                    break;
                case 13:
                    joueurs[*ligneIndex].S3P2= atoi(token);
                    break;
                case 14:
                    joueurs[*ligneIndex].P2= atoi(token);
                    break;
                case 15:
                    joueurs[*ligneIndex].S1P3= atoi(token);
                    break;
                case 16:
                    joueurs[*ligneIndex].S2P3= atoi(token);
                    break;
                case 17:
                    joueurs[*ligneIndex].S3P3= atoi(token);
                    break;
                case 18:
                    joueurs[*ligneIndex].P3= atoi(token);
                    break;
                
                case 19:
                    joueurs[*ligneIndex].S1Q1= atoi(token);
                    break;
                case 20:
                    joueurs[*ligneIndex].S2Q1= atoi(token);
                    break;
                case 21:
                    joueurs[*ligneIndex].S3Q1= atoi(token);
                    break;
                case 22:
                    joueurs[*ligneIndex].Q1= atoi(token);
                    break;

                case 23:
                    joueurs[*ligneIndex].S1Q2= atoi(token);
                    break;
                case 24:
                    joueurs[*ligneIndex].S2Q2= atoi(token);
                    break;
                case 25:
                    joueurs[*ligneIndex].S3Q2= atoi(token);
                    break;

                case 26:
                    joueurs[*ligneIndex].S1Q2= atoi(token);
                    break;
                case 27:
                    joueurs[*ligneIndex].S2Q2= atoi(token);
                    break;
                case 28:
                    joueurs[*ligneIndex].S3Q2= atoi(token);
                    break;
                case 29:
                    joueurs[*ligneIndex].Q2= atoi(token);
                    break;

                case 30:
                    joueurs[*ligneIndex].S1Q3= atoi(token);
                    break;
                case 31:
                    joueurs[*ligneIndex].S2Q3= atoi(token);
                    break;
                case 32:
                    joueurs[*ligneIndex].S3Q3= atoi(token);
                    break;
                case 33:
                    joueurs[*ligneIndex].Q3= atoi(token);
                    break;
                
                case 34:
                    joueurs[*ligneIndex].S1R= atoi(token);
                    break;
                case 35:
                    joueurs[*ligneIndex].S2R= atoi(token);
                    break;
                case 36:
                    joueurs[*ligneIndex].S3R= atoi(token);
                    break;
                case 37:
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

    // Mise à jour de l'en-tête pour inclure tous les champs
    fprintf(fichier, "nb,Num,Prenom,Nom,Team,Naissance,Nationalite,S1P1,S2P1,S3P1,P1,S1P2,S2P2,S3P2,P2,S1P3,S2P3,S3P3,P3,S1Q1,S2Q1,S3Q1,Q1,S1Q2,S2Q2,S3Q2,Q2,S1Q3,S2Q3,S3Q3,Q3,S1R,S2R,S3R,RACE\n");

    for (int i = 0; i < ligneIndex; i++) {
        fprintf(fichier, "%d,%d,%s,%s,%s,%s,%s,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f\n", 
            joueurs[i].nb, 
            joueurs[i].Num, 
            joueurs[i].Prenom, 
            joueurs[i].Nom, 
            joueurs[i].Team, 
            joueurs[i].Naissance, 
            joueurs[i].Nationalite,
            joueurs[i].S1P1, 
            joueurs[i].S2P1, 
            joueurs[i].S3P1, 
            joueurs[i].P1,
            joueurs[i].S1P2, 
            joueurs[i].S2P2, 
            joueurs[i].S3P2, 
            joueurs[i].P2,
            joueurs[i].S1P3, 
            joueurs[i].S2P3, 
            joueurs[i].S3P3, 
            joueurs[i].P3,
            joueurs[i].S1Q1, 
            joueurs[i].S2Q1, 
            joueurs[i].S3Q1, 
            joueurs[i].Q1,
            joueurs[i].S1Q2, 
            joueurs[i].S2Q2, 
            joueurs[i].S3Q2, 
            joueurs[i].Q2,
            joueurs[i].S1Q3, 
            joueurs[i].S2Q3, 
            joueurs[i].S3Q3, 
            joueurs[i].Q3,
            joueurs[i].S1R, 
            joueurs[i].S2R, 
            joueurs[i].S3R, 
            joueurs[i].RACE);
    }

    fclose(fichier);
    return 0;
}


#endif
