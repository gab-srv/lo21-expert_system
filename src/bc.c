#include <stdlib.h>
#include "../include/bc.h"

ListeR ajouterQueueR(ListeR L, Regle r)
{
    listElementR* nouv = malloc(sizeof(listElementR));
    nouv->value = r;
    nouv->next = NULL;

    if (L == NULL)
        return nouv;

    ListeR courant = L;
    while (courant->next != NULL)
        courant = courant->next;

    courant->next = nouv;
    return L;
}

BC creerBC()
{
    BC bc;
    bc.regles = NULL;
    return bc;
}

BC ajouterRegle(BC bc, Regle r)
{
    bc.regles = ajouterQueueR(bc.regles, r);
    return bc;
}

Regle* teteBC(BC bc)
{
    if (bc.regles == NULL)
        return NULL;
    return &bc.regles->value;
}
