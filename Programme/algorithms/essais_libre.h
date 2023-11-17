#ifndef ESSAIS_LIBRE_H
#define ESSAIS_LIBRE_H
#include "../utilities/pilote.h"
#include "../utilities/randommili.h"
#include "../utilities/tour.h"

// Définir NOMBRE_DE_TOURS quelque part dans votre code
#define NOMBRE_DE_TOURS 30
int sessionEssaisLibres() {
    struct Joueur joueurs[MAX_LINES];
    int ligneIndex = 0;

    // Lire les données des pilotes à partir du fichier CSV
    if (lireFichierCSV("./data/pilotes.csv", joueurs, &ligneIndex) != 0) {
        fprintf(stderr, "Erreur de lecture du fichier CSV.\n");
        return 1 ;  // Sortir de la fonction en cas d'erreur
    }
    srand(time(NULL)); 
    //printf("%d",ligneIndex);
    // Simuler les sessions d'essais libres pour chaque pilote
    for (int i = 0; i < ligneIndex; i++) {
        // Ici, on peut simuler un certain nombre de tours pour chaque pilote
        // et enregistrer leur meilleur temps dans la structure Joueur
        
            float temps = drive(NOMBRE_DE_TOURS);
            printf("%f",temps);
            joueurs[i].P1 = temps;
            
                
            
        

        // Afficher les résultats pour chaque pilote
        printf("Pilote %s %s (Voiture %d) - Meilleur temps en essais libres : %.3f secondes\n", 
        joueurs[i].Prenom, joueurs[i].Nom, joueurs[i].Num, joueurs[i].P1);

    }
    if (sauvegarderFichierCSV("data/pilotes.csv", joueurs, ligneIndex) != 0) {
        return 1;
    }
    

    // Vous pouvez choisir de sauvegarder les résultats dans le fichier CSV ou dans un autre fichier
}


#endif
