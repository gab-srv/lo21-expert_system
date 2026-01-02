#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/liste.h"
#include "../include/regle.h"

/* Création d'une règle */
Regle creerRegle(){
    Regle r;
    r.premisses = NULL;
    r.conclusion = NULL;
    return r;
}

Regle definirConclusion(Regle r, const char *conclusion){
    if (r.conclusion != NULL) {
        free(r.conclusion);
    }
    r.conclusion = malloc(strlen(conclusion) + 1);
    strcpy(r.conclusion, conclusion);
    return r;
}

Regle ajouterPremisse(Regle r, const char *premisse) {
    char *copy = malloc(strlen(premisse) + 1);
    strcpy(copy, premisse);
    r.premisses = ajouterQueue(r.premisses, copy);
    return r;
}

bool appartientPremisse(Regle r, const char *premisse){
    Liste i = r.premisses;
    while (i != NULL) {
        if (strcmp(i->valeur, premisse) == 0)
            return true;
        i = i->suivant;
    }
    return false;
}

Regle supprimerPropPremisse(Regle r, const char *premisse) {
    r.premisses = supprimerElement(r.premisses, (char *)premisse);
    return r;
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

/* Destruction de la règle */
void detruireRegle(Regle *r) {
    detruireListe(r->premisses);
    if (r->conclusion != NULL)
        free(r->conclusion);
}
