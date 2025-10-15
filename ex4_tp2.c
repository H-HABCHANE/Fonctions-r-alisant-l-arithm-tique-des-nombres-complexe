#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Fonction pour résoudre une équation du second degré
void resoudreEquationSecondDegre(double a, double b, double c) {
    printf("Equation: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);
    
    // Calcul du discriminant
    double delta = b * b - 4 * a * c;
    printf("Discriminant (delta) = %.2f\n", delta);
    
    if (delta > 0) {
        // Deux racines réelles distinctes
        double x1 = (-b - sqrt(delta)) / (2 * a);
        double x2 = (-b + sqrt(delta)) / (2 * a);
        printf("Deux racines reelles distinctes:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
        
        // Vérification
        printf("\nVerification:\n");
        printf("a*x1² + b*x1 + c = %.2f\n", a*x1*x1 + b*x1 + c);
        printf("a*x2² + b*x2 + c = %.2f\n", a*x2*x2 + b*x2 + c);
    }
    else if (delta == 0) {
        // Une racine réelle double
        double x = -b / (2 * a);
        printf("Une racine reelle double:\n");
        printf("x = %.2f\n", x);
        
        // Vérification
        printf("\nVerification:\n");
        printf("a*x² + b*x + c = %.2f\n", a*x*x + b*x + c);
    }
    else {
        // Pas de racines réelles
        printf("Pas de racines reelles (delta < 0)\n");
        double partieReelle = -b / (2 * a);
        double partieImaginaire = sqrt(-delta) / (2 * a);
        printf("Racines complexes:\n");
        printf("x1 = %.2f - %.2fi\n", partieReelle, partieImaginaire);
        printf("x2 = %.2f + %.2fi\n", partieReelle, partieImaginaire);
    }
    printf("----------------------------------------\n");
}

// Fonction principale
int main() {
    int min, max;
    int nombreEquations;
    
    printf("=== RESOLUTION D'EQUATIONS DU SECOND DEGRE ===\n");
    printf("Entrez la valeur minimale pour les coefficients: ");
    scanf("%d", &min);
    printf("Entrez la valeur maximale pour les coefficients: ");
    scanf("%d", &max);
    printf("Combien d'equations voulez-vous generer ? ");
    scanf("%d", &nombreEquations);
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("\n=== GENERATION ET RESOLUTION ===\n");
    
    for (int i = 0; i < nombreEquations; i++) {
        // Génération aléatoire des coefficients dans l'intervalle [min, max]
        double a = min + (rand() / (double)RAND_MAX) * (max - min);
        double b = min + (rand() / (double)RAND_MAX) * (max - min);
        double c = min + (rand() / (double)RAND_MAX) * (max - min);
        
        // Éviter a = 0 (ce ne serait plus une équation du second degré)
        while (a == 0) {
            a = min + (rand() / (double)RAND_MAX) * (max - min);
        }
        
        printf("\nEquation %d:\n", i + 1);
        resoudreEquationSecondDegre(a, b, c);
    }
    
    return 0;
}

// À quoi sert srand(time(NULL)) ?
// rand(time(NULL)) initialise le générateur de nombres aléatoires avec une graine (seed) basée sur l'heure actuelle.

// rand() seul : génère toujours la même séquence de nombres à chaque exécution

// srand(time(NULL)) : utilise l'heure actuelle comme point de départ, donc la séquence change à chaque exécution