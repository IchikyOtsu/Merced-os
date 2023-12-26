#ifndef DRIVE_H
#define DRIVE_H

#include "random.h" 
#include "pilote.h" 

float *drive(){


    //initialisation des meilleurs temps à 0
    float *meilleursTemps = (float *)malloc(4 * sizeof(float));
    for (int i = 0; i < 4; i++) {
    	meilleursTemps[i] = 0;
    }
    



	//génerére le temps de ce tour dans un tableau
        float temps[4] = {0, 0, 0, 0};
        genererTempsAleatoires(25000, 45000, temps);

	//sauver les temps si ils sont meilleur que les précedents
        if (meilleursTemps[0] == 0 || meilleursTemps[0] > temps[0]){
        	meilleursTemps[0] = temps[0];
        }
        if (meilleursTemps[1] == 0 || meilleursTemps[1] > temps[1]){
        	meilleursTemps[1] = temps[1];
        }
        if (meilleursTemps[2] == 0 || meilleursTemps[2] > temps[2]){
        	meilleursTemps[2] = temps[2];
        }
        if (meilleursTemps[3] == 0 || meilleursTemps[3] > temps[3]){
        	meilleursTemps[3] = temps[3];
        }



    return meilleursTemps;
}

#endif

