#ifndef Q3_H
#define Q3_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include "../utilities/pilote.h"
#include "../utilities/random.h"
#include "../utilities/drive.h"
#include "../utilities/classement.h"
#include "constantes.h"
#define NOMBRE_DE_TOURS 60



int sessionQualif3(float nbrTours) {
    struct Joueur *temp = malloc(MAX_LINES * sizeof(struct Joueur));
    //  même clé que dans le programme principal
    key_t key = ftok("data/shmkeyfile", 65);
    if (key == -1) {
        perror("ftok main");
        exit(1);
    }
    //  l'identifiant de la mémoire partagée
    int shmid = shmget(key, sizeof(struct Joueur) * MAX_LINES, 0666 | IPC_CREAT);
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
    // Initialisation du sémaphore pour la mémoire partagée
    if (sem_init(&sharedMemorySemaphore, 0, 1) != 0) {
        perror("sem_init");
        exit(1);
    }
    // Initialisation du sémaphore pour les tours
    if (sem_init(&tourSemaphore, 0, 1) != 0) {
        perror("sem_init");
        exit(1);
    }
    // Initialisation de toutes les valeurs S1, S2, S3 et Q3 à zéro pour chaque joueur
    for (int i = 0; i < MAX_LINES; i++) {
        resultats[i].temps[INDEX_S1Q3] = 0.0;
        resultats[i].temps[INDEX_S2Q3] = 0.0;
        resultats[i].temps[INDEX_S3Q3] = 0.0;
        resultats[i].temps[INDEX_Q3] = 0.0;
        resultats[i].stand = 0;
        resultats[i].out = 0;
    }

    for (int tour = 0; tour < nbrTours; tour++) {
        // Attendre que tous les processus soient prêts pour le nouveau tour
        sem_wait(&tourSemaphore);
        
        for (int i = 0; i < MAX_LINES-12; i++) {
            pid_t pid = fork();

            srand(time(NULL) ^ getpid());

            if (pid == -1) {
                // Gestion d'erreur
                perror("fork failed");
                exit(1);
            } else if (pid == 0) {
                float *meilleursTemps = drive();
                
                sem_wait(&sharedMemorySemaphore);
                /*printf("\n------joueur %d -------\n", i + 1);
                printf("ID du joueur : %d\n", resultats[i].Num);
                printf("Nom du joueur : %s\n", resultats[i].Nom);
                printf("temps S1 : %f\n", meilleursTemps[0]);
                printf("temps S2 : %f\n", meilleursTemps[1]);
                printf("temps S3 : %f\n", meilleursTemps[2]);
                printf("temps T1 : %f\n", meilleursTemps[3]);*/
                
                //check si la voiture est out
                if(resultats[i].out !=1){
                    

                    // Décider aléatoirement si la voiture va au stand
                    if (resultats[i].stand != 2){
                        if (rand() % 100 < PROBABILITE_STAND * 100) {
                            resultats[i].stand = 1; // La voiture va au stand
                        } else {
                            resultats[i].stand = 0; // La voiture ne va pas au stand
                        }
                    }
                    // Pas obligatoire lors des Practices
                    /*if(tour == nbrTours-1 && resultats[i].stand == 0){
                        resultats[i].stand = 1;
                    }*/
                    if (resultats[i].stand == 0 || resultats[i].stand == 2) {
                        
                        if (resultats[i].temps[INDEX_S1Q3] == 0.0 || meilleursTemps[0]/1000 < resultats[i].temps[INDEX_S1Q3]) {
                            // Mettez à jour le temps
                            resultats[i].temps[INDEX_S1Q3] = meilleursTemps[0] / 1000;
                        }
                        if (resultats[i].temps[INDEX_S2Q3] == 0.0 || meilleursTemps[1]/1000 < resultats[i].temps[INDEX_S2Q3]) {
                            // Mettez à jour le temps
                            resultats[i].temps[INDEX_S2Q3] = meilleursTemps[1] / 1000;
                        }
                        if (resultats[i].temps[INDEX_S3Q3] == 0.0 || meilleursTemps[2]/ 1000 < resultats[i].temps[INDEX_S3Q3]) {
                            // Mettez à jour le temps
                            resultats[i].temps[INDEX_S3Q3] = meilleursTemps[2] / 1000;
                        }
                        if (resultats[i].temps[INDEX_Q3] == 0.0 || meilleursTemps[3]/ 1000 < resultats[i].temps[INDEX_Q3]) {
                            // Mettez à jour le temps
                            resultats[i].temps[INDEX_Q3] = meilleursTemps[3] / 1000;
                        }
                    }
                    
                    // Décider aléatoirement si la voiture quite les practice
                    if (rand() % 100 < PROBABILITE_OUT * 100) {
                            resultats[i].out = 1; // La voiture va au stand
                        } else {
                            resultats[i].out = 0; // La voiture ne va pas au stand
                        }
                }

                
                /*// Sauvegarde de ces informations dans la mémoire partagée
                resultats[i].S1Q3 = meilleursTemps[0];
                resultats[i].S2Q3 = meilleursTemps[1];
                resultats[i].S3Q3 = meilleursTemps[2];
                resultats[i].Q3 = meilleursTemps[3];
                */
                // Libérez le sémaphore après avoir effectué les opérations sur la mémoire partagée
                sem_post(&sharedMemorySemaphore);
                _exit(1);
            }else{
            
                system("clear");

                
                int joueurs_qui_roullent = 10;
                char *que_afficher = "q3";
                afficherClassement(resultats, joueurs_qui_roullent, que_afficher);
                printf("\n\nJoueur N°%d à roullé un temps de : %fs\n\n", resultats[i].Num, resultats[i].temps[INDEX_P1] );
                sleep(1.5);
                //srand(time(NULL));
            }
            
        }
        for (int a = 0; a < MAX_LINES; a++) {
            wait(NULL);
        }
        for (int b = 0; b < MAX_LINES; b++) {
            if (resultats[b].stand == 1){
                resultats[b].stand = 2;
            }
        }
        sem_post(&tourSemaphore);

    }
    //triage pour l'élimination.
    qsort(resultats, MAX_LINES, sizeof(struct Joueur), comparerResultatsglobal);

    // Sauvegarde dans le fichier CSV

    // Détruire le sémaphore
    sem_destroy(&sharedMemorySemaphore);
    sem_destroy(&tourSemaphore);
}


#endif
