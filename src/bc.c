#include "../include/bc.h"
#include "../include/liste.h"
#include "../include/regle.h"

BC creerBC(){
    BC B = { creerListe() };
    return B;
}

void ajouterRegle(BC *bc, Regle r){
    ajouterQueueR(&bc->regles, r);
}

Regle teteBC(BC bc){
    return teteR(bc.regles);
}