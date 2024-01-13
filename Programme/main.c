#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdint.h>
#include <math.h>

#include "algorithms/essais_libre.h"
#include"algorithms/Q1.h"
#include"algorithms/race.h"
#include"utilities/circuits.h"



int selecMen(int nbrTourRace) {

	// Initialiser le générateur de nombres aléatoires
	//srand(time(NULL)); 

	//initialiser la mémoire partager et y metre les inforamations actuelle dedans
	//Initialize();
	

	printf("What do you want to do ? :\n");
	printf("1 : Practice session\n");
	printf("2 : The qualifications (Q1/Q2/Q3)\n");
	printf("3 : The race\n");
	printf("4 : Exit\n");
	int choice = 0;
	scanf("\n%d", &choice);
	
	
	switch (choice){
		case 1:
			printf("Practice session\n");
			sessionEssaisLibres(2);
			break;
		case 2:
			printf("The qualifications (Q1/Q2/Q3)\n");
			sessionQualif(2);
			break;
		case 3:
			printf("The race\n");
            		race(nbrTourRace);
			break;
        case 4:
            return 2;
            break;
		default:
			printf("Invalid input pleas retry\n");
			break;
	}
	
	return 0;
}


int main(int argc, char **argv){
    key_t key = ftok("data/shmkeyfile", 65); // générere une clé unique
        if (key == -1) {
        perror("ftok main");
        exit(1);
    }
    
    // Mettre test comme variable dans argv[1], si l'utilisateur n'a pas mis de parametres au porgrame
    char userRaceInput[50];  
    
    if (argc <= 1) {
	strcpy(userRaceInput, "test");
	argv[1] = userRaceInput;
    }


    
    
    // récuperer les données des circuits
    struct Circuits circuits[MAX_LIGNES];
    int nombreCircuits = lireFichierCSV_circuits("data/circuits.csv", circuits);
    if (nombreCircuits == -1) {
        return 1;  // Erreur lors de l'ouverture du fichier
    }
    
    
    //vérifier que le circuit existe bien et assigner le nombre de tour a la course
    int nbrTourRace = 0;
    int found = 0;
    
    for (int i = 0; i < nombreCircuits; i++) {
	if (strcasecmp(argv[1], circuits[i].Race) == 0){  //strcasecmp => compare sans case sensitive
        	nbrTourRace = round(300/circuits[i].Taille);  // calculer le nombre de tours
        	found = 1;
        }
    }
    
    while (found == 0){
       	system("clear");
    	printf("Enter a correct place for the race from this list :\n");
    	for (int i = 0; i < nombreCircuits; i++) {
    		printf("- %s\n", circuits[i].Race);
    	}
	printf("=> ");
    	fgets(argv[1], 50, stdin);
    	printf("%s", argv[1]);
    	if (argv[1] == NULL) {
        	fprintf(stderr, "Erreur d'allocation mémoire\n");
        	return 1;
    	}
    	
    	//enlever le /n à la fin du fgets
    	size_t len = strlen(argv[1]);
        if (len > 0 && argv[1][len - 1] == '\n') {
            argv[1][len - 1] = '\0';
        }
	
	//check si la course existe bien
	for (int i = 0; i < nombreCircuits; i++) {
		if (strcasecmp(argv[1], circuits[i].Race) == 0){  //strcasecmp => compare sans case sensitive
			nbrTourRace = round(300/circuits[i].Taille); // calculer le nombre de tours
			found = 1;
		}
	}
    }
    
    system("clear");
    printf("\nYou are competing in \033[1;32m%s\033[0m and will do \033[1;32m%d\033[0m laps in the race.\n\n",argv[1], nbrTourRace);
    
    
    
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
    int ret = selecMen(nbrTourRace);
    
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
    if(ret == 2){
        return 0;
    }
    main(argc, argv);
    
}
