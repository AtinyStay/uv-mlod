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


    afficheEnvers_r(playlist);

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

        l = ajoutTete(tmp, l);
    }

    free(line);

    return l;
}

