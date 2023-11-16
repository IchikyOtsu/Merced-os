//#include "/home/ichiky/Documents/Merced'OS/UseCSV/FichierH/utils/pilotes.h"
#include "utilities/randommili.h"
int main() {
    int nombreDeTours = 60;
    float temps_min = trouver_temps_minimum(nombreDeTours);
    printf("Le temps minimum sur %d tours est : %.3f secondes\n", nombreDeTours, temps_min);

    return 0;
}
