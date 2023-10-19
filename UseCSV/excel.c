#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fichier = fopen("pilotes.csv", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char ligne[1024]; 
    while (fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, ",");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fichier);

    return 0;
}

