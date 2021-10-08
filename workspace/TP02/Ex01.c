#include <stdio.h>
#include <stdlib.h>

#include "Ex01.h"

int main(int argc, char *argv[]) {
    int a=20, b=10;
    printf("a  = %d ; b = %d\n",a ,b);
    echangeContenu(&a,&b);
    printf("a  = %d ; b = %d\n",a ,b);
    return EXIT_SUCCESS;
}

void echangeContenu(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}