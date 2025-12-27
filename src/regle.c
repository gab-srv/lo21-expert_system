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

void ajouterPremisse(Regle *r, char premisse){
    ajouterQueue(&(r->premisses), premisse);
}

bool appartientPremisse(Regle r, char premisse){
    Liste i = r.premisses;
    while (i != NULL){
        if (i->value == premisse)
            return true;
        i = i->next;
    }
    return false;
}

void supprimerPropPremisse(Regle *r, char premisse){
    supprimerElement(&(r->premisses), premisse);
}

bool estVidePremisse(Regle r){
    return r.premisses == NULL;
}

char tetePremisse(Regle r){
    if (!estVidePremisse(r))
        return r.premisses->value;
    return '\0';
}

char* conclusion(Regle r){
    return r.conclusion;
}

void detruireRegle(Regle *r){
    detruireListe(&(r->premisses)); // fonction à implémenter dans liste.c
    if (r->conclusion)
        free(r->conclusion);
}
