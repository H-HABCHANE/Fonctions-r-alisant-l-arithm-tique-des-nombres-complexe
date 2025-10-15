#include <stdio.h>
#include <stdlib.h>

// Déclarations des fonctions
int** allouerMatrice(int lignes, int colonnes);
void libererMatrice(int **matrice, int lignes);
void afficherMatrice(int **matrice, int lignes, int colonnes);
void initialiserMatrice(int **matrice, int lignes, int colonnes);

// Fonction pour multiplier deux matrices de dimensions (n × p) et (p × m)
int** multiplierMatrices(int **A, int **B, int n, int p, int m) {
    // Vérification de la compatibilité des dimensions
    if (A == NULL || B == NULL) {
        printf("Erreur: Matrices non allouées\n");
        return NULL;
    }
    
    // Allocation de la matrice résultat (n × m)
    int **C = allouerMatrice(n, m);
    if (C == NULL) {
        printf("Erreur d'allocation de la matrice résultat\n");
        return NULL;
    }
    
    // Multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

// Fonction pour allouer une matrice
int** allouerMatrice(int lignes, int colonnes) {
    int **matrice = (int**)malloc(lignes * sizeof(int*));
    if (matrice == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (int*)malloc(colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Erreur d'allocation mémoire pour la ligne %d\n", i);
            // Libérer la mémoire déjà allouée
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return NULL;
        }
    }
    return matrice;
}

// Fonction pour libérer une matrice
void libererMatrice(int **matrice, int lignes) {
    if (matrice != NULL) {
        for (int i = 0; i < lignes; i++) {
            free(matrice[i]);
        }
        free(matrice);
    }
}

// Fonction pour initialiser une matrice avec des valeurs
void initialiserMatrice(int **matrice, int lignes, int colonnes) {
    int valeur = 1;
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = valeur++;
        }
    }
}

// Fonction pour afficher une matrice
void afficherMatrice(int **matrice, int lignes, int colonnes) {
    if (matrice == NULL) {
        printf("Matrice non allouée\n");
        return;
    }
    
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Version pour matrices carrées (conservée pour compatibilité)
void multiplierMatricesCarrees(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    printf("=== Test avec matrices non carrées ===\n");
    
    int n = 4;  // lignes de A, lignes de C
    int p = 3;  // colonnes de A, lignes de B (p ≤ n)
    int m = 4;  // colonnes de B, colonnes de C
    
    printf("Multiplication de matrices (%d x %d) * (%d x %d)\n", n, p, p, m);
    
    // Allocation des matrices
    int **A = allouerMatrice(n, p);
    int **B = allouerMatrice(p, m);
    
    if (A == NULL || B == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }
    
    // Initialisation des matrices
    initialiserMatrice(A, n, p);
    initialiserMatrice(B, p, m);
    
    // Multiplication
    int **C = multiplierMatrices(A, B, n, p, m);
    
    if (C == NULL) {
        printf("Erreur lors de la multiplication\n");
        libererMatrice(A, n);
        libererMatrice(B, p);
        return 1;
    }
    
    // Affichage des résultats
    printf("\nMatrice A (%d x %d):\n", n, p);
    afficherMatrice(A, n, p);
    
    printf("\nMatrice B (%d x %d):\n", p, m);
    afficherMatrice(B, p, m);
    
    printf("\nMatrice C = A * B (%d x %d):\n", n, m);
    afficherMatrice(C, n, m);
    
    // Cas spécial mentionné dans l'énoncé : (n × p) ∗ (p × n) avec p ≤ n
    printf("\n=== Cas spécial: (n × p) ∗ (p × n) avec p ≤ n ===\n");
    
    // Réallocation pour le cas spécial
    libererMatrice(B, p);
    libererMatrice(C, n);
    
    B = allouerMatrice(p, n);  // (p × n)
    if (B == NULL) {
        printf("Erreur d'allocation de B\n");
        libererMatrice(A, n);
        return 1;
    }
    
    initialiserMatrice(B, p, n);
    
    C = multiplierMatrices(A, B, n, p, n);
    if (C == NULL) {
        printf("Erreur lors de la multiplication\n");
        libererMatrice(A, n);
        libererMatrice(B, p);
        return 1;
    }
    
    printf("\nMatrice A (%d x %d):\n", n, p);
    afficherMatrice(A, n, p);
    
    printf("\nMatrice B (%d x %d):\n", p, n);
    afficherMatrice(B, p, n);
    
    printf("\nMatrice C = A * B (%d x %d):\n", n, n);
    afficherMatrice(C, n, n);
    
    // Libération mémoire
    libererMatrice(A, n);
    libererMatrice(B, p);
    libererMatrice(C, n);
    
    return 0;
}