#ifndef ESSAIS_LIBRE_H
#define ESSAIS_LIBRE_H
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

// Définir NOMBRE_DE_TOURS quelque part dans votre code
#define NOMBRE_DE_TOURS 60

// Déclaration d'un sémaphore
sem_t sharedMemorySemaphore;
sem_t tourSemaphore;

int sessionEssaisLibres(float nbrTours) {
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

    // Initialisation de toutes les valeurs S1, S2, S3 et P1 à zéro pour chaque joueur
    for (int i = 0; i < MAX_LINES; i++) {
        resultats[i].S1P1 = 0.0;
        resultats[i].S2P1 = 0.0;
        resultats[i].S3P1 = 0.0;
        resultats[i].P1 = 0.0;
    }

    for (int tour = 0; tour < nbrTours; tour++) {
        // Attendre que tous les processus soient prêts pour le nouveau tour
        sem_wait(&tourSemaphore);

        for (int i = 0; i < MAX_LINES; i++) {
            pid_t pid = fork();
            if (pid == -1) {
                // Gestion d'erreur
                perror("fork failed");
                exit(1);
            } else if (pid == 0) {
                float *meilleursTemps = drive(60);

                
                
                /*printf("\n------joueur %d -------\n", i + 1);
                printf("ID du joueur : %d\n", resultats[i].nb);
                printf("Nom du joueur : %s\n", resultats[i].Nom);
                printf("temps S1 : %f\n", meilleursTemps[0]);
                printf("temps S2 : %f\n", meilleursTemps[1]);
                printf("temps S3 : %f\n", meilleursTemps[2]);
                printf("temps T1 : %f\n", meilleursTemps[3]);*/
                

                
                sem_wait(&sharedMemorySemaphore);
                if (resultats[i].S1P1 == 0.0 || meilleursTemps[0] < resultats[i].S1P1) {
                    // Mettez à jour le temps
                    resultats[i].S1P1 = meilleursTemps[0];
                }
                if (resultats[i].S2P1 == 0.0 || meilleursTemps[1] < resultats[i].S2P1) {
                    // Mettez à jour le temps
                    resultats[i].S2P1 = meilleursTemps[1];
                }
                if (resultats[i].S3P1 == 0.0 || meilleursTemps[2] < resultats[i].S3P1) {
                    // Mettez à jour le temps
                    resultats[i].S3P1 = meilleursTemps[2];
                }
                if (resultats[i].P1 == 0.0 || meilleursTemps[3] < resultats[i].P1) {
                    // Mettez à jour le temps
                    resultats[i].P1 = meilleursTemps[3];
                }


                /*// Sauvegarde de ces informations dans la mémoire partagée
                resultats[i].S1P1 = meilleursTemps[0];
                resultats[i].S2P1 = meilleursTemps[1];
                resultats[i].S3P1 = meilleursTemps[2];
                resultats[i].P1 = meilleursTemps[3];
                */

                // Libérez le sémaphore après avoir effectué les opérations sur la mémoire partagée
                sem_post(&sharedMemorySemaphore);

                _exit(0);
            }
            system("clear");
            afficherClassement(resultats, MAX_LINES);
            srand(time(NULL));
            sleep(1);
        }

        for (int i = 0; i < MAX_LINES; i++) {
            wait(NULL);
        }
        sem_post(&tourSemaphore);
        
    }

    // Sauvegarde dans le fichier CSV
    if (sauvegarderFichierCSV("data/pilotes.csv", resultats, MAX_LINES) != 0) {
        fprintf(stderr, "Erreur de sauvegarde du fichier CSV.\n");
        return 1;
    }

    // Détacher le segment de mémoire partagée
    if (shmdt(resultats) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Détruire le sémaphore
    sem_destroy(&sharedMemorySemaphore);
    sem_destroy(&tourSemaphore);
}

#endif
