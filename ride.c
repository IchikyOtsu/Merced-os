#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //pour la fonction sleep

// Définition de la structure Coureur
struct Coureur {
    int id;
    char nom[50];
    char equipe[50]; // Nom de l'équipe
    char dateNaissance[15]; // Date de naissance au format "jj/mm/aaaa"
    char nationalite[30]; // Nationalité du coureur
    double meilleurTemps; // Meilleur temps pour un tour complet
    double meilleurTempsSecteur[3]; // Meilleurs temps par secteur (tableau de trois valeurs)

};

// Définition de la structure Circuit
struct Circuit {
    char nom[50];
    char pays[30];
    char grandPrix[50];
    double longueur; // En kilomètres
    int virages;
    int zonesDrs;
};

// Fonction pour afficher un coureur
void afficherCoureur(struct Coureur coureur) {
    printf("ID: %d, Nom: %s, Equipe: %s, Date de Naissance: %s, Nationalité: %s\n",
           coureur.id, coureur.nom, coureur.equipe, coureur.dateNaissance, coureur.nationalite);
    printf("Meilleur Temps: %.2f secondes\n", coureur.meilleurTemps);
    printf("Meilleurs Temps par Secteur: %.2f, %.2f, %.2f secondes\n",
           coureur.meilleurTempsSecteur[0], coureur.meilleurTempsSecteur[1], coureur.meilleurTempsSecteur[2]);
}

// Fonction pour afficher un circuit
void afficherCircuit(struct Circuit circuit) {
    printf("Circuit: %s, Pays: %s, Grand Prix: %s, Longueur: %.2f km, Virages: %d, Zones DRS: %d\n",
           circuit.nom, circuit.pays, circuit.grandPrix, circuit.longueur, circuit.virages, circuit.zonesDrs);
}

// Fonction pour générer un temps aléatoire pour un secteur de la piste
double genererTempsSecteur() {
    // Paramètres de la distribution normale (à ajuster selon les besoins)
    double moyenne = 20.0; // Temps moyen en secondes
    double ecartType = 5.0; // Écart type du temps en secondes

    // Génération d'un temps aléatoire suivant une distribution normale
    double temps = (rand() / (double)RAND_MAX) * ecartType + moyenne;

    return temps;
}
/*      Initialisation du générateur de nombres aléatoires
        srand(time(NULL)); à executer avant chaque appel de la fonction 
        sleep(1); à appeller après execution de la fonction*/
        
void ride(struct Coureur chauffeurs[], int nombreTours) {
    for (int tour = 1; tour <= nombreTours; ++tour) {
        printf("\nDébut du tour %d\n", tour);
        
        // Parcours de chaque coureur
        for (int i = 0; i < 20; ++i) {
            double tempsTour = 0.0;

            // Génération de temps pour chaque secteur
            for (int secteur = 0; secteur < 3; ++secteur) {
                double tempsSecteur = genererTempsSecteur();
                tempsTour += tempsSecteur;

                // Mise à jour des meilleurs temps par secteur si nécessaire
                if (tempsSecteur < chauffeurs[i].meilleurTempsSecteur[secteur] || chauffeurs[i].meilleurTempsSecteur[secteur] == 0.0) {
                    chauffeurs[i].meilleurTempsSecteur[secteur] = tempsSecteur;
                }
            }

            printf("Coureur %s, Tour %d, Temps: %.2f secondes\n", chauffeurs[i].nom, tour, tempsTour);

            // Mise à jour du meilleur temps pour un tour complet si nécessaire
            if (tempsTour < chauffeurs[i].meilleurTemps || chauffeurs[i].meilleurTemps == 0.0) {
                chauffeurs[i].meilleurTemps = tempsTour;
            }
        }

        printf("Fin du tour %d\n", tour);
        sleep(1); // Ajout d'une pause entre les tours
    }
}


// Fonction pour comparer les temps de deux chauffeurs pour le tri comme quoi on ne devrait si vite rigoler des cours de monsieur delvigne
int comparerTemps(const void *a, const void *b) {
    const struct Coureur *chauffeurA = (const struct Coureur *)a;
    const struct Coureur *chauffeurB = (const struct Coureur *)b;

    return (chauffeurA->meilleurTemps > chauffeurB->meilleurTemps) - (chauffeurA->meilleurTemps < chauffeurB->meilleurTemps); 
}

// Fonction pour trier les chauffeurs par ordre croissant de temps
void trierChauffeurs(struct Coureur chauffeurs[], int nombreChauffeurs) {
    qsort(chauffeurs, nombreChauffeurs, sizeof(struct Coureur), comparerTemps); // qui disait qu'on ne peut pas faire des dinguerien en C???
}

