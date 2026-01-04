#include "../include/regle.h"
#include "../include/bc.h"
#include "../include/moteur.h"
#include "../include/liste.h"

//Fonctions du menu

// Fonction pour afficher le menu
void afficherMenu() {
    printf("\n=== Menu du Système Expert ===\n");
    printf("1. Ajouter un fait à la base de faits\n");
    printf("2. Ajouter une règle à la base de connaissances\n");
    printf("3. Afficher la base de faits\n");
    printf("4. Afficher la base de connaissances\n");
    printf("5. Exécuter le moteur d'inférence\n");
    printf("6. Quitter\n");
    printf("Choisissez une option : ");
}

// Fonction pour ajouter un fait
Liste ajouterFait(Liste bf) {
    char fait[100];
    printf("Entrez le fait à ajouter : ");
    scanf("%99s", fait);
    bf = ajouterQueue(bf, strdup(fait));
    printf("Fait ajouté : %s\n", fait);
    return bf;
}

// Fonction pour ajouter une règle
BC ajouterRegleMenu(BC bc) {
    Regle r = creerRegle();
    char premisse[100];
    char conclusion[100];
    int nbPremisses;

    printf("Combien de prémisses pour cette règle ? ");
    scanf("%d", &nbPremisses);

    for (int i = 0; i < nbPremisses; i++) {
        printf("Entrez la prémisse %d : ", i + 1);
        scanf("%99s", premisse);
        r = ajouterPremisse(r, strdup(premisse));
    }

    printf("Entrez la conclusion de la règle : ");
    scanf("%99s", conclusion);
    r = definirConclusion(r, strdup(conclusion));

    bc = ajouterRegle(bc, r);
    printf("Règle ajoutée.\n");
    return bc;
}

// Fonction pour afficher la base de faits
void afficherBaseFaits(Liste bf) {
    printf("\n=== Base de faits ===\n");
    afficherListe(bf);
}

// Fonction pour afficher la base de connaissances
void afficherBaseConnaissances(BC bc) {
    printf("\n=== Base de connaissances ===\n");
    ListeR regles = bc.regles;
    int i = 1;
    while (regles != NULL) {
        Regle r = regles->value;
        printf("Règle %d :\n", i);
        printf("  Prémisses : ");
        afficherListe(r.premisses);
        printf("  Conclusion : %s\n", r.conclusion);
        regles = regles->next;
        i++;
    }
}


int main() {
    

    //Cas de base pour test
    /*Liste bf = creerListe();
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
    afficherListe(deduites);*/


    Liste bf = creerListe();
    BC bc = creerBC();
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                bf = ajouterFait(bf);
                break;
            case 2:
                bc = ajouterRegleMenu(bc);
                break;
            case 3:
                afficherBaseFaits(bf);
                break;
            case 4:
                afficherBaseConnaissances(bc);
                break;
            case 5: {
                Liste deduites = moteurInference(bc, bf);
                printf("\n=== Faits déduits ===\n");
                afficherListe(deduites);
                break;
            }
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

    detruireListe(bf);
    // TODO: Ajouter la libération de la mémoire pour la base de connaissances

    return 0;
}