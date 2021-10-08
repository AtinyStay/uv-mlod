#include "Ex03.h"

int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];

    mult_matrice(matriceResultat,matrice1,matrice2);
    affiche_matrice(matriceResultat);

    return EXIT_SUCCESS;
}

void mult_matrice(int64_t (*resultat)[5],int64_t (*matriceA)[5], int64_t (*matriceB)[5]){
    int64_t sommeIJ;
    for (int i = 0; i <5; i++){
        for (int j = 0; j <5; j++){
            sommeIJ =0;
            for (int k = 0; k < 5; k++){
                sommeIJ += matriceA[i][k] * matriceB[k][j];
            }
            resultat[i][j] = sommeIJ;
        }
    }
};

void affiche_matrice(int64_t (*matrice)[5]){
    for (int i = 0; i <5; i++){
        for (int j = 0; j <5; j++){
            printf("%ld \t", matrice[i][j]);
        }
        printf("\n");
    }
}
