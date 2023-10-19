/*

Source Internet : Ce programme ne marche pas.



*/








#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure générique pour stocker les données CSV
typedef struct {
    char **columns; // Tableau de noms de colonnes
    char ***data;   // Tableau de données
    int rowCount;
    int columnCount;
} CSVData;

// Fonction pour initialiser
CSVData initCSVData(int rowCount, int columnCount) {
    CSVData csv;
    csv.rowCount = rowCount;
    csv.columnCount = columnCount;
    csv.columns = (char **)malloc(columnCount * sizeof(char *));
    csv.data = (char ***)malloc(rowCount * sizeof(char *));
    for (int i = 0; i < rowCount; i++) {
        csv.data[i] = (char **)malloc(columnCount * sizeof(char *));
    }
    return csv;
}

void freeCSVData(CSVData *csv) {
    for (int i = 0; i < csv->rowCount; i++) {
        for (int j = 0; j < csv->columnCount; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    for (int i = 0; i < csv->columnCount; i++) {
        free(csv->columns[i]);
    }
    free(csv->columns);
}

// Fonction pour lire le fichier CSV et stocker les données dans la structure CSVData
int readCSV(const char *filename, CSVData *csv) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    char line[1024]; // Supposons que la longueur maximale d'une ligne est de 1023 caractères

    // Lire la première ligne (noms des colonnes)
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 1; // Fichier vide
    }

    // Découper les noms de colonnes
    char *token = strtok(line, ",");
    int columnCount = 0;
    while (token != NULL) {
        csv->columns[columnCount] = (char *)malloc(strlen(token) + 1);
        strcpy(csv->columns[columnCount], token);
        token = strtok(NULL, ",");
        columnCount++;
    }
    csv->columnCount = columnCount;

    int rowCount = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue; // Ignorer les lignes vides
        }

        for (int i = 0; i < columnCount; i++) {
            if (token == NULL) {
                continue; // Gérer le cas où il manque des données
            }
            csv->data[rowCount][i] = (char *)malloc(strlen(token) + 1);
            strcpy(csv->data[rowCount][i], token);
            token = strtok(NULL, ",");
        }
        rowCount++;
    }
    csv->rowCount = rowCount;

    fclose(file);
    return 0;
}

// Fonction pour sauvegarder la structure dans le fichier CSV
int saveCSV(const char *filename, CSVData *csv) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    // Écrire la première ligne avec les noms des colonnes
    for (int i = 0; i < csv->columnCount - 1; i++) {
        fprintf(file, "%s,", csv->columns[i]);
    }
    fprintf(file, "%s\n", csv->columns[csv->columnCount - 1]);

    // Écrire les données
    for (int i = 0; i < csv->rowCount; i++) {
        for (int j = 0; j < csv->columnCount - 1; j++) {
            fprintf(file, "%s,", csv->data[i][j]);
        }
        fprintf(file, "%s\n", csv->data[i][csv->columnCount - 1]);
    }

    fclose(file);
    return 0;
}

// Fonction pour ajouter une ligne de données à la structure CSVData
void addData(CSVData *csv, char **rowData) {
    if (csv->rowCount < csv->rowCount) {
        for (int i = 0; i < csv->columnCount; i++) {
            csv->data[csv->rowCount][i] = (char *)malloc(strlen(rowData[i]) + 1);
            strcpy(csv->data[csv->rowCount][i], rowData[i]);
        }
        csv->rowCount++;
    }
}

int main() {
    const char *filename = "pilotes.csv";
    CSVData csv = initCSVData(100, 100); // Supposons un maximum de 100 lignes et 100 colonnes

    if (readCSV(filename, &csv) == 0) {
        // Les données CSV ont été lues avec succès
        // Vous pouvez maintenant ajouter, modifier ou supprimer des données dans la structure

        // Exemple d'ajout de données
        char *newData[] = {"NouveauNom", "30", "AutreColonne"};
        addData(&csv, newData);

        // Sauvegarder la structure modifiée dans le fichier CSV
        if (saveCSV(filename, &csv) == 0) {
            printf("Données sauvegardées avec succès.\n");
        }
    }

    // Libérer la mémoire allouée pour la structure CSVData
    freeCSVData(&csv);

    return 0;
}

