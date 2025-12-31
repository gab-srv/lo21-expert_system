#include "../include/bc.h"
#include "../include/regle.h"
#include <stdlib.h>

BC creerBC(){
    BC B = { creerListe() };
    return B;
}

bool bcVide(BC bc)
{
    return bc == NULL;
}
void ajouterQueueR(ListeR *l, Regle r){
    listElementR* newElement = malloc(sizeof(listElementR));
    newElement->value = r;
    newElement->next = NULL;

    if (*l == NULL){
        *l = newElement;
    } else {
        listElementR* current = *l;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newElement;
    }
}

Regle teteR(ListeR *l){
    if (*l != NULL)
        return (*l)->value;
    else {
        Regle emptyRule = creerRegle();
        return emptyRule;
    }
}

void ajouterRegle(BC *bc, Regle r){
    ajouterQueueR(&bc->regles, r);
}

Regle teteBC(BC bc){
    return teteR(bc.regles);
}
