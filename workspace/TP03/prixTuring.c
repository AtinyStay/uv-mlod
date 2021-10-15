/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Winner{
	int annee;
	char* nom;
	char* description;
} Winner;

typedef struct WinnerTab{
	Winner* winners;
	int nbWinners;
} WinnerTab;

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine();

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt();

WinnerTab readWinners();
void printWinners(WinnerTab);
void infosAnnee(WinnerTab, int);

int main(int argc, char *argv[])
{
	WinnerTab winners = readWinners();
	infosAnnee( winners, atoi(argv[1]));

	free(winners.winners);
	return EXIT_SUCCESS;
}


WinnerTab readWinners(){
	WinnerTab tableau;
	tableau.nbWinners = scanLineAsInt();

	tableau.winners = (Winner*)malloc(tableau.nbWinners*sizeof(Winner));

	for(int i=0; i<tableau.nbWinners; i++){
		tableau.winners[i].annee = scanLineAsInt();
		tableau.winners[i].nom = scanLine();
		tableau.winners[i].description = scanLine();
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

void infosAnnee(WinnerTab winners, int annee){
	int i=0;
	while(winners.winners[i].annee != annee && i < winners.nbWinners)
		i++;
	printf("L'annee %i, le(s) gagnant(s) ont été : %s\nNature des travaux : %s\n", annee, winners.winners[i].nom,winners.winners[i].description);
}

char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}
