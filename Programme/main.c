#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdint.h>

#include "algorithms/essais_libre.h"


int selecMen() {

	// Initialiser le générateur de nombres aléatoires
	//srand(time(NULL)); 

	//initialiser la mémoire partager et y metre les inforamations actuelle dedans
	//Initialize();
	

	printf("what dou you wana do :\n");
	printf("1 : Practice session\n");
	printf("2 : The qualifications (Q1/Q2/Q3)\n");
	printf("3 : The race\n");
	
	int choice = 0;
	scanf("\n%d", &choice);
	
	
	switch (choice){
		case 1:
			printf("Practice session\n");
			sessionEssaisLibres(1);
			break;
		case 2:
			printf("The qualifications (Q1/Q2/Q3)\n");
			break;
		case 3:
			printf("The race\n");
			break;
		default:
			printf("Invalid input pleas retry\n");
			break;
	}
	
	return 0;
}


int main(){
    key_t key = ftok("data/shmkeyfile", 65); // générere une clé unique
        if (key == -1) {
        perror("ftok main");
        exit(1);
    }
    
    int shmid;
    struct Joueur joueurs[MAX_LINES];  // Assurez-vous que MAX_LINES est défini
    int ligneIndex = 0;

    // lecture du fihier csv et création de la structure avec les données du fichier
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
    struct Joueur *resultats;
    resultats = (struct Joueur *)shmat(shmid, NULL, 0);
    if ((intptr_t)resultats == -1) {
        perror("shmat");
        exit(1);
    }
    
     // copie des données dans la mémoire partagée
    for (int i = 0; i < ligneIndex; i++) {
        resultats[i] = joueurs[i];
    }
    //printf("test mémoire partager%s\n", resultats[2].Nom); 
    selecMen();
    for (int i = 0; i < ligneIndex; i++) {
        joueurs[i] = resultats[i];
    }
    
    //printf("Nom du joueur modifié : %.3f\n", joueurs[1].P1);
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
}
