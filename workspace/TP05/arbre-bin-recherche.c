#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL ;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	a = malloc(sizeof a);
	a->val = e;
	a->filsDroit = NULL;
	a->filsGauche = NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if(equalsElement(a->val, e))
		return a;

	ArbreBinaire f, t = a;
	bool continuer = true;
	while(continuer){
		if(equalsElement(t->val, e))
			return a;

		f = e > t->val ? t->filsDroit : t->filsGauche;
		if(estVide(f)){
			continuer = false;
		}else
			t = f;
	}

	if(e > t->val){
		t->filsDroit = creer(e);
	}else
		t->filsGauche = creer(e);
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(estVide(a))
		return creer(e);

	if(equalsElement(a->val, e))
		return a;

	if(a->val < e){
		a->filsDroit = insere_r(a->filsDroit, e);
	}else
		a->filsGauche = insere_r(a->filsGauche, e);

	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a))
		return 0;
	return nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche) + 1;
}

//
bool equalsElement(Element e1, Element e2){
	return e1 == e2; 
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a))
		return -1;
	if(equalsElement(a->val, e))
		return 1;
	
	int pGauche, pDroite;
	pGauche = profondeur(a->filsGauche, e);
	pDroite = profondeur(a->filsDroit, e);
	
	if(pGauche != -1)
		return pGauche + 1;
	if(pDroite != -1)
		return pDroite + 1;

	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a))
		return 0;
	int hDroite, hGauche;
	hDroite = nombreDeNoeud(a->filsDroit);
	hGauche = nombreDeNoeud(a->filsGauche);
	int max = hDroite > hGauche ? hDroite : hGauche ;
	return max + 1;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element e){
	if(estVide(a))
		return NULL;
	if(equalsElement(a->val, e))
		return NULL;
	
	if(a->val < e){
		if(!estVide(a->filsDroit)){
			if (equalsElement(a->filsDroit->val, e)){
				return a;
			}else
				return pere(a->filsDroit, e);
		}
	}else
		if(!estVide(a->filsGauche)){
			if (equalsElement(a->filsGauche->val, e)){
				return a;
			}else
				return pere(a->filsGauche, e);
		}

	return NULL;
}

void afficheElement(Element e){
	printf("%i", e);
};

void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheElement(a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsGauche))
			printf("(");
		afficheGRD_r(a->filsGauche);
		if(!estVide(a->filsGauche))
			printf(")");
		afficheElement(a->val);
		if(!estVide(a->filsDroit))
			printf("(");
		afficheGRD_r(a->filsDroit);
		if(!estVide(a->filsDroit))
			printf(")");
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		afficheElement(a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a))
		return NULL;
	if(estVide(a->filsGauche))
		return a;
	return min(a->filsGauche);
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a))
		return NULL;
	if(estVide(a->filsDroit))
		return a;
	return min(a->filsDroit);
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element e){
	if(estVide(a))
		return NULL;
	if(equalsElement(a->val, e))
		return a;
	
	if(a->val < e){
		return recherche_r(a->filsDroit, e);
	}else
		return recherche_r(a->filsGauche, e);

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element e)
{
	ArbreBinaire papa = pere(a, e);
	if(estVide(papa))
		return NULL;

	ArbreBinaire noeudElem, filsDElem, filsGElem, successeur;

	noeudElem = e < papa->val ? papa->filsGauche : papa->filsDroit;
	filsDElem = noeudElem->filsDroit;
	filsGElem = noeudElem->filsGauche; 
	
	detruireElement(noeudElem->val);
	free(noeudElem);

	successeur = max(filsGElem);
	if(!estVide(successeur->filsDroit) || !estVide(successeur->filsGauche))
		return supprimer_r(filsGElem, successeur->val);

	successeur->filsDroit = filsDElem;
	successeur->filsGauche = filsGElem;

	ArbreBinaire papaSuc = pere(filsGElem, successeur->val);
	papaSuc->filsDroit = NULL;

	if(papa->val < e){
		papa->filsDroit = successeur;

	}else{
		papa->filsGauche = successeur;
	}

	return a;
}

void detruireElement(Element e) {}

void detruire_r(ArbreBinaire a){
	if(!estVide(a)){
		detruire_r(a->filsDroit);
		detruire_r(a->filsGauche);
		detruireElement(a->val);
		free(a);
	}
}

