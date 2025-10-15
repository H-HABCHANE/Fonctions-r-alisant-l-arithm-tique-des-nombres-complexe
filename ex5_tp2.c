#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction qui génère un nombre aléatoire entre 0 et 100
int genererNombreMystere() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    return rand() % 101; // nombre entre 0 et 100 inclus
}

// Fonction principale du jeu
void jouer() {
    int nombreMystere = genererNombreMystere();
    int proposition = -1;
    int compteur = 0;

    printf("=== Jeu du Nombre Mystere ===\n");
    printf("Devinez le nombre entre 0 et 100 !\n\n");

    // Boucle jusqu’à ce que le joueur trouve le bon nombre
    while (proposition != nombreMystere) {
        printf("Votre proposition : ");
        scanf("%d", &proposition);
        compteur++;

        if (proposition < nombreMystere) {
            printf("C'est plus !\n");
        } else if (proposition > nombreMystere) {
            printf("C'est moins !\n");
        } else {
            printf("Bravo ! Vous avez trouve le nombre mystere %d en %d essais.\n",
                   nombreMystere, compteur);
        }
    }
}

// Programme principal
int main() {
    jouer();
    return 0;
}
