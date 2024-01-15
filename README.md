gcc -o main main.c -lm 

./main 

Pour changer le nombre de tour, lors d'un éventuel test, vous pouvez remplacer "nbrTourRace" dans le switch du main.c : 

switch (choice){
		case 1:
			printf("Practice session\n");
			sessionEssaisLibres(nbrTourRace);
			break;
		case 2:
			printf("The qualifications (Q1/Q2/Q3)\n");
			sessionQualif(nbrTourRace);
			break;
		case 3:
			printf("The race\n");
            		race(nbrTourRace);
			break;
