#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = (Liste)malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste n = creer(v);
	n->suiv = l;
	return n;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(!estVide(l)){
		afficheElement(l->val);
		l = l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(!estVide(l)){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}else 
		printf("\n");
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste t;
	while(!estVide(l)){
		t = l->suiv;
		detruireElement(l->val);
		free(l);
		l = t;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(!estVide(l->suiv)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if(!estVide(l))
		return creer(v);
	
	Liste t = l; 
	while(!estVide(t->suiv))
		t = t->suiv;

	t->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(!estVide(l->suiv)){
		ajoutFin_r(v,l->suiv);
	}else{
		l->suiv = creer(v);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) && !equalsElement(v, l->val))
		l = l->suiv;
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(equalsElement(v, l->val))
		return l;
	if(!estVide(l->suiv) )
		return cherche_r(v, l->suiv);
	return NULL;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste premier;
	if(estVide(premier = cherche_i(v, l)))
		return l;

	if (l == premier ){
		Liste t = l->suiv;
		detruireElement(t->val);
		free(l);
		return t;
	}

	Liste t = l;
	while(t->suiv != premier)
		t = t->suiv;	

	Liste tmp = t->suiv->suiv;
	detruireElement(t->suiv->val);
	free(t->suiv);
	t->suiv = tmp;

	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(estVide(l))
		return NULL;

	if (equalsElement(v, l->val)){
		Liste tmp = l->suiv;
		detruireElement(l->val);
		free(l);
		return tmp;
	}

	if (!estVide(l->suiv)){
		if(equalsElement(v, l->suiv->val)){
			Liste tmp = l->suiv->suiv;
			detruireElement(l->suiv->val);
			free(l->suiv);
			l->suiv = tmp;
		}else{
			retirePremier_r(v,l->suiv);
		}
	}
	
	return l;
}

void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}	