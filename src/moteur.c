void moteurInference(BC* bc, Liste* bf)
{
    while (!bcVide(bc)) {

        Regle* r = teteBC(bc);
        Regle* r_temp = creerRegle();
        definirConclusion(r_temp, conclusion(r));
        Regle* r_read = r;
        while (!estVidePremisse(r_read)) {
            ajouterPremisse(r_temp, tetePremisse(r_read));
            r_read = restePremisse(r_read);
        }
        while (!estVidePremisse(r_temp)) {

            Proposition p = tetePremisse(r_temp);

            if (appartientBF(*bf, p)) {
                supprimerPropPremisse(r_temp, p);
            } else {
                break;
            }
        }
        if (estVidePremisse(r_temp)) {
            Proposition c = conclusion(r_temp);
            if (!appartientBF(*bf, c)) {
                ajouterQueue(bf, c);
            }
            printf("Conclusion: %s\n", c);
            detruireRegle(r_temp);
            return ;
        }

        detruireRegle(r_temp);
        bc = resteBC(bc);
    }
    printf("Aucune conclusion a votre probleme\n");
}
