#ifndef REGLE_H
#define REGLE_H

#include <stdbool.h>
#include "liste.h"

typedef struct {
    Liste premisses;
    char *conclusion;
} Regle;

Regle creerRegle();
void ajouterPremisse(Regle *r, const char *premisse);
void definirConclusion(Regle *r, const char *conclusion);
bool appartientPremisse(Regle r, const char *premisse);
void supprimerPropPremisse(Regle *r, const char *premisse);
bool estVidePremisse(Regle r);
char* tetePremisse(Regle r);
char* conclusion(Regle r);
void detruireRegle(Regle *r);

#endif
