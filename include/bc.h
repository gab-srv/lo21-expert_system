#ifndef BC_H
#define BC_H

#include "regle.h"

typedef struct elemR {
    Regle value;
    struct elemR* next;
} listElementR;

typedef listElementR* ListeR;

typedef struct {
    ListeR regles;
} BC;

/* opérations sur la BC */
BC creerBC();
BC ajouterRegle(BC bc, Regle r);
Regle* teteBC(BC bc);

/* opérations internes */
ListeR ajouterQueueR(ListeR L, Regle r);

#endif
