#include <stdio.h>
#include <stdlib.h>

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier);

float calcul_prix_billet(float prix_plein_tarif, float age){
    float prix = prix_plein_tarif;
    if(age<=2){
        prix*=0.1;
    }else if (age<=12)
    {
        prix*=0.5;
    }
    return prix;

}

int parfait(int N){
    int sommeDiv=0;
    for(int i=1; i<N; i++){
        if(N%i==0)
            sommeDiv+=i;
    }

    if(sommeDiv==N)
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {

    // EXERCICE 1
    printf("Exercice 1 :\n");
    printf("Prix (Init 22; Age 14): %f\n", calcul_prix_billet(22,14));

    // EXERCICE 2
    printf("Exercice 2 :\n");
    int n;
    printf("N = ? ");
    scanf("%d", &n);
    printf("\nPour N = %d\n", n);
    for (int i = 1; i <= 6; i++){
        for (int j = 1; j <= 6; j++){
            for (int k = 1; k <= 6; k++){
                if(i+j+k==n){
                    printf("%d%d%d\n",i,j,k);
                }
            }
        }
    }

    // EXERCICE 3
    printf("\nExercice 3 :\n");
    printf("N = ? ");
    scanf("%d", &n);
    for (int i =0 ; i < n; i++)
    {
        if (parfait(i))
            printf("%d\n",i);
    }

    // EXERCICE 4
    printf("\nExercice 4 :\n");
    printf("N = ? ");
    scanf("%d", &n);
    printf("%d\n",factorielle(n));
    

    return 0;
}

TypeEntier factorielle(TypeEntier n){
    if(n==1)
        return 1;
    if(n>1)
        return n*factorielle(n-1);
    return 0;
}