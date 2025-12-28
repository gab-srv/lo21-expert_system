#ifndef LISTE_H
#define LISTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char* Element;

typedef struct Cellule {
    Element valeur;
    struct Cellule* suivant;
} Cellule;

typedef Cellule* Liste;
Liste creerListe();
bool appartient(Liste l, char* c);
void afficherListe(Liste l);
Liste ajouterQueue(Liste l, Element v);
Liste supprimerElement(Liste l, Element v);
void detruireListe(Liste l);

#endif
