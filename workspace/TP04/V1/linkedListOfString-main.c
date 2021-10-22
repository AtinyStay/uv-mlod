#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfString.h"

int main(int argc, char *argv[]) {
    Liste maliste, p;
    maliste = creer("Jedi");
    maliste = ajoutFin_i("!", maliste);
    maliste = ajoutTete("un", maliste);
    maliste = ajoutTete("est", maliste);
    maliste = ajoutTete("Luke", maliste);
 
    afficheListe_r(maliste);


    return EXIT_SUCCESS;
}