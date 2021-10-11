#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Ex04.h"

int main(int argc, char *argv[]) {
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    Date e;
    e = creerDateParCopie();
    afficheDate(&e);

    Date *date;
    date = newDate();
    afficheDate(date);

    free(date);

    printf("\n\n%d", nbreJours(fevrier,2100));

    return EXIT_SUCCESS;
}

void initialiseDate(Date* date){
    int jour, annee, mois;
    printf("Jour ? ");
    while (jour <1 || jour > 31)
        scanf("%d", &jour);
    printf("Mois ? ");
    while (mois <1 || mois > 12)
        scanf("%d", &mois);
    printf("Annee ? ");
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

Date creerDateParCopie(){
    Date date;
    int jour, annee, mois;
    printf("Jour ? ");
    while (jour <1 || jour > 31)
        scanf("%d", &jour);
    printf("\nMois ? ");
    while (mois <1 || mois > 12)
        scanf("%d", &mois);
    printf("\nAnnee ? ");
    scanf("%d", &annee);


    date.jour = jour;
    date.mois = inttomois(mois);
    date.annee = annee;

    return date;
}

Date* newDate(){
    Date* pDate = (Date*)malloc(sizeof(Date));
    if (pDate)
        initialiseDate(pDate);
    return pDate;
}

Mois inttomois(int mois){
    switch (mois){
        case 1:
            return janvier;
        case 2:
            return fevrier;
        case 3:
            return mars;
        case 4:
            return avril;
        case 5:
            return mai;
        case 6:
            return juin;
        case 7:
            return juillet;
        case 8:
            return aout;
        case 9:
            return septembre;
        case 10:
            return octobre;
        case 11:
            return novembre;
        case 12:
            return decembre;
        default:
            break;
    }
    return 0;
}

char* moistostr(Mois mois){
    switch (mois){
        case janvier:
            return "janvier";
        case fevrier:
            return "fevrier";
        case mars:
            return "mars";
        case avril:
            return "avril";
        case mai:
            return "mai";
        case juin:
            return "juin";
        case juillet:
            return "juillet";
        case aout:
            return "aout";
        case septembre:
            return "septembre";
        case octobre:
            return "octobre";
        case novembre:
            return "novembre";
        case decembre:
            return "decembre";
        default:
            break;
    }
    return 0;
}

void afficheDate(Date* date){
    printf("%02d %s %04d\n", date->jour, moistostr(date->mois), date->annee);
}

unsigned int nbreJours(Mois mois, unsigned int annee){
    switch (mois){
        case janvier:
            return 31;
        case fevrier:
            if((annee%4 == 0 && annee%100 != 0) || annee%400 == 0){
                return 29;
            }else{
                return 28;
            }
        case mars:
            return 31;
        case avril:
            return 30;
        case mai:
            return 31;
        case juin:
            return 30;
        case juillet:
            return 31;
        case aout:
            return 31;
        case septembre:
            return 30;
        case octobre:
            return 31;
        case novembre:
            return 30;
        case decembre:
            return 31;
        default:
            break;
    }
    return 0;
}

bool dateValide(Date uneDate){
    if(uneDate.mois<1 || uneDate.mois>12 || uneDate.jour < 1 || uneDate.jour > nbreJours(uneDate.mois, uneDate.annee))
        return false;   
    return true;    
}

unsigned int jourDansAnnee(Date uneDate){
    unsigned int somme;
    if(dateValide(uneDate)){
        somme = uneDate.jour;
        for (Mois i = 1; i < uneDate.mois; i++){
            somme += nbreJours(i, uneDate.annee);
        }  
    }
    return 0;
}