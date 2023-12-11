#include <stdio.h>
#include <string.h>

struct Joueur {
    int nb;
    int Num;
    char Prenom[50];
    char Nom[50];
    char Team[50];
    char Naissance[15];
    char Nationalite[30];
    int P1;
    int P2;
    int P3;
    int Q1;
    int Q2;
    int Q3;
    int RACE; 
};

typedef int (*CompareFunction)(const struct Joueur *, const struct Joueur *);

struct Joueur* sortPlayers(struct Joueur *players, int numPlayers, CompareFunction compare) {
    int i, j;
    struct Joueur temp;

    for (i = 0; i < numPlayers - 1; i++) {
        for (j = i + 1; j < numPlayers; j++) {
            if (compare(&players[i], &players[j]) > 0) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    return players;
}

// Fonction de comparaison pour trier par le champ spécifié (par exemple, P1)
int compare(const struct Joueur *player1, const struct Joueur *player2) {
    return player1->P1 - player2->P1;
}

int main() {
    // Exemple d'utilisation
    struct Joueur joueurs[] = {
        {1, 101, "John", "Doe", "TeamA", "01/01/1990", "USA", 10, 12, 15, 9, 11, 14, 120},
        {2, 102, "Jane", "Smith", "TeamB", "02/02/1995", "Canada", 11, 13, 16, 8, 10, 13, 118},
        {3, 103, "Toto1", "Tutu1", "TeamC", "03/03/1996", "Belgique", 45, 13, 16, 8, 10, 13, 118},
        {4, 104, "Toto2", "Tutu2", "TeamD", "04/04/1994", "France", 26, 13, 16, 8, 10, 13, 118},
        {5, 105, "Toto3", "Tutu3", "TeamE", "05/05/1993", "Espagne", 2, 13, 16, 8, 10, 13, 118},
        {6, 106, "Toto4", "Tutu4", "TeamF", "06/06/1992", "Italie", 1, 13, 16, 8, 10, 13, 118},
        {7, 107, "Toto5", "Tutu5", "TeamG", "07/07/1991", "Suisse", 7, 13, 16, 8, 10, 13, 118},
        {8, 108, "Toto6", "Tutu6", "TeamH", "08/08/1997", "Allemagne", 15, 13, 16, 8, 10, 13, 118},
        
    };

    int numPlayers = sizeof(joueurs) / sizeof(joueurs[0]);

    // Triez les joueurs par le champ P1
    sortPlayers(joueurs, numPlayers, compare);

    // Affichez les joueurs triés
    printf("Joueurs triés:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d: %s %s\n", joueurs[i].Num, joueurs[i].Prenom, joueurs[i].Nom);
    }

    return 0;
}
