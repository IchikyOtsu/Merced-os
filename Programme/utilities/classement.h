#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include <stdio.h>
#include "pilote.h"
#include "affichageV1.h"

int globalIndexTemps;  // Variable globale pour l'index de temps
int s1IndexTemps; // Variable globale pour l'index de temps (permet de calculer le meuilleur s1)
int s2IndexTemps; // Variable globale pour l'index de temps (permet de calculer le meuilleur s2)
int s3IndexTemps; //  Variable globale pour l'index de temps (permet de calculer le meuilleur s3)

//trier sur global
int comparerResultatsglobal(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    if (joueurA->temps[globalIndexTemps] == 0 && joueurB->temps[globalIndexTemps] != 0) return 1;
    if (joueurA->temps[globalIndexTemps] != 0 && joueurB->temps[globalIndexTemps] == 0) return -1;
    if (joueurA->temps[globalIndexTemps] < joueurB->temps[globalIndexTemps]) return -1;
    if (joueurA->temps[globalIndexTemps] > joueurB->temps[globalIndexTemps]) return 1;
    return 0;
}

//trier sur S1
int comparerResultatsS1(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    if (joueurA->temps[s1IndexTemps] == 0 && joueurB->temps[s1IndexTemps] != 0) return 1;
    if (joueurA->temps[s1IndexTemps] != 0 && joueurB->temps[s1IndexTemps] == 0) return -1;
    if (joueurA->temps[s1IndexTemps] < joueurB->temps[s1IndexTemps]) return -1;
    if (joueurA->temps[s1IndexTemps] > joueurB->temps[s1IndexTemps]) return 1;
    return 0;
}

//trier sur S2
int comparerResultatsS2(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    if (joueurA->temps[s2IndexTemps] == 0 && joueurB->temps[s2IndexTemps] != 0) return 1;
    if (joueurA->temps[s2IndexTemps] != 0 && joueurB->temps[s2IndexTemps] == 0) return -1;
    if (joueurA->temps[s2IndexTemps] < joueurB->temps[s2IndexTemps]) return -1;
    if (joueurA->temps[s2IndexTemps] > joueurB->temps[s2IndexTemps]) return 1;
    return 0;
}

//trier sur S3
int comparerResultatsS3(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;

    if (joueurA->temps[s3IndexTemps] == 0 && joueurB->temps[s3IndexTemps] != 0) return 1;
    if (joueurA->temps[s3IndexTemps] != 0 && joueurB->temps[s3IndexTemps] == 0) return -1;
    if (joueurA->temps[s3IndexTemps] < joueurB->temps[s3IndexTemps]) return -1;
    if (joueurA->temps[s3IndexTemps] > joueurB->temps[s3IndexTemps]) return 1;
    return 0;
}
int compNum(const void *a, const void *b) {
    struct Joueur *joueurA = (struct Joueur *)a;
    struct Joueur *joueurB = (struct Joueur *)b;
    if (joueurA->Num < joueurB->Num) return -1;
    if (joueurA->Num > joueurB->Num) return 1;
    return 0;
}
void trierJoueursParNum(struct Joueur *resultat, int nombreDeJoueurs) {
    qsort(resultat, nombreDeJoueurs, sizeof(struct Joueur), compNum);
}


void afficherClassement(struct Joueur *resultats, int joueurs_qui_roullent, char *que_afficher) {
    struct Joueur *temp = malloc(MAX_LINES * sizeof(struct Joueur));
    if (temp == NULL) {
        perror("malloc failed");
        exit(1);
    }

    // Copier les données dans la copie temporaire
    memcpy(temp, resultats, MAX_LINES * sizeof(struct Joueur));

    // Définir globalIndexTemps en fonction de que_afficher
    if (strcmp(que_afficher, "p2") == 0) {
        globalIndexTemps = INDEX_P2;
        s1IndexTemps = INDEX_S1P2;
        s2IndexTemps = INDEX_S2P2;
        s3IndexTemps = INDEX_S3P2;
    } else if (strcmp(que_afficher, "p3") == 0) {
        globalIndexTemps = INDEX_P3;
        s1IndexTemps = INDEX_S1P3;
        s2IndexTemps = INDEX_S2P3;
        s3IndexTemps = INDEX_S3P3;
    } else if (strcmp(que_afficher, "p1") == 0){
        globalIndexTemps = INDEX_P1;
        s1IndexTemps = INDEX_S1P1;
        s2IndexTemps = INDEX_S2P1;
        s3IndexTemps = INDEX_S3P1;
    }else if (strcmp(que_afficher, "q1") == 0){
        globalIndexTemps = INDEX_Q1;
        s1IndexTemps = INDEX_S1Q1;
        s2IndexTemps = INDEX_S2Q1;
        s3IndexTemps = INDEX_S3Q1;
    }
    else if (strcmp(que_afficher, "q2") == 0){
        globalIndexTemps = INDEX_Q2;
        s1IndexTemps = INDEX_S1Q2;
        s2IndexTemps = INDEX_S2Q2;
        s3IndexTemps = INDEX_S3Q2;
    }else if (strcmp(que_afficher, "q3") == 0){
        globalIndexTemps = INDEX_Q3;
        s1IndexTemps = INDEX_S1Q3;
        s2IndexTemps = INDEX_S2Q3;
        s3IndexTemps = INDEX_S3Q3;
    }
    
    // Trouver le plus petit S1
    
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultatsS1);
    float bestS1 = temp[0].temps[s1IndexTemps];
    
    
    // Trouver le plus petit S2
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultatsS2);
    float bestS2 = temp[0].temps[s2IndexTemps];
    
    // Trouver le plus petit S3   
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultatsS3);
    float bestS3 = temp[0].temps[s3IndexTemps];
    
    //printf("%f----%f----%f",bestS1, bestS2, bestS3);
    
    
    // Trier & afficher  la copie temporaire trier sur  global
    qsort(temp, MAX_LINES, sizeof(struct Joueur), comparerResultatsglobal);
    affichage(temp, que_afficher, joueurs_qui_roullent, bestS1, bestS2, bestS3);
    free(temp);
}

#endif  // CLASSEMENT_H
