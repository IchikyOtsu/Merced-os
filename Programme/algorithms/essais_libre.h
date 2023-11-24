#ifndef ESSAIS_LIBRE_H
#define ESSAIS_LIBRE_H
#include "../utilities/pilote.h"
#include "../utilities/random.h"
#include "../utilities/drive.h"


// Définir NOMBRE_DE_TOURS quelque part dans votre code




#define NOMBRE_DE_TOURS 60



int sessionEssaisLibres() {

        // Utilisez la même clé que dans le programme principal
    key_t key = ftok("data/shmkeyfile", 65);
    if (key == -1) {
        perror("ftok main");
        exit(1);
    }

    // Obtenez l'identifiant de la mémoire partagée
    int shmid = shmget(key, 0, 0); // 0 pour obtenir la taille actuelle
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attachement de la mémoire partagée
    
    struct Joueur *resultats = (struct Joueur *)shmat(shmid, NULL, 0);
    if ((intptr_t)resultats == -1) {
        perror("shmat");
        exit(1);
    }
    //printf("test mémoire partager%s\n", resultats[2].Nom);
    
    
    
    

    // faire rouller chaque joueur ses 60 tours et récuperer ses meilleurs temps dans un tableau (S1, S2, S3 et le meilleur tour)
    for (int i = 0; i < MAX_LINES; i++) {
    
    	
    	float *meilleursTemps = drive(60);
    	
    	printf("\n------joueur %d -------\n",i);
    	printf("ID du joueur : %d\n", resultats[i].nb);
        printf("Nom du joueur : %s\n", resultats[i].Nom);
    	printf("temps S1 : %f\n", meilleursTemps[0]);  
    	printf("temps S2 : %f\n", meilleursTemps[1]);
    	printf("temps S3 : %f\n", meilleursTemps[2]);
    	printf("temps T1 : %f\n", meilleursTemps[3]);
    	
    	
    	
    	//sauve ces inforamtion dans la mémoire partagée
	resultats[i].S1P1 = meilleursTemps[0];
	resultats[i].S2P1 = meilleursTemps[1];
	resultats[i].S3P1 = meilleursTemps[2];
	resultats[i].P1 = meilleursTemps[3];
	
	
	// Sauvegarde dans le fichier CSV
	if (sauvegarderFichierCSV("data/pilotes.csv", resultats, i+1) != 0) {
        	fprintf(stderr, "Erreur de sauvegarde du fichier CSV.\n");
        	return 1;
    	}
    }
    
     
}


#endif
