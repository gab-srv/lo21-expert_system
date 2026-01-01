#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/liste.h"
#include "../include/regle.h"

Regle creerRegle(){
    Regle r;
    r.premisses = creerListe();
    r.conclusion = NULL;
    return r;
}

void definirConclusion(Regle *r, const char *conclusion){
    if (r->conclusion != NULL)
        free(r->conclusion);

    r->conclusion = malloc(strlen(conclusion) + 1);
    strcpy(r->conclusion, conclusion);
}

void ajouterPremisse(Regle *r, const char *premisse){
    char *copy = malloc(strlen(premisse) + 1);
    strcpy(copy, premisse);
    ajouterQueue(&(r->premisses), copy);
}

bool appartientPremisse(Regle r, const char *premisse){
    Liste i = r.premisses;
    while (i != NULL){
        if (strcmp(i->valeur, premisse) == 0)
            return true;
        i = i->suivant;
    }
    return false;
}

void supprimerPropPremisse(Regle *r, const char *premisse){
    supprimerElement(&(r->premisses), premisse); 
}

Regle* restePremisse(Regle* r)
{
    if (r == NULL || estVidePremisse(r)) {
        return NULL;
    }
    Regle* r_suivante = r;
    r_suivante->premisses = r->premisses->suivant;

    return r_suivante;
}

bool estVidePremisse(Regle r){
    return r.premisses == NULL;
}

char* tetePremisse(Regle r){
    if (!estVidePremisse(r))
        return r.premisses->valeur;
    return NULL;
}

char* conclusion(Regle r){
    return r.conclusion;
}

void detruireRegle(Regle *r){
    detruireListe(&(r->premisses)); 
    if (r->conclusion)
        free(r->conclusion);
}
