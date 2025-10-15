#include <stdio.h>
#include <stdlib.h>

// Fonction pour multiplier deux matrices carrées d'ordre n
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

// Fonction pour afficher une matrice
void afficherMatrice(int **matrice, int lignes, int colonnes) {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour allouer une matrice
int** allouerMatrice(int lignes, int colonnes) {
    int **matrice = (int**)malloc(lignes * sizeof(int*));
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (int*)malloc(colonnes * sizeof(int));
    }
    return matrice;
}

// Fonction pour libérer une matrice
void libererMatrice(int **matrice, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

int main() {
    int n = 3;
    
    // Allocation des matrices
    int **A = allouerMatrice(n, n);
    int **B = allouerMatrice(n, n);
    int **C = allouerMatrice(n, n);
    
    // Initialisation des matrices A et B
    int valeur = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = valeur++;
            B[i][j] = valeur % 5 + 1;
        }
    }
    
    // Multiplication
    multiplierMatricesCarrees(A, B, C, n);
    
    // Affichage
    printf("Matrice A:\n");
    afficherMatrice(A, n, n);
    
    printf("\nMatrice B:\n");
    afficherMatrice(B, n, n);
    
    printf("\nMatrice C = A * B:\n");
    afficherMatrice(C, n, n);
    
    // Libération mémoire
    libererMatrice(A, n);
    libererMatrice(B, n);
    libererMatrice(C, n);
    
    return 0;
}