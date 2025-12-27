#ifndef REGLE_H
#define REGLE_H

#include "liste.h"

typedef struct {
    Liste premisses;
    char *conclusion;
} Regle;

Regle creerRegle();
void ajouterPremisse(Regle *r, char premisse);
void definirConclusion(Regle *r, const char* conclusion);
bool appartientPremisse(Regle r);
void supprimerPropPremisse(Regle *r);
bool estVidePremisse(Regle r);
char tetePremisse(Regle r);
char conclusion(Regle r);

#endif