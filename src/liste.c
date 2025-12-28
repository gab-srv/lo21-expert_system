
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "liste.h"


Liste creerListe() {
    return NULL;
}


bool appartient(Liste l, char* c){
    if (l == NULL) {
        return false;}
    if (strcmp(l->valeur, c) == 0) {
        return true;}
    return appartient(l->suivant, c);
}

void afficherListe(Liste l){
    while (l != NULL) {
        printf("%s\n", l->valeur);
        l = l->suivant;}
}  



Liste ajouterQueue(Liste l, Element v) {
    Cellule* nouv = (Cellule*)malloc(sizeof(Cellule));
    if (nouv == NULL){
	return l;}
    nouv->valeur = (char*)malloc((strlen(v) + 1) * sizeof(char));
    strcpy(nouv->valeur, v);
    nouv->suivant = NULL;
    if (l == NULL) {return nouv;}
    Liste temp = l;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouv;
    return l;
}

Liste supprimerElement(Liste l, Element v) {
    if (!appartient(l, v)) {
        printf("L'element '%s' n'est pas dans la liste.\n", v);
        return l; 
    }

    Cellule* courant = l;
    Cellule* precedent = NULL;

    while (courant != NULL) {
        if (strcmp(courant->valeur, v) == 0) {
            if (precedent == NULL) {
                l = courant->suivant; } else {
                precedent->suivant = courant->suivant;}
            free(courant->valeur);
            free(courant);
            return l;}
        precedent = courant;
        courant = courant->suivant;}
    return l;}

void detruireListe(Liste l) {
    Cellule* courant = l;
    while (courant != NULL) {
        Cellule* suivant = courant->suivant;
        free(courant->valeur); 
        free(courant);         
        courant = suivant;}
}
