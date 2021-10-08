#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Ex02.h"

int main(int argc, char *argv[]) {

    bool T1[5] = {false, true, true,false,false};
    bool T2[5] = {true,true,false,false,true};
    bool T3[5] = {true,true,false,true,false};

    printf("T1 : ");
    if (estConvexe(T1, 5)){
        printf("true");
    }else{
        printf("false");
    }
    printf("\nT2 : ");
    if (estConvexe(T2, 5)){
        printf("true");
    }else{
        printf("false");
    }
    printf("\nT3 : ");
    if (estConvexe(T3, 5)){
        printf("true");
    }else{
        printf("false");
    }


    return EXIT_SUCCESS;
}

bool estConvexe(bool tab[], int length){
    int i = 0;
    bool convexe = true;
    while(!tab[i] && i<length)
        i++;
    while(tab[i] && i<length)
        i++;
    for(int j = i; j<length; j++){
        if(tab[j]){
            convexe=false;
            break;
        }
    }

    if(!convexe){
        while(tab[i] && i<length)
            i++;
        while(!tab[i] && i<length)
            i++;
        for(int j = i; j<length; j++){
            if(!tab[j])
                return false;
        }
    }

    return true;
}

