#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "utilities/pilote.h"
#include "utilities/drive.h"

int main() {
    // Remplacez cette partie par une clé valide
    key_t key = ftok("data/shmkeyfile", 65); // Exemple: ftok avec un fichier et un numéro
        if (key == -1) {
        perror("ftok main");
        exit(1);
    }
    
    int shmid;
    struct Joueur joueurs[MAX_LINES];  // Assurez-vous que MAX_LINES est défini
    int ligneIndex = 0;

    // Vérification de la lecture du fichier CSV
    if (lireFichierCSV("data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return 1;  // Sortir de la fonction en cas d'erreur
    }

    // Création du segment de mémoire partagée
    shmid = shmget(key, ligneIndex * sizeof(struct Joueur), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attachement de la mémoire partagée
    struct Joueur *resultats;  // Déclaration de la variable resultats
    resultats = (struct Joueur *)shmat(shmid, NULL, 0);
    if (resultats == (struct Joueur *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Copie des données dans la mémoire partagée
    for (int i = 0; i < ligneIndex; i++) {
        resultats[i] = joueurs[i];
    }
	//----------------------------------------
    // Appel de la fonction drive
    drive(60, 1);

    for (int i = 0; i < ligneIndex; i++) {
        joueurs[i] = resultats[i];
    }
    printf("Nom du joueur modifié : %.3f\n", joueurs[1].P1);
    // Détachement de la mémoire partagée
    if (shmdt(resultats) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Marquage du segment pour suppression
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Sauvegarde dans le fichier CSV
    if (sauvegarderFichierCSV("data/pilotes.csv", joueurs, ligneIndex) != 0) {
        fprintf(stderr, "Erreur de sauvegarde du fichier CSV.\n");
        return 1;
    }

    return 0;
}
