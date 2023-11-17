#ifndef TOUR_H
#define TOUR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randommili.h"


float drive(int nbrTours) {
    //srand(time(NULL)); 
    float temps_min_secteur1 = trouver_temps_minimum(60);
    printf("Le temps minimum du secteur 1 est : %.3f secondes\n", temps_min_secteur1);
    
    
    float temps_min_secteur2 = trouver_temps_minimum(60);
    printf("Le temps minimum du secteur 2 est : %.3f secondes\n", temps_min_secteur2);
    
    
    float temps_min_secteur3 = trouver_temps_minimum(60);
    printf("Le temps minimum du secteur 3 est : %.3f secondes\n", temps_min_secteur3);
    
    float temps_min_tour = temps_min_secteur1 + temps_min_secteur2 + temps_min_secteur3 ;
    printf("Le temps minimum du tour est : %.3f secondes\n", temps_min_tour);

    return temps_min_tour;
}
#endif
