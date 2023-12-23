#ifndef AFFICHAGEV1_H
#define AFFICHAGEV1_H
#include <stdio.h>
#include "pilote.h"





void afficherEnTete() {
    printf("\033[1;35m\n");  // Violet et gras
    printf(" /======================================================================/\n");
    printf(" ||      .-.                                   __                  .-. ||\n");
    printf(" ||       .;|/:                              .'|/.;;.    .-.;;;.`-'    ||\n");
    printf(" ||      .;   :  .-.   .;.::..-.   .-.  .-..'  ';;  `;`-' ;;  (_)      ||\n");
    printf(" ||     .;    :.;.-'   .;   ;    .;.-' :   ;   ;;    :.   `;;;.        ||\n");
    printf(" || .:'.;     : `:::'.;'    `;;;;'`:::'`:::'`.;;     ;'   _   `:       ||\n");
    printf(" ||(__.'      `.                              `;.__.'    (_.;;;'       ||\n");
    printf(" /======================================================================/\n");
    printf("\n");
    printf("\033[0m");  // Réinitialise le style
}


void p1(struct Joueur *resultats, int joueurs_qui_roullent) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P1", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P1], resultats[i].temps[INDEX_S2P1],
               resultats[i].temps[INDEX_S3P1], resultats[i].temps[INDEX_P1], resultats[0].temps[INDEX_P1]-resultats[i].temps[INDEX_P1]);
    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P1], resultats[i].temps[INDEX_S2P1],
               resultats[i].temps[INDEX_S3P1], resultats[i].temps[INDEX_P1], resultats[0].temps[INDEX_P1]-resultats[i].temps[INDEX_P1]);
    }
    printf("\033[0m");  // Réinitialiser le style
}



void p2(struct Joueur *resultats, int joueurs_qui_roullent) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P2", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P2], resultats[i].temps[INDEX_S2P2],
               resultats[i].temps[INDEX_S3P2], resultats[i].temps[INDEX_P2], resultats[0].temps[INDEX_P2]-resultats[i].temps[INDEX_P2]);
    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P2], resultats[i].temps[INDEX_S2P2],
               resultats[i].temps[INDEX_S3P2], resultats[i].temps[INDEX_P2], resultats[0].temps[INDEX_P2]-resultats[i].temps[INDEX_P2]);
    }
    printf("\033[0m");  // Réinitialiser le style
}


void p3(struct Joueur *resultats, int joueurs_qui_roullent) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P3", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P3], resultats[i].temps[INDEX_S2P3],
               resultats[i].temps[INDEX_S3P3], resultats[i].temps[INDEX_P3], resultats[0].temps[INDEX_P3]-resultats[i].temps[INDEX_P3]);
    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].temps[INDEX_S1P3], resultats[i].temps[INDEX_S2P3],
               resultats[i].temps[INDEX_S3P3], resultats[i].temps[INDEX_P3], resultats[0].temps[INDEX_P3]-resultats[i].temps[INDEX_P3]);
    }
    printf("\033[0m");  // Réinitialiser le style
}





int affichage(struct Joueur *resultats, char *que_afficher, int joueurs_qui_roullent) {
	//printf("%f\n", resultats[1].S1P1);
	

    afficherEnTete();
    


    if (strcmp(que_afficher, "p1") == 0) {
        p1(resultats, joueurs_qui_roullent);
        
    } else if (strcmp(que_afficher, "p2") == 0) {
    	p2(resultats, joueurs_qui_roullent);

    } else if (strcmp(que_afficher, "p3") == 0) {
    	p3(resultats, joueurs_qui_roullent);

    }  else {
        printf("Mauvais appel du type d'affichage\n");
    }

    return 0;
}

#endif