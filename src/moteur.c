#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/moteur.h"
#include "../include/liste.h"
#include "../include/regle.h"
#include "../include/bc.h"


Liste moteurInference(BC bc, Liste bf) {
    Liste deduites = creerListe();
    Liste faits = bf;

    while (faits != NULL) {
        char *f = faits->valeur;
        ListeR regles = bc.regles;
        while (regles != NULL) {
            Regle *r = &(regles->value);
            if (appartientPremisse(*r, f)) {
                *r = supprimerPropPremisse(*r, f);
                if (estVidePremisse(*r)) {
                    char *c = conclusion(*r);
                    if (!appartient(bf, c)) { //éviter doublons
                        bf = ajouterQueue(bf, strdup(c));
                        deduites = ajouterQueue(deduites, strdup(c));
                    }
                }
            }
            regles = regles->next;
        }
        faits = faits->suivant;
    }
    return deduites;
}