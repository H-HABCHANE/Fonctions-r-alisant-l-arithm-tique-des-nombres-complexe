#include <stdio.h>

int main(void) {
    /* entêtes de colonnes */
    printf("\t");
    for (int c = 0; c < 16; ++c) printf("0x%X\t", c);
    printf("\n");

    /* lignes */
    for (int r = 0; r < 16; ++r) {
        printf("0x%X\t", r);               /* index de la ligne */
        for (int c = 0; c < 16; ++c) {
            printf("0x%02X\t", r * c);     /* produit en hex (2 chiffres) */
        }
        printf("\n");
    }
    return 0;
}
