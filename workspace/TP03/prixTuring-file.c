#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Winner{
	int annee;
	char* nom;
	char* description;
} Winner;

typedef struct WinnerTab{
	Winner* winners;
	int nbWinners;
} WinnerTab;

WinnerTab readWinnersFile(FILE*);
void printWinners(WinnerTab );

int main(int argc, char *argv[]) {
    if( argc >= 2 ){
        FILE* f;
        if( (f=fopen(argv[1],"r")) == NULL) {
            printf ("Code de l'erreur : %d\n", errno);
            return EXIT_FAILURE;
        }

        WinnerTab winners = readWinnersFile(f);
        printWinners(winners);

        fclose(f);
    }
    return EXIT_SUCCESS;
}

WinnerTab readWinnersFile(FILE* fichier){
    WinnerTab tableau;
    char buffer[256];
	tableau.nbWinners = atoi(fgets(buffer, 256, fichier));

	tableau.winners = (Winner*)malloc(tableau.nbWinners*sizeof(Winner));

	for(int i=0; i<tableau.nbWinners; i++){
		tableau.winners[i].annee =  atoi(fgets(buffer, 256, fichier));
		
		tableau.winners[i].nom = calloc(256,sizeof(char));
		tableau.winners[i].nom = fgets(buffer, 256, fichier);
		
		tableau.winners[i].description = calloc(256,sizeof(char));
		tableau.winners[i].description = fgets(buffer, 256, fichier);
	}

	return tableau;
}

void printWinners(WinnerTab tableau){
	printf("%i\n", tableau.nbWinners);

	for(int i=0; i<tableau.nbWinners; i++){
		printf("%i\n",tableau.winners[i].annee);
		printf("%s\n",tableau.winners[i].nom);
		printf("%s\n",tableau.winners[i].description);
    }
}