// Fonction pour enregistrer les résultats dans un fichier texte
void enregistrerResultats(struct Coureur chauffeurs[], int nombreChauffeurs) {
    FILE *fichier = fopen("resultats_course.txt", "w");

    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "Numéro\tEquipe\tNom\tMeilleurTempsTour\tEcart\tMeilleursTempsSecteur\n");

    for (int i = 0; i < nombreChauffeurs; ++i) {
        double differenceSuivant = (i == 0) ?  0.0 : chauffeurs[i].meilleurTemps - chauffeurs[i-1].meilleurTemps ; // petit ternaire kiff

        fprintf(fichier, "%d\t%s\t%s\t%.2f\t%.2f\t%.2f, %.2f, %.2f\n",
                chauffeurs[i].id, chauffeurs[i].equipe, chauffeurs[i].nom,
                chauffeurs[i].meilleurTemps, differenceSuivant,
                chauffeurs[i].meilleurTempsSecteur[0], chauffeurs[i].meilleurTempsSecteur[1], chauffeurs[i].meilleurTempsSecteur[2]);
    }

    fclose(fichier);

    printf("Les résultats ont été enregistrés dans le fichier 'resultats_course.txt'.\n");
}


        
int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Déclaration et initialisation du tableau de chauffeurs
    struct Coureur chauffeurs[20];

    // Liste de quelques pilotes de Formule 1 célèbres avec leurs équipes, dates de naissance et nationalités
    char *pilotes[] = {"Lewis Hamilton", "Sebastian Vettel", "Max Verstappen", "Charles Leclerc",
                       "Valtteri Bottas", "Daniel Ricciardo", "Fernando Alonso", "Kimi Räikkönen",
                       "Lando Norris", "Carlos Sainz", "Pierre Gasly", "Esteban Ocon", "Lance Stroll",
                       "George Russell", "Nikita Mazepin", "Mick Schumacher", "Nicholas Latifi", "Yuki Tsunoda", "Antonio Giovinazzi","Noel Yando"};

    char *equipes[] = {"Mercedes", "Aston Martin", "Red Bull Racing", "Ferrari", "Mercedes", "McLaren", "Alpine", "Alfa Romeo", "McLaren", "Ferrari", "AlphaTauri", "Alpine", "Aston Martin", "Williams", "Haas", "Haas", "Haas", "Williams", "AlphaTauri", "Alfa Romeo"};

    char *datesNaissance[] = {"07/01/1985", "03/07/1987", "30/09/1997", "16/10/1997", "28/08/1989", "01/07/1989", "29/07/1981", "17/10/1979", "13/11/1999", "01/09/1994", "07/02/1996", "17/09/1996", "29/10/1988", "15/02/1998", "02/03/1999", "22/03/1999", "22/07/1999", "29/06/1995", "14/05/2000", "14/12/1993"};

    char *nationalites[] = {"British", "German", "Dutch", "Monegasque", "Finnish", "Australian", "Spanish", "Finnish", "British", "Spanish", "French", "Spanish", "Canadian", "British", "Russian", "German", "German", "Canadian", "Japanese", "Italian", "Italian"};

    // Initialisation des chauffeurs avec des valeurs par défaut
    for (int i = 0; i < 20; ++i) {
        chauffeurs[i].id = rand() % 100 + 1; // Numéro de chauffeur aléatoire entre 1 et 100
        snprintf(chauffeurs[i].nom, sizeof(chauffeurs[i].nom), "%s", pilotes[i]);
        snprintf(chauffeurs[i].equipe, sizeof(chauffeurs[i].equipe), "%s", equipes[i]);
        snprintf(chauffeurs[i].dateNaissance, sizeof(chauffeurs[i].dateNaissance), "%s", datesNaissance[i]);
        snprintf(chauffeurs[i].nationalite, sizeof(chauffeurs[i].nationalite), "%s", nationalites[i]);
        chauffeurs[i].meilleurTemps = 0.0; // Initialisation du meilleur temps à 0.0
        chauffeurs[i].meilleurTempsSecteur[0] = 0.0;
        chauffeurs[i].meilleurTempsSecteur[1] = 0.0;
        chauffeurs[i].meilleurTempsSecteur[2] = 0.0;
    }
    
    // Déclaration et initialisation du circuit
    struct Circuit circuitSpa = {
        .nom = "Circuit de Spa-Francorchamps",
        .pays = "Belgium",
        .grandPrix = "Belgian Grand Prix",
        .longueur = 7.004, // En kilomètres
        .virages = 19,
        .zonesDrs = 2};

    /* Affichage des informations des chauffeurs
    for (int i = 0; i < 20; ++i) {
        afficherCoureur(chauffeurs[i]);
    }*/

    // Affichage des informations du circuit
    //afficherCircuit(circuitSpa);
    
 ride(chauffeurs, 3);   
 trierChauffeurs(chauffeurs, 20);
 enregistrerResultats(chauffeurs, 20);

    return 0;
}
/* flemme de rajouter les cas où certains chauffeurs ne prennent pas part aux essais libres;
   les cas où certains sont out et autres
   se sont juste des conditions (si court (booléen aléatoir)); parreil pour les autres cas... 
   ici je fais courir tout le monde grace des infos codé à la main par chatgpt; mais en synchhronisant tout avec les fonctions de lecture de brice...
   l'ecriture dans le fichier c'est un petit bordel
   j'ai aussi random avec ma propre fonction; mais qu'on peut aisément remplacer par celle d'aloïs
   quoi d'autres ???? merci gaetan pour le coup de pousse; et genial ta chemise ce mercredi à l'interro de telecom brice
*/
