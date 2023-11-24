#ifndef DRIVE_H
#define DRIVE_H

#include "random.h" 
#include "pilote.h" 

void drive(int nbrTours, int indexJoueur) {
    key_t key = ftok("data/shmkeyfile", 65);  // Utilisez la même clé que dans le programme principal
        if (key == -1) {
        perror("ftok drive");
        exit(1);
    }
    int shmid = shmget(key, 0, 0666);  // Taille à 0 pour obtenir l'ID sans allouer de mémoire
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    struct Joueur *joueurs = (struct Joueur *)shmat(shmid, NULL, 0);
    if (joueurs == (struct Joueur *)(-1)) {
        perror("shmat");
        exit(1);
    }

        srand(time(NULL));

    for (int tour = 0; tour < nbrTours; tour++) {
        //cas spéciaux (entrée au stand ou joueur "out")
        /*if (false) {
            if (tour == nbrTours - 1) {
                // Sacrifier le dernier tour pour entrer au stand
                break;
            }
            continue; // Ne pas prendre en compte ce tour
        }

        if (false) {
            break; // Arrêter la course pour ce joueur
        }*/

        // Générer des temps aléatoires pour les secteurs
        float tempsSecteurs[4];
        genererTempsAleatoires(20001, 25000, tempsSecteurs);
        // Enregistrer au premier tour ou si le temps est meilleur
        if (tour == 0 || tempsSecteurs[3] < joueurs[indexJoueur].P1) {
            joueurs[indexJoueur].S1P1 = tempsSecteurs[0];
            joueurs[indexJoueur].S2P1 = tempsSecteurs[1];
            joueurs[indexJoueur].S3P1 = tempsSecteurs[2];
            joueurs[indexJoueur].P1 = tempsSecteurs[3];
        }
    }
    // Détacher le segment
    if (shmdt(joueurs) == -1) {
        perror("shmdt");
        exit(1);
    }
}
#endif