#ifndef BC_H
#define BC_H

#include "liste.h"
#include "regle.h"

typedef struct elemR {
    Regle value;
    struct elemR* next;
} listElementR;

typedef listElementR* ListeR;

typedef struct {
    ListeR regles;
} BC;
bool bcVide(BC bc);
void ajouterQueueR(ListeR *l, Regle r);
Regle teteR(ListeR *l);
BC creerBC();
void ajouterRegle(BC *bc, Regle r);
Regle teteBC(BC bc);

#endif
