#ifndef CIRCUITS_H
#define CIRCUITS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGNES 25

struct Circuits {
    char Course[50];
    char Ville[50];
    char DATE[10];
    char Pays[50];
    char Nom[50];
    float Taille;
    char Race[50];
    char Circuit[50];
    char Date[10];
};

int lireFichierCSV_circuits(const char *nomFichier, struct Circuits circuits[]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    char ligne[1024];
    int i = 0;

    // Ignorer la première ligne
    fgets(ligne, sizeof(ligne), fichier);

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Utiliser sscanf pour extraire les valeurs de la ligne
        sscanf(ligne, "%49[^;];%49[^;];%9[^;];%49[^;];%49[^;];%f;%49[^;];%49[^;];%9[^;]",
               circuits[i].Course, circuits[i].Ville, circuits[i].DATE, circuits[i].Pays,
               circuits[i].Nom, &circuits[i].Taille, circuits[i].Race, circuits[i].Circuit,
               circuits[i].Date);

        i++;

        if (i >= MAX_LIGNES) {
            break;  // Limiter le nombre de lignes lues pour éviter le dépassement de tableau
        }
    }

    fclose(fichier);

    return i;  // Retourne le nombre de lignes lues
}

#endif
