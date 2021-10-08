#include <stdio.h>
#include <stdlib.h>

typedef enum Mois {janvier=1, fevrier, mars, avril, mai, juin, juillet, aout, septembre, octobre, novembre, decembre} Mois;

typedef struct Date {
    int jour;
    enum Mois mois;
    int annee;
} Date;

void initialiseDate(Date*);
void afficheDate(Date*);

int main(int argc, char *argv[]) {
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);


    return EXIT_SUCCESS;
}

void initialiseDate(Date* date){
    int jour, annee, mois;
    printf("Jour ? ");
    while (jour <1 || jour > 31)
        scanf("%d", &jour);
    printf("\nMois ? ");
    while (mois <1 || mois > 12)
        scanf("%d", &mois);
    printf("\nAnnee ? ");
    scanf("%d", &annee);

    date->jour = jour;
    switch (mois){
        case 1:
            date->mois = janvier;
            break;
        case 2:
            date->mois = fevrier;
            break;
        case 3:
            date->mois = mars;
            break;
        case 4:
            date->mois = avril;
            break;
        case 5:
            date->mois = mai;
            break;
        case 6:
            date->mois = juin;
            break;
        case 7:
            date->mois = juillet;
            break;
        case 8:
            date->mois = aout;
            break;
        case 9:
            date->mois = septembre;
            break;
        case 10:
            date->mois = octobre;
            break;
        case 11:
            date->mois = novembre;
            break;
        case 12:
            date->mois = decembre;
            break;
        default:
            break;
    }
    date->annee = annee;
}

void afficheDate(Date* date){
    printf("%d / %00d / %d", date->jour, (int)date->mois, date->annee);
    
}