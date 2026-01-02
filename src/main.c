#include "../include/regle.h"
#include "../include/bc.h"
#include "../include/moteur.h"
#include "../include/liste.h"

int main() {
    
    Liste bf = creerListe();
    bf = ajouterQueue(bf, "fait1");
    bf = ajouterQueue(bf, "fait2");

    Regle r1 = creerRegle();
    r1 = ajouterPremisse(r1, "fait1");
    r1 = definirConclusion(r1, "conclusion1");

    Regle r2 = creerRegle();
    r2 = ajouterPremisse(r2, "fait2");
    r2 = definirConclusion(r2, "conclusion2");

    Regle r3 = creerRegle();
    r3 = ajouterPremisse(r3, "fait1");
    r3 = ajouterPremisse(r3, "fait2");
    r3 = definirConclusion(r3, "conclusion3");

    Regle r4 = creerRegle();
    r4 = ajouterPremisse(r4, "fait1");
    r4 = ajouterPremisse(r4, "fait3");
    r4 = definirConclusion(r4, "conclusion4");

    Regle r5 = creerRegle();
    r5 = ajouterPremisse(r5, "conclusion2");
    r5 = ajouterPremisse(r5, "conclusion3");
    r5 = definirConclusion(r5, "conclusion5");

    BC bc = creerBC();
    bc = ajouterRegle(bc, r1);
    bc = ajouterRegle(bc, r2);
    bc = ajouterRegle(bc, r3);
    bc = ajouterRegle(bc, r4);
    bc = ajouterRegle(bc, r5);

    Liste deduites = moteurInference(bc, bf);
    printf("Faits déduits :\n");
    afficherListe(deduites);

    return 0;
}