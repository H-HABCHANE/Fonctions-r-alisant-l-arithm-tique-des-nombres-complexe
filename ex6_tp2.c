#include <stdio.h>
#include <stdlib.h> // pour atoi()

// Prototype de la fonction
int pgcd(int a, int b);

// Programme principal avec arguments de la ligne de commande
int main(int argc, char *argv[]) {
    int a, b, resultat;

    // Vérification du nombre d’arguments
    if (argc != 3) {
        printf("Utilisation : %s nombre1 nombre2\n", argv[0]);
        printf("Exemple : %s 125 7\n", argv[0]);
        return 1; // sortie avec erreur
    }

    // Conversion des arguments en entiers
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    // Calcul du PGCD
    resultat = pgcd(a, b);

    // Affichage du résultat
    printf("Le PGCD de %d et %d est : %d\n", a, b, resultat);

    return 0;
}

// Définition de la fonction pgcd (algorithme d’Euclide)
int pgcd(int a, int b) {
    int reste;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        reste = a % b;
        a = b;
        b = reste;
    }

    return a;
}
