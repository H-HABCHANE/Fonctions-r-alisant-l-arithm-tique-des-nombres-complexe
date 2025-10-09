#include <stdio.h>

int pgcd(int a, int b);


int pgcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int x, y, resultat;

    printf("Entrez deux entiers : ");
    scanf("%d %d", &x, &y);

    resultat = pgcd(x, y);

    printf("Le PGCD de %d et %d est : %d\n", x, y, resultat);
