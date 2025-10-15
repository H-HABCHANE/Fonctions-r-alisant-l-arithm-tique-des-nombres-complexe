#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    // Lecture du nombre de lignes
    printf("Entrez le nombre de lignes n : ");
    scanf("%d", &n);
    
    // Vérification que n est positif
    if (n <= 0) {
        printf("Erreur : n doit être un entier positif.\n");
        return 1;
    }
    
    // Allocation dynamique du tableau 2D
    int **triangle = (int **)malloc(n * sizeof(int *));
    if (triangle == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
        if (triangle[i] == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            // Libération de la mémoire déjà allouée
            for (int j = 0; j < i; j++) {
                free(triangle[j]);
            }
            free(triangle);
            return 1;
        }
    }
    
    // Remplissage du triangle de Pascal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // Les bords valent toujours 1
                triangle[i][j] = 1;
            } else {
                // Coefficient = somme des deux coefficients au-dessus
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
    
    // Affichage du triangle de Pascal
    printf("\nTriangle de Pascal pour n = %d :\n\n", n);
    
    // Calcul de l'espacement pour un affichage centré
    int espace = n - 1;
    
    for (int i = 0; i < n; i++) {
        // Espaces pour centrer
        for (int s = 0; s < espace; s++) {
            printf("   ");
        }
        espace--;
        
        // Affichage des coefficients
        for (int j = 0; j <= i; j++) {
            printf("%6d", triangle[i][j]);
        }
        printf("\n");
    }
    
    // Affichage sous forme de tableau (facultatif)
    printf("\nAffichage sous forme de tableau :\n");
    for (int i = 0; i < n; i++) {
        printf("Ligne %2d : ", i);
        for (int j = 0; j <= i; j++) {
            printf("%4d ", triangle[i][j]);
        }
        printf("\n");
    }
    
    // Affichage de la formule mathématique
    printf("\nFormules des coefficients binomiaux :\n");
    for (int i = 0; i < n; i++) {
        printf("C(%d,k) : ", i);
        for (int j = 0; j <= i; j++) {
            printf("C(%d,%d)=%d", i, j, triangle[i][j]);
            if (j < i) printf(", ");
        }
        printf("\n");
    }
    
    // Libération de la mémoire
    for (int i = 0; i < n; i++) {
        free(triangle[i]);
    }
    free(triangle);
    
    return 0;
}