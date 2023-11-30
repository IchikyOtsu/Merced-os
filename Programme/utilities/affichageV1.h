#ifndef AFFICHAGEV1_H
#define AFFICHAGEV1_H
#include <stdio.h>
#include "pilote.h"

struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
    float S1P1;
    float S2P1;
    float S3P1;
    float P1;

    float S1P2;
    float S2P2;
    float S3P2;
    float P2;

    float S1P3;
    float S2P3;
    float S3P3;
    float P3;

    float S1Q1;
    float S2Q1;
    float S3Q1;
    float Q1;

    float S1Q2;
    float S2Q2;
    float S3Q2;
    float Q2;

    float S1Q3;
    float S2Q3;
    float S3Q3;
    float Q3;

    float S1R;
    float S2R;
    float S3R;
    float RACE;
    
};


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

void q1(struct Joueur joueurs[], int taille) {
    afficherEnTete();
    printf("\033[1;33m");  // Jaune et  gras pour l'en-tête
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1Q1", "S2Q1", "S3Q1", "TP1", "GAP");
    printf("\033[0m");  // Réinitialiser le style

    printf("\033[1;34m");  // Bleu et en gras pour la ligne de séparation
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");  // Réinitialiser le style
    printf("\033[1;32m");  // Vert et en gras pour les 15 premières lignes
    printf("%-4s | %-4s | %-15s | %-15s | %-20s | %-20s | %-5s | %-5s | %-5s | %-5s | %-5s\n",
           "Num", "Nb", "Prenom", "Nom", "Team", "Nationalite", "S1Q1", "S2Q1", "S3Q1", "TP1", "GAP");
    

    for (int i = 0; i < 15; ++i) {
        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1Q1, joueurs[i].S2Q1,
               joueurs[i].S3Q1, joueurs[i].TP1, joueurs[i].TP1 - joueurs[i > 0 ? i - 1 : 0].TP1);
    }
    printf("\033[0m");  // Réinitialise le style

    printf("\n\033[1;31m");  // Rouge et en gras pour les 5 dernières lignes
    for (int i = 15; i < taille; ++i) {
        printf("%-4d | %-4d | %-15s | %-15s | %-20s | %-20s | %-5d | %-5d | %-5d | %-5d | %-5d\n",
               joueurs[i].Num, joueurs[i].nb, joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Team,
               joueurs[i].Nationalite, joueurs[i].S1P1, joueurs[i].S2P1,
               joueurs[i].S3P1, joueurs[i].TP1, joueurs[i].TP1 - joueurs[i > 0 ? i - 1 : 0].TP1);
    }
    printf("\033[0m");  // Réinitialiser le style
}

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

int main() {
    struct Joueur joueurs[20] = {
        {1, 44, "Lewis", "Hamilton", "Mercedes", "07/01/1985", "British", 750, 800, 780, 135, 0,0},
        {2, 77, "Valtteri", "Bottas", "Mercedes", "28/08/1989", "Finnish", 755, 805, 790, 138, 0,0},
        {3, 33, "Max", "Verstappen", "Red Bull Racing", "30/09/1997", "Dutch", 740, 810, 775, 137,0,0},
        {4, 16, "Charles", "Leclerc", "Ferrari", "16/10/1997", "Monegasque", 755, 798, 785, 139,0,0},
        {5, 3, "Daniel", "Ricciardo", "McLaren", "01/07/1989", "Australian", 748, 802, 782, 136,0,0},
        {6, 55, "Carlos", "Sainz", "Ferrari", "01/09/1994", "Spanish", 752, 799, 788, 140,0,0},
        {7, 10, "Pierre", "Gasly", "AlphaTauri", "07/02/1996", "French", 746, 805, 777, 138,0,0},
        {8, 14, "Fernando", "Alonso", "Alpine", "29/07/1981", "Spanish", 750, 803, 780, 137,0,0},
        {9, 31, "Esteban", "Ocon", "Alpine", "17/09/1996", "French", 749, 807, 778, 138,0,0},
        {10, 22, "Yuki", "Tsunoda", "AlphaTauri", "11/05/2000", "Japanese", 743, 809, 783, 136,0,0},
        {11, 18, "Lance", "Stroll", "Aston Martin", "29/10/1998", "Canadian", 745, 806, 779, 137,0,0},
        {12, 7, "Kimi", "Raikkonen", "Alfa Romeo ", "17/10/1979", "Finnish", 747, 801, 781, 138,0,0},
        {13, 5, "Sebastian", "Vettel", "Aston Martin", "03/07/1987", "German", 748, 804, 784, 139,0,0},
        {14, 63, "George", "Russell", "Williams", "15/02/1998", "British", 742, 811, 776, 137,0,0},
        {15, 47, "Mick", "Schumacher", "Haas", "22/03/1999", "German", 744, 808, 778, 138,0,0},
        {16, 9, "Nikita", "Mazepin", "Haas", "02/03/1999", "Russian", 746, 806, 777, 139,0,0},
        {17, 6, "Nicholas", "Latifi", "Williams", "29/06/1995", "Canadian", 742, 810, 780, 137,0,0},
        {18, 99, "Antonio", "Giovinazzi", "Alfa Romeo Racing", "14/12/1993", "Italian", 745, 807, 779, 138,0,0},
        {19, 20, "Kevin", "Magnussen", "Haas", "05/10/1992", "Danish", 743, 809, 781, 137,0,0},
        {20, 11, "Sergio", "Perez", "Red Bull Racing", "26/01/1990", "Mexican", 750, 808, 782, 139,0,0},
    };
    int taille = sizeof(joueurs) / sizeof(joueurs[0]);
    char mot[10];

    printf("Entrez un mot : ");
    scanf("%s", mot);

    switch (mot[0]) {
        case 'p':
            // Action pour le mot "P"
            p(joueurs, taille);
            break;

        case 'q':
            switch (mot[1]) {
                case '1':
                    // Action pour le mot "Q1"
                    q1(joueurs, taille);
                    break;

                case '2':
                    // Action pour le mot "Q2"
                    q2(joueurs, taille);
                    break;

                case '3':
                    // Action pour le mot "Q3"
                    q3(joueurs, taille);
                    break;

                default:
                    printf("Mot inconnu commençant par 'Q'\n");
            }
            break;

        case 'c':
            // Action pour le mot "course"
            p(joueurs, taille);
            break;

        default:
            printf("Mauvais appel du type d'affichage\n");
            break;
    }

    return 0;
}

#endif
