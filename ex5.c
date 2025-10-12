#include <stdio.h>

int main(void) {
    int a, b, c, d;  // a + ib et c + id
    int re, im;      // parties réelle et imaginaire du produit

    // Lecture du premier nombre complexe
    printf("Entrez la partie réelle et imaginaire du premier nombre : ");
    scanf("%d %d", &a, &b);

    // Lecture du deuxième nombre complexe
    printf("Entrez la partie réelle et imaginaire du deuxième nombre : ");
    scanf("%d %d", &c, &d);

    // Calcul du produit :
    // (a + ib) * (c + id) = (a*c - b*d) + i(a*d + b*c)
    re = a * c - b * d;
    im = a * d + b * c;

    // Affichage du résultat
    printf("Le produit est : %d + i%d\n", re, im);

    return 0;
}
