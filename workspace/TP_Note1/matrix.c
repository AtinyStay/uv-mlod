#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Matrix{
    int** valeurs;
    int nbColonnes;
    int nbLignes;
};
typedef struct Matrix Matrix;

struct MatrixArray{
    Matrix* matrices;
    int nbMatrices;
} ;
typedef struct MatrixArray MatrixArray;


Matrix readMatrix(FILE*);
MatrixArray readMatrixArray(FILE*);
void freeMatrix(Matrix);
void freeMatrixArray(MatrixArray);
void printMatrix(Matrix);
void printMatrixArray(MatrixArray);
MatrixArray rotate90ccw(MatrixArray);
Matrix rotate90ccwMatrix(Matrix);


int main(int argc, char *argv[]) {

    // Ouverture du fichier
    FILE* monFichier;
    if( (monFichier = fopen("matrices.txt","r")) == NULL) {
        printf ("Échec de l'ouverture, code de l'erreur : %d\n", errno);
        return EXIT_FAILURE;
    }

    // Lecture et affichage des matrices
    MatrixArray monArray = readMatrixArray(monFichier);
    printMatrixArray(monArray);

    // Vérification Q. 5 :
    //printMatrixArray(rotate90ccw(monArray));
    
    freeMatrixArray(monArray);
    fclose(monFichier);
    return EXIT_SUCCESS;
}


MatrixArray readMatrixArray(FILE* fichier){
    MatrixArray array;

    // Lecture et allocation du bon nombre de matrices
    fscanf(fichier, "%i", &array.nbMatrices);
    array.matrices =  (Matrix *)calloc(array.nbMatrices, sizeof(Matrix));

    // Lecture de chaque matrice
    for (int i = 0; i < array.nbMatrices; i++){
        array.matrices[i] = readMatrix(fichier);
    }

    return array;
}

Matrix readMatrix(FILE* fichier){
    Matrix matrice;

    // Lecture et allocation du bon nombre de lignes
    fscanf(fichier, "%i %i", &matrice.nbLignes, &matrice.nbColonnes);
    matrice.valeurs =  (int **)calloc(matrice.nbLignes, sizeof(int *));
    for (int i = 0; i < matrice.nbLignes; i++){

        //Pour chaque ligne on alloue puis lit le bon nombre de colonnes
        matrice.valeurs[i] =  (int *)calloc(matrice.nbColonnes, sizeof(int));
        for (int j = 0; j < matrice.nbColonnes; j++){
            fscanf(fichier, "%i ", &matrice.valeurs[i][j]);
        }
    }

    return matrice;
}


void freeMatrix(Matrix matrice){
    for (int i = 0; i < matrice.nbLignes; i++){
        free(matrice.valeurs[i]);
    }
    free(matrice.valeurs);
}

void freeMatrixArray(MatrixArray array){
    for (int i = 0; i < array.nbMatrices; i++){
        freeMatrix(array.matrices[i]);
    }
    free(array.matrices);
}

void printMatrix(Matrix matrice){
    printf("\n%i %i", matrice.nbLignes, matrice.nbColonnes);
    for (int i = 0; i < matrice.nbLignes; i++){
        printf("\n");
        for (int j = 0; j < matrice.nbColonnes-1; j++){
            printf("%i ", matrice.valeurs[i][j]);
        }
        // Affichage de la dernère valeur sans espace après pour que le fichier de sortie soit exactement identique à celui d'entrée
        printf("%i", matrice.valeurs[i][matrice.nbColonnes-1]);
    }
}

void printMatrixArray(MatrixArray array){
    printf("%i", array.nbMatrices);
    for (int i = 0; i < array.nbMatrices; i++){
        printMatrix(array.matrices[i]);
    }
}

MatrixArray rotate90ccw(MatrixArray baseArray){
    MatrixArray newArray;
    newArray.nbMatrices = baseArray.nbMatrices;
    
    newArray.matrices =  (Matrix *)calloc(newArray.nbMatrices, sizeof(Matrix));
    for (int i = 0; i < newArray.nbMatrices; i++){
        newArray.matrices[i] = rotate90ccwMatrix(baseArray.matrices[i]);
    }

    return newArray;
}

Matrix rotate90ccwMatrix(Matrix baseMatrix){
    Matrix newMatrix;
    newMatrix.nbColonnes = baseMatrix.nbLignes;
    newMatrix.nbLignes = baseMatrix.nbColonnes;

    newMatrix.valeurs =  (int **)calloc(newMatrix.nbLignes, sizeof(int *));
    for (int i = 0; i < newMatrix.nbLignes; i++){
        newMatrix.valeurs[i] =  (int *)calloc(newMatrix.nbColonnes, sizeof(int));
        for (int j = 0; j < newMatrix.nbColonnes; j++){
            newMatrix.valeurs[i][j] = baseMatrix.valeurs[j][newMatrix.nbLignes - i -1];
        }
    }

    return newMatrix;
}