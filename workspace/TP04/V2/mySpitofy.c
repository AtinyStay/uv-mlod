/** 
 Compilation
 gcc -g -Wall -o spitofy mySpitofy.c linkedListOfMusic.c ../V1/linkedList.c

 Execution 
 ./spitofy > out.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./spitofy > out.csv
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "linkedListOfMusic.h"


Liste readCsv(FILE*);


int main(int argc, char *argv[]) {

    // Ouverture du fichier
    FILE* monFichier;
    if( (monFichier = fopen("music.csv","r")) == NULL) {
        printf ("Échec de l'ouverture, code de l'erreur : %d\n", errno);
        return EXIT_FAILURE;
    }

    Liste playlist;
    playlist = readCsv(monFichier);

    // playlist = orderByYear(playlist);

    afficheListe_i(playlist);


    detruire_i(playlist);
    fclose(monFichier);
    return EXIT_SUCCESS;
}

//Name,Artist,Album,Genre,Disc Number,Track Number,Year
Liste readCsv(FILE* csv){
    Liste l;
    l = NULL;
    char *line, *copy;
    Music* tmp;

    
    line = calloc(256,sizeof(char));
    while (fgets(line, 256, csv) != NULL){
        tmp = (Music *)malloc(sizeof(Music));

        // A free -> Comment !??
        copy = strdup(line);

        if (!copy)
            exit(EXIT_FAILURE);

        tmp->name = strsep(&copy, ",\n");
        tmp->artist = strsep(&copy, ",\n");
        tmp->album = strsep(&copy, ",\n");
        tmp->genre = strsep(&copy, ",\n");
        tmp->disc = strsep(&copy, ",\n");
        tmp->track = strsep(&copy, ",\n");
        tmp->year = strsep(&copy, ",\n");

        l = ajoutFin_i(tmp, l);
    }
    free(line);

    return l;
}

