#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/liste.h"
#include "../include/regle.h"


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
    r.conclusion = strdup(conclusion);
    return r;
}

Regle ajouterPremisse(Regle r, const char *premisse) {
    char *copy = strdup(premisse);
    r.premisses = ajouterQueue(r.premisses, copy);
    return r;
}

/*bool appartientPremisse(Regle r, const char *premisse){
    Liste i = r.premisses; 
    while (i != NULL){ 
        if (strcmp(i->valeur, premisse) == 0) {
            return true; 
        }
        i = i->suivant;
    } 
    return false;
}Version non itérative pour appartientPremisse*/

bool appartientPremisseRecursif(Liste l, const char *premisse) {
    if (l == NULL) {
        return false;
    }
    if (strcmp(l->valeur, premisse) == 0) {
        return true;
    }
    return appartientPremisseRecursif(l->suivant, premisse);
}

bool appartientPremisse(Regle r, const char *premisse) {
    return appartientPremisseRecursif(r.premisses, premisse);
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
