#ifndef AFFICHAGEV1_H
#define AFFICHAGEV1_H
#include <stdio.h>
#include "pilote.h"





void afficherEnTete() {
    printf("\033[1;35m");  // Violet et gras
    printf(" ||\\\\     //|| ||||||||  __      .__  __        .__ __________        \n");
    printf(" || \\\\   // || ||       \\__ __|__|/  |_  ____ |__|\\______   \\_____  \n");
    printf(" ||  \\\\=//  || ||=====  \\    |  |  \\  \\   __\\/ __ \\|  ||     ___/\\__  \\ \n");
    printf(" ||         || ||=====   /  ||  | \\  ___/|  ||    |     / __ \\_\n");
    printf(" ||         || ||        >__||____|    (____  /\\_\n");
    printf(" ||         || ||||||||  |__|             \\/                   \\/    \n");
    printf("\n");

    printf("\033[0m");  // Réinitialise le style
}


void q1(struct Joueur *resultats, int joueurs_qui_roullent) {
	
    
    printf("\033[1;33m");  // Jaune et  gras pour l'en-tête
    printf("%-8s | %-4s | %-15s | %-15s | %-20s | %-20s | %-13s | %-13s | %-13s | %-13s | %-13s\n",
           "position", "Num", "Prenom", "Nom", "Team", "Nationalite", "S1", "S2", "S3", "TOUR", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes

    for (int i = 0; i < joueurs_qui_roullent; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | /\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].S1P1, resultats[i].S2P1,
               resultats[i].S3P1, resultats[i].P1);
    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = joueurs_qui_roullent; i < MAX_LINES; ++i) {
        printf("%-8d | %-4d | %-15s | %-15s | %-20s | %-20s | %-13f | %-13f | %-13f | %-13f | /\n",
               i+1, resultats[i].Num, resultats[i].Prenom, resultats[i].Nom, resultats[i].Team,
               resultats[i].Nationalite, resultats[i].S1P1, resultats[i].S2P1,
               resultats[i].S3P1, resultats[i].P1);
    }
    printf("\033[0m");  // Réinitialiser le style
}
/*
void q2(struct Joueur joueurs[], int taille) {
    afficherEnTete();
    printf("\033[1;33m");  // Jaune et en gras pour l'en-tête
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1P1", "S2P1", "S3P1", "TP1", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 10 premières lignes
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1P1", "S2P1", "S3P1", "TP1", "GAP");
    

    for (int i = 0; i < 10; ++i) {
        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1P1, joueurs[i].S2P1,
               joueurs[i].S3P1, joueurs[i].TP1, joueurs[i].TP1 - joueurs[i > 0 ? i - 1 : 0].TP1);
    }
    printf("\033[0m");  // Réinitialiser le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 10 dernières lignes
    for (int i = taille - 10; i < taille; ++i) {
        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1P1, joueurs[i].S2P1,
               joueurs[i].S3P1, joueurs[i].TP1, joueurs[i].TP1 - joueurs[i > 0 ? i - 1 : 0].TP1);
    }
    printf("\033[0m");  // Réinitialiser le style
}

void q3(struct Joueur joueurs[], int taille) {
    int gap[taille];
    gap[0] = joueurs[0].TP1;
    afficherEnTete();
    printf("\033[1;33m");  // Jaune et en gras pour l'en-tête
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1P1", "S2P1", "S3P1", "TP1", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    for (int i = 0; i < taille; ++i) {
        // Calculer le GAP à partir du deuxième élément
        if (i > 0) {
            gap[i] = joueurs[i].TP1 - joueurs[i - 1].TP1;
        }

        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1P1, joueurs[i].S2P1,
               joueurs[i].S3P1, joueurs[i].TP1, gap[i]);
    }
}


void p(struct Joueur joueurs[], int taille) {
    int gap[taille];
    gap[0] = joueurs[0].TP1;
    afficherEnTete();
    printf("\033[1;33m");  // Jaune et en gras pour l'en-tête
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1P1", "S2P1", "S3P1", "TP1", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    for (int i = 0; i < taille; ++i) {
        // Calculer le GAP à partir du deuxième élément
        if (i > 0) {
            gap[i] = joueurs[i].TP1 - joueurs[i - 1].TP1;
        }

        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1P1, joueurs[i].S2P1,
               joueurs[i].S3P1, joueurs[i].TP1, gap[i]);
    }
}

void q1 (){
	printf("aaaaaa\n");
}
*/


void q2 (){
	printf("eeeee\n");
}


int affichage(struct Joueur *resultats, char *part, int joueurs_qui_roullent) {
	//printf("%d\n", resultats[1].S1P1);
	

    afficherEnTete();
    


    if (strcmp(part, "q1") == 0) {
        q1(resultats, joueurs_qui_roullent);
        
    } else if (strcmp(part, "q2") == 0) {
    	q2();

    } else {
        printf("Mauvais appel du type d'affichage\n");
    }

    return 0;
}

#endif





















