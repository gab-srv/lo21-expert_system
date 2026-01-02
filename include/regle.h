#ifndef REGLE_H
#define REGLE_H

#include <stdbool.h>
#include "liste.h"

typedef struct {
    Liste premisses;
    char *conclusion;
} Regle;

Regle creerRegle();
Regle ajouterPremisse(Regle r, const char *premisse);
Regle definirConclusion(Regle r, const char *conclusion);
bool appartientPremisse(Regle r, const char *premisse);
Regle supprimerPropPremisse(Regle r, const char *premisse);
bool estVidePremisse(Regle r);
char* tetePremisse(Regle r);
char* conclusion(Regle r);
void detruireRegle(Regle *r);

#endif
