#include <stdio.h>
#include <stdlib.h>

#include "algorithms/essais_libre.h"
int main() {

	printf("what dou you wana do :\n");
	printf("1 : Practice session\n");
	printf("2 : The qualifications (Q1/Q2/Q3)\n");
	printf("3 : The race\n");
	
	int choice = 0;
	scanf("\n%d", &choice);

	switch (choice){
		case 1:
			printf("Practice session\n");
			sessionEssaisLibres();
			break;
		case 2:
			printf("The qualifications (Q1/Q2/Q3)\n");
			break;
		case 3:
			printf("The race\n");
			break;
		default:
			printf("Invalid input pleas retry\n");
			break;
	}
	return 0;
}
