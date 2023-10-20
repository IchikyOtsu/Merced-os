#include <stdio.h>
#include "mercedos.h" // bibliothèque personnelle

int main() {
    int choice;
    int again = 1;

    while (again) {
        printf("Menu principal :\n");
        printf("1. Dire bonjour\n");
        printf("2. Option 2\n");
        printf("3. Quitter\n");
        printf("Faites un choix : ");

        //penser à rendre ça super robuste pour ne laisser passer que nombre de 1 à 9 par exemple
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hello();
                break;
            case 2:
                ramdom();
                break;
            case 3:
                printf("Au revoir !\n");
                again = 0;
                return 0;
            default:
                printf("Choix non valide. Réessayez.\n");
        }
    }

    return 0;
}
