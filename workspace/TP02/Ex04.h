#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Mois {janvier=1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre} Mois;

typedef struct Date {
    int jour;
    enum Mois mois;
    int annee;
} Date;

void initialiseDate(Date*);
Date creerDateParCopie();
Date* newDate();

void afficheDate(Date*);
Mois inttomois(int);
char* moistostr(Mois);

unsigned int nbreJours(Mois, unsigned int);
bool dateValide(Date);
unsigned int jourDansAnnee(Date );