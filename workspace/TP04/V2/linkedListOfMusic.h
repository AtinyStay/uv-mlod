#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../V1/linkedList.h"

typedef struct {
    //Name,Artist,Album,Genre,Disc Number,Track Number,Year
    char* name;
    char* artist;
    char* album;
    char* genre;
    char* disc ;
    char* track;
    char* year;
} Music;

void afficheElement(Element e);

void detruireElement(Element e);

bool equalsElement(Element m1, Element m2);

Liste orderByYear(Liste l);