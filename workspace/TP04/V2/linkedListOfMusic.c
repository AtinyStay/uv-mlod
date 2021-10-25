#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfMusic.h"

//Name,Artist,Album,Genre,Disc Number,Track Number,Year
void afficheElement(Element e){
    Music *music = (Music *)e;
    printf("%s,%s,%s,%s,%s,%s,%s\n",
        music->name, music->artist, music->album, music->genre, music->disc, music->track, music->year);
}

void detruireElement(Element e){
    free(e);

}

bool equalsElement(Element m1, Element m2){
    return true;
}
