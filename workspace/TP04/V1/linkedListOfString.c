#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfString.h"

void afficheElement(Element e){
    printf("%s ", (char*)e);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return strcmp((char*)e1, (char*)e2)==0;
}
