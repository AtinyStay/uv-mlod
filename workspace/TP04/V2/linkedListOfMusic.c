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

Liste orderByYear(Liste l){
    
    if(estVide(l) || estVide(l->suiv))
        return l;

    Liste curr, prev, oldest, oldestPrev;
    curr = prev = oldest = oldestPrev = l;

    while(!estVide(curr)){

        if(strcmp(((Music *)curr->val)->year, ((Music *)oldest->val)->year) <= 0){
            oldestPrev = prev;
            oldest = curr;
        }
        prev = curr;
		curr = curr->suiv;
	}

    // On met le maillon correspondant à la musique la plus vieille en tete de liste si elle ne l'est pas déjà
    Liste tmp;
    if (oldest != l){
        oldestPrev->suiv = l;
        tmp = l->suiv;
        l->suiv = oldest->suiv;
        oldest->suiv = tmp;
    }

    oldest->suiv = orderByYear(oldest->suiv);

    return oldest;
}
