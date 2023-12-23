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


void p1(struct Joueur *resultats, int joueurs_qui_roullent, float bestS1, float bestS2, float bestS3) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s | %-5s | %-3s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P1", "GAP", "Stand", "OUT");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
	printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | ",
                i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
                resultats[i].Nationalite);
                
         // trouve le best S1 et le met en bleu clair
         if (resultats[i].temps[INDEX_S1P1] == bestS1){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S1P1]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P1]);
         }
         
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S2P1] == bestS2){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S2P1]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P1]);
         }
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S3P1] == bestS3){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S3P1]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P1]);
         }

         
         printf("%-13f | %-13f | %-5s | %-3s\n", resultats[i].temps[INDEX_P1], resultats[0].temps[INDEX_P1]-resultats[i].temps[INDEX_P1], resultats[i].stand == 1 ? "\033[1;31mOui  \033[1;32m" : "Non", resultats[i].out == 1 ? "\033[1;31mOui\033[1;32m" : "Non");

    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
         printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f | %-5s | %-3s\n",
            i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
            resultats[i].Nationalite, resultats[i].temps[INDEX_S1P1], resultats[i].temps[INDEX_S2P1],
            resultats[i].temps[INDEX_S3P1], resultats[i].temps[INDEX_P1], resultats[0].temps[INDEX_P1]-resultats[i].temps[INDEX_P1],
            resultats[i].stand == 1 ? "\033[1;31mOui\033[1;32m" : "Non",
            resultats[i].out == 1 ? "\033[1;31mOui\033[1;32m" : "Non");

    }
    printf("\033[0m");  // Réinitialiser le style
}



void p2(struct Joueur *resultats, int joueurs_qui_roullent, float bestS1, float bestS2, float bestS3) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s | %-5s | %-3s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P2", "GAP", "Stand", "OUT");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
	printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | ",
                i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
                resultats[i].Nationalite);
                
         // trouve le best S1 et le met en bleu clair
         if (resultats[i].temps[INDEX_S1P2] == bestS1){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S1P2]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P2]);
         }
         
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S2P2] == bestS2){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S2P2]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P2]);
         }
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S3P2] == bestS3){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S3P2]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P2]);
         }

         
         printf("%-13f | %-13f | %-5s | %-3s\n", resultats[i].temps[INDEX_P2], resultats[0].temps[INDEX_P2]-resultats[i].temps[INDEX_P2], resultats[i].stand == 1 ? "033[1;31Oui  \033[1;32m" : "Non", resultats[i].out == 1 ? "033[1;31Oui\033[1;32m" : "Non");
    }
    
    printf("\033[0m");  // Réinitialise le style
    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes

    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f | %-5s | %-3s\n",
            i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
            resultats[i].Nationalite, resultats[i].temps[INDEX_S1P2], resultats[i].temps[INDEX_S2P2],
            resultats[i].temps[INDEX_S3P2], resultats[i].temps[INDEX_P2], resultats[0].temps[INDEX_P2]-resultats[i].temps[INDEX_P2],
            resultats[i].stand == 1 ? "033[1;31Oui\033[1;32m" : "Non",
            resultats[i].out == 1 ? "033[1;31Oui\033[1;32m" : "Non");
    }
    printf("\033[0m");  // Réinitialiser le style
}


void p3(struct Joueur *resultats, int joueurs_qui_roullent, float bestS1, float bestS2, float bestS3) {
    printf("\033[1;33m");  // Jaune et gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s | %-5s | %-3s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR : P3", "GAP", "Stand", "OUT");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
	printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | ",
                i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
                resultats[i].Nationalite);
                
         // trouve le best S1 et le met en bleu clair
         if (resultats[i].temps[INDEX_S1P3] == bestS1){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S1P3]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P3]);
         }
         
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S2P3] == bestS2){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S2P3]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P3]);
         }
         
         // trouve le best S2 et le met en bleu clair
         if (resultats[i].temps[INDEX_S3P3] == bestS3){
         	printf("\033[1;36m%-13f \033[1;32m| ", resultats[i].temps[INDEX_S3P3]);
         }else{
         	printf("%-13f | ", resultats[i].temps[INDEX_S1P3]);
         }

         
         printf("%-13f | %-13f | %-5s | %-3s\n", resultats[i].temps[INDEX_P3], resultats[0].temps[INDEX_P3]-resultats[i].temps[INDEX_P3], resultats[i].stand == 1 ? "033[1;31Oui  \033[1;32m" : "Non", resultats[i].out == 1 ? "033[1;31Oui\033[1;32m" : "Non");
    }
    
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | %-13f | %-5s | %-3s\n",
            i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
            resultats[i].Nationalite, resultats[i].temps[INDEX_S1P3], resultats[i].temps[INDEX_S2P3],
            resultats[i].temps[INDEX_S3P3], resultats[i].temps[INDEX_P3], resultats[0].temps[INDEX_P3]-resultats[i].temps[INDEX_P3],
            resultats[i].stand == 1 ? "033[1;31Oui\033[1;32m" : "Non",
            resultats[i].out == 1 ? "033[1;31Oui\033[1;32m" : "Non");


    }
    printf("\033[0m");  // Réinitialiser le style
}





int affichage(struct Joueur *resultats, char *que_afficher, int joueurs_qui_roullent, float bestS1, float bestS2, float bestS3) {
	

    afficherEnTete();
    
    


    if (strcmp(que_afficher, "p1") == 0) {
        p1(resultats, joueurs_qui_roullent, bestS1, bestS2, bestS3);
        
    } else if (strcmp(que_afficher, "p2") == 0) {
    	p2(resultats, joueurs_qui_roullent, bestS1, bestS2, bestS3);

    } else if (strcmp(que_afficher, "p3") == 0) {
    	p3(resultats, joueurs_qui_roullent, bestS1, bestS2, bestS3);

    }  else {
        printf("Mauvais appel du type d'affichage\n");
    }

    return 0;
}

#endif
