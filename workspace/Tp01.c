#include <stdio.h>
#include <stdlib.h>


// EXERCICE 1
float calcul_prix_billet(float, int);

// EXERCICE 3
int parfait(int);
void parfaitJusquAN(int);
int lectureInt(void);

// EXERCICE 4
typedef short TypeEntier;
TypeEntier factorielle(TypeEntier);



int main(void) {

    // EXERCICE 1
    printf("Exercice 1 :\n");
    int age;
    float prix;
    printf("Prix plein tarif = ? ");
    scanf("%f", &prix);
    printf("Age = ? ");
    scanf("%d", &age);
    printf("Prix (Plein tarif %.2f; Age %d): %.2f\n",prix,age, calcul_prix_billet(prix,age));

    // EXERCICE 2
    printf("\nExercice 2 - Somme des dés :\n");
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
    printf("\nExercice 3 - Nombres parfaits :\n");
    parfaitJusquAN(lectureInt());
    

    // EXERCICE 4
    printf("\nExercice 4 - Factorielle :\n");
    printf("%d\n",factorielle(lectureInt()));
    

    return 0;
}

// EXERCICE 1

float calcul_prix_billet(float prix_plein_tarif, int age){
    float prix = prix_plein_tarif;
    if(age<=2){
        prix*=0.1;
    }else if (age<=12){
        prix*=0.5;
    }
    return prix;

}


// EXERCICE 3

int lectureInt(){
    int n;
    scanf("%d", &n);
    return n;
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

void parfaitJusquAN(int N){
    for (int i =0 ; i < N; i++){
        if(parfait(i))
            printf("%d\n",i);
    }
    
}


// EXERCICE 4

TypeEntier factorielle(TypeEntier n){
    if(n==1)
        return 1;
    if(n>1)
        return n*factorielle(n-1);
    return 0;
